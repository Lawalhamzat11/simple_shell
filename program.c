#include "shell.h"
/**
 * command_loop - Continuously prompts user for input using 'getline' until
 *                 user enters 'exit' or Ctrl+D (EOF).
 *
 * @buffer: Pointer to the buffer for user input.
 * @line: Pointer to the current line of input.
 * @firster: Pointer to the environment lists.
 *
 * This function reads user input and stores it in 'buf until 'exit' Ctrl+D.
 * Return: 0 on success or 1 if 'realloc' fails.
 */
int command_loop(strings buffer, strings line, lists_t **firster)
{
	int chars_read, oldlen, val = 0;
	strings *token;
	lists_t *temp;

	temp = *firster;
	for (;;)
	{
		clear_buff(buffer);
		chars_read = get_line(buffer, BUFFERSIZE);
		if (chars_read == -1)
		{
			break;
		}
		oldlen = (line) ? _strlen(line) : 0;
		line = _realloc(line, oldlen, ++chars_read);
		if (line == NULL)
		{
			perror("Insufficent memory");
			val = 1;
			break;
		}
		line = _memcpy(line, buffer, chars_read);
		if (line[0] != '\0')
		{
			token = _strtok(line, ' ');
			val = custom_commands(token, &temp);
			if (shell_exit(token) && val != -1)
			{
				free_arr(token);
				break;
			}
			if (val == -1)
				val = run_command(token, &temp);
			free_arr(token);
		}
	}
	free(line);
	return (val);
}
