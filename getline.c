#include "myshell.h"
/**
 * processline - Display >) wait for the user to enter a command,and print
 *               it on the next line.
 * @input: Pointer to the buffer to store user input.
 * @size: Size of the buffer.
 *
 * Return: The number of characters read, or -1 if reallocation failed.
 */
int processline(string input, int size)
{
	int index;
	int val;
	struct stat fd;

	if (fstat(STDIN_FILENO, &fd) == -1)
	{
		perror("hsh");
		exit(-1);
	}
	if ((fd.st_mode & S_IFMT) != S_IFIFO)
		myprint("<) ");
	for (index = 0; index < size - 1; index++)
	{
		val = read(STDIN_FILENO, (input + index), 1);
		if (val == 0)
			return (-1);
		if (input[index] == '\n')
			break;
	}
	input[index] = '\0';
	return (index);
}
/**
 * exit_shell - Check if the user input is 'exit' to exit the shell.
 * @token: Pointer to a tokenized input line.
 *
 * Return: 1 if the user wants to exit, 0 otherwise.
 */
int exit_shell(string *token)
{
	int cmp, lend, lline, size;

	size = arr_size(token) < 3;
	cmp = _strncmp(token[0], "exit", _strlen("exit"));
	lend = _strlen("exit");
	lline = _strlen(token[0]);
	if (cmp == 0 && lend == lline && size)
		return (1);
	return (0);
}
/**
 * clear_buff - Set all characters in 'buff' to 0.
 * @buff: Buffer to reset.
 */
void clear_buff(string buff)
{
	int index;

	for (index = 0; index < BUFFSIZE; index++)
		buff[index] = 0;
}
/**
 * _memcpy - Copy a memory area.
 * @dest: Memory area to copy to.
 * @src: Memory area to copy from.
 * @n: Number of bytes to copy.
 *
 * Return: A pointer to 'dest'.
 */
string _memcpy(string dest, string src, int n)
{
	int index;

	for (index = 0; index < n - 1; index++)
	{
		*(dest + index) = *(src + index);
	}
	*(dest + index) = '\0';
	return (dest);
}
/**
 * _realloc - Reallocate a memory block using malloc and free.
 * @ptr: Pointer to the memory previously allocated with a call to malloc.
 * @old: Size, in bytes, of the previously allocated space for ptr.
 * @new: New size, in bytes, of the memory block.
 *
 * Return: A pointer to the new memory location.
 */
void *_realloc(void *ptr, unsigned int old, unsigned int new)
{
	string arr;
	string helper;
	unsigned int index;

	if (old == new)
		return (NULL);
	if (new == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		arr = malloc(new);
		if (arr == NULL)
			return (NULL);
		return (arr);
	}
	arr = malloc(sizeof(char) * new);
	if (arr == NULL)
		return (NULL);
	if (new > old && old != 0)
	{
		helper = ptr;
		for (index = 0; index < old; index++)
			arr[index] = helper[index];
		free(ptr);
	}
	if (new < old)
	{
		helper = ptr;
		for (index = 0; index < new; index++)
			arr[index] = helper[index];
		free(ptr);
	}
	return (arr);
}
