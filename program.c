#include "myshell.h"
/**
 * cmd_loop - Continuously prompts user for input using 'getline' until
 *                 user enters 'exit' or Ctrl+D (EOF).
 *
 * @buff: Pointer to the buffer for user input.
 * @line: Pointer to the current line of input.
 * @header: Pointer to the environment lists.
 *
 * This function reads user input and stores it in 'buff' until 'exit' Ctrl+D.
 * Return: 0 on success or 1 if 'realloc' fails.
 */
int cmd_loop(string buff, string line, lists_t **header)
{
	int chars_read, oldlen, val = 0;
	string *token;
	lists_t *temp;

	temp = *header;
	for (;;)
	{
		clear_buff(buff);
		chars_read = processline(buff, BUFFSIZE);
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
		line = _memcpy(line, buff, chars_read);
		if (line[0] != '\0')
		{
			token = _strtok(line, ' ');
			val = custom_commands(token, &temp);
			if (exit_shell(token) && val != -1)
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
