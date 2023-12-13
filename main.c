#include "myshell.h"
/**
 * main - Entry Point to Shell
 * Return: Always 0 on success
 */
int main(void)
{
	string buff;
	string line;
	list_t *header;
	int val;

	line = NULL;
	buff = malloc(sizeof(char) * BUFFSIZE);
	if (buff == NULL)
		return (1);
	header = arr_to_list(environ);
	val = cmd_loop(buff, line, &header);
	free_list(header);
	free(buff);
	return (val);
}
/**
 * sign_handle - Signal handler for handling a specific signal.
 *
 * This function is a signal handler designed to handle the specified signal.
 * prints the "<) " string to the standard output when invoked.
 *
 * @signal: The signal number to be handled (unused in this implementation).
 */
void sign_handle(int signal)
{
	char *str = "\n<) ";
	(void)signal;

	myprint(str);
}
