#include "shell.h"
/**
 * path_dir - Create an array of pointers for all directories in the PATH.
 * @firster: Pointer to the environment lists.
 *
 * Return: An array of pointers.
 */
strings *path_dir(lists_t **firster);
strings *path_dir(lists_t **firster)
{
	strings ptr;
	strings name = "PATH";
	strings path_str;
	char delim = ':';
	strings *dirs;
	lists_t *temp;

	temp = *firster;

	ptr = _getenv(name, &temp);
	path_str = _strdup(ptr + 5);
	dirs = _strtok(path_str, delim);
	if (dirs == NULL)
	{
		free(path_str);
		return (NULL);
	}
	free(path_str);
	return (dirs);
}
/**
 * command_path - Check if a command is in the PATH and return its full path.
 * @str: The command to check.
 * @firster: Pointer to the environment lists.
 *
 * Return: The full path of the command if found, or NULL if not found.
 */
strings command_path(strings str, lists_t **firster)
{
	strings *path_dirs;
	strings command;
	int index, j, commandl, strl;
	lists_t *temp;

	for (j = 0; str[j] != '\0'; j++)
	{
		if (str[j] == '/' && str[j + 1] != '\0' && str[j + 1] != '/' &&
		    access(str, F_OK | X_OK) == 0)
			return (str);
	}
	if ((str[0] == '/' || str[0] == '.') && str[j] == '\0')
	{
		print(str);
		print(": not found\n");
		return (NULL);
	}
	temp = *firster;
	path_dirs = path_dir(&temp);
	if (path_dirs == NULL)
	{
		perror("Out of memory");
		return (NULL);
	}
	for (index = 0; path_dirs[index] != NULL; index++)
	{
		command = _strdup(path_dirs[index]);
		commandl = _strlen(command);
		strl = _strlen(str);
		command = _realloc(command, commandl, commandl + strl + 2);
		command = _strcpy(command, path_dirs[index]);
		command = _strcat(command, "/");
		command = _strcat(command, str);
		if (access(command, F_OK) == 0)
		{
			free_arr(path_dirs);
			return (command);
		}
	}
	free_arr(path_dirs);
	return (str);
}
/**
 * run_command - Execute the command entered in the shell.
 * @token: Tokenized input line.
 * @firster: Pointer to the environment lists.
 *
 * Return: 0 on success, 1 on error.
 */
int run_command(strings *token, lists_t **firster)
{
	pid_t child;
	int status;
	strings *env_arr;
	strings command;
	lists_t *temp;

	temp = *firster;
	env_arr = lists_to_arr(&temp);
	if (env_arr == NULL)
	{
		perror("Insufficient Memory");
		return (1);
	}
	child = fork();
	if (child == -1)
	{
		perror("run_command: child pid is -1");
		free(env_arr);
		return (1);
	}
	if (child == 0)
	{
		command = command_path(token[0], &temp);
		if (command == NULL)
			exit(1);
		if (execve(command, token, env_arr) == -1)
		{
			perror("hsh");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
	free(env_arr);
	return (0);
}
