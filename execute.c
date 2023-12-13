#include "myshell.h"
/**
 * path_dirs - Create an array of pointers for all directories in the PATH.
 * @header: Pointer to the environment list.
 *
 * Return: An array of pointers.
 */
string *path_dirs(list_t **header);
string *path_dirs(list_t **header)
{
	string ptr;
	string name = "PATH";
	string path_str;
	char delim = ':';
	string *dirs;
	list_t *temp;

	temp = *header;

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
 * cmd_path - Check if a command is in the PATH and return its full path.
 * @str: The command to check.
 * @header: Pointer to the environment list.
 *
 * Return: The full path of the command if found, or NULL if not found.
 */
string cmd_path(string str, list_t **header)
{
	string *path_dir;
	string cmd;
	int index, j, cmdl, strl;
	list_t *temp;

	for (j = 0; str[j] != '\0'; j++)
	{
		if (str[j] == '/' && str[j + 1] != '\0' && str[j + 1] != '/' &&
		    access(str, F_OK | X_OK) == 0)
			return (str);
	}
	if ((str[0] == '/' || str[0] == '.') && str[j] == '\0')
	{
		myprint(str);
		myprint(": not found\n");
		return (NULL);
	}
	temp = *header;
	path_dir = path_dirs(&temp);
	if (path_dir == NULL)
	{
		perror("Out of memory");
		return (NULL);
	}
	for (index = 0; path_dir[index] != NULL; index++)
	{
		cmd = _strdup(path_dir[index]);
		cmdl = _strlen(cmd);
		strl = _strlen(str);
		cmd = _realloc(cmd, cmdl, cmdl + strl + 2);
		cmd = _strcpy(cmd, path_dir[index]);
		cmd = _strcat(cmd, "/");
		cmd = _strcat(cmd, str);
		if (access(cmd, F_OK) == 0)
		{
			free_arr(path_dir);
			return (cmd);
		}
	}
	free_arr(path_dir);
	return (str);
}
/**
 * run_command - Execute the command entered in the shell.
 * @token: Tokenized input line.
 * @header: Pointer to the environment list.
 *
 * Return: 0 on success, 1 on error.
 */
int run_command(string *token, list_t **header)
{
	pid_t child;
	int status;
	string *env_arr;
	string cmd;
	list_t *temp;

	temp = *header;
	env_arr = list_to_arr(&temp);
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
		cmd = cmd_path(token[0], &temp);
		if (cmd == NULL)
			exit(1);
		if (execve(cmd, token, env_arr) == -1)
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
