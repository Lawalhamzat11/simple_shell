#include "myshell.h"
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
 * myprint - uses write to print to standard output
 * @str: string to be printed
 */
void myprint(string str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}
/**
 * print_arr - Print an array of strings.
 * @arr: The array to be printed.
 */
void print_arr(string *arr)
{
	int index;

	if (!arr || !(*arr))
	{
		perror("Something went wrong");
		return;
	}
	for (index = 0; arr[index] != NULL; ++index)
	{
		myprint(arr[index]);
		_putchar('\n');
	}
}
/**
 * print_list - Print all the elements of a list_t linked list.
 * @head: A pointer to the linked list.
 *
 * Return: The number of elements in the linked list.
 */
size_t print_list(list_t *head)
{
	size_t length;

	length = 0;
	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		myprint(head->str);
		_putchar('\n');
		head = head->next;
		length++;
	}
	return (length);
}
