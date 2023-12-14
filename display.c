#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * print - uses write to print to standard output
 * @str: strings to be printed
 */
void print(strings str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}
/**
 * arr_print - Print an array of strings.
 * @arr: The array to be printed.
 */
void arr_print(strings *arr)
{
	int index;

	if (!arr || !(*arr))
	{
		perror("Something went wrong");
		return;
	}
	for (index = 0; arr[index] != NULL; ++index)
	{
		print(arr[index]);
		_putchar('\n');
	}
}
/**
 * print_lists - Print all the elements of a lists_t linked lists.
 * @first: A pointer to the linked lists.
 *
 * Return: The number of elements in the linked lists.
 */
size_t print_lists(lists_t *first)
{
	size_t length;

	length = 0;
	if (first == NULL)
		return (0);
	while (first != NULL)
	{
		print(first->str);
		_putchar('\n');
		first = first->next;
		length++;
	}
	return (length);
}
