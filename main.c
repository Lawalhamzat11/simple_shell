#include "shell.h"
/**
 * main - Entry Point to Shell
 * Return: Always 0 on success
 */
int main(void)
{
	strings buffer;
	strings line;
	lists_t *firster;
	int val;

	line = NULL;
	buffer = malloc(sizeof(char) * BUFFERSIZE);
	if (buffer == NULL)
		return (1);
	firster = arr_to_lists(environ);
	val = command_loop(buffer, line, &firster);
	free_lists(firster);
	free(buffer);
	return (val);
}
/**
 * sign_hand - Signal handler for handling a specific signal.
 *
 * This function is a signal handler designed to handle the specified signal.
 * prints the "<) " strings to the standard output when invoked.
 *
 * @signal: The signal number to be handled (unused in this implementation).
 */
void sign_hand(int signal)
{
	char *str = "\n<) ";
	(void)signal;

	print(str);
}
