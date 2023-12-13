#include "myshell.h"
/**
 * main - Entry Point to Shell
 * Return: Always 0 on success
 */
int main(void)
{
	string buff;
	string line;
	lists_t *header;
	int val;

	line = NULL;
	buff = malloc(sizeof(char) * BUFFSIZE);
	if (buff == NULL)
		return (1);
	header = arr_to_lists(environ);
	val = cmd_loop(buff, line, &header);
	free_lists(header);
	free(buff);
	return (val);
}
/**
 * sign_hand - Signal handler for handling a specific signal.
 *
 * This function is a signal handler designed to handle the specified signal.
 * prints the "<) " string to the standard output when invoked.
 *
 * @signal: The signal number to be handled (unused in this implementation).
 */
void sign_hand(int signal)
{
	char *str = "\n<) ";
	(void)signal;

	print(str);
}
