#include "myshell.h"
/**
 * custom_commands - Check if a command is a built-in.
 * @input: Tokenized line from the command line.
 * @header: Pointer to the environment lists.
 *
 * Return: 0 on success(if it's a built-in command)1 on error, -1 the command
 * is not found among built-in commands.
 */
int custom_commands(string *input, lists_t **header)
{
	customs_t builtins[] = {
		{"exit", exit_cmd},
		{"env", print_env},
		{"setenv", _set_env},
		{"unsetenv", un_set_env},
		{NULL, NULL}
	};
	int index, val;
	lists_t *temp;

	temp = *header;
	if (!input)
	{
		perror("custom_commands");
		return (1);
	}
	index = 0;
	while ((builtins + index)->cmd != NULL)
	{
		if (_strcmp(input[0], (builtins + index)->cmd) == 0)
		{
			if (_strcmp(input[0], "exit") == 0)
			{
				val = (builtins + index)->func(input);
				return (val);
			}
			val = (builtins + index)->func(input, &temp);
			return (val);
		}
		index++;
	}
	return (-1);
}

/**
 * exit_cmd - Exit the shell with a given status.
 * @line: Tokenized line from the command line.
 *
 * Return: 0 on success or the specified status, 1 on error.
 */
int exit_cmd(string *line)
{
	int size, status;

	size = arr_size(line);
	if (size > 2)
	{
		print("Invalid syntax: exit status\n");
		return (1);
	}
	if (size == 1)
		return (0);
	if (size == 2)
	{
		status = _atoi(line[1]);
		return (status);
	}
	return (1);
}
/**
 * print_env - Print the current environment variables.
 * @line: Tokenized line from the command line (unused in this function).
 * @header: Pointer to the environment lists.
 *
 * Return: 0 on success, 1 on error.
 */
int print_env(string *line, lists_t **header)
{
	int size;
	lists_t *temp;

	temp = *header;
	size = arr_size(line);
	if (size > 1)
	{
		print("Failed: Command syntax: env\n");
		return (1);
	}
	print_lists(temp);
	return (0);
}
/**
 * _set_env - Initialize a new environment variable or modify an existing one.
 * @line: Tokenized line from the command line.
 * @header: Pointer to the environment lists.
 *
 * Return: 0 on success, 1 on error.
 */
int _set_env(string *line, lists_t **header)
{
	int size;
	int val;
	lists_t *temp;

	temp = *header;
	size = arr_size(line);
	if (size != 3)
	{
		print("Failed: Command syntax: setenv VARIABLE VALUE\n");
		return (1);
	}
	val = _setenv(line[1], line[2], &temp);
	return (val);
}
/**
 * un_set_env - Deletes an environment variable.
 * @line: A tokenized command line input.
 * @header: A pointer to the environment variables lists.
 *
 * Return: 0 on success, 1 on error.
 */
int un_set_env(string *line, lists_t **header)
{
	int size, val;
	lists_t *temp;

	temp = *header;
	size = arr_size(line);
	if (size != 2)
	{
		print("Failed: Command syntax: unsetenv VARIABLE\n");
		return (1);
	}
	val = _unsetenv(line[1], &temp);
	return (val);
}
