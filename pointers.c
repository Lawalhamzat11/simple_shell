#include "myshell.h"
/**
 * arr_size - Calculates the size of an array of pointers to strings.
 * @arr: An array of pointers to strings.
 *
 * Return: The size of the array.
 */
int arr_size(string *arr)
{
	int index;

	if (arr == NULL || *arr == NULL)
		return (-1);
	index = 0;
	while (arr[index])
		index++;
	return (index);
}
/**
 * arr_to_lists - Converts an array of pointers to strings into a linked lists.
 * @arr: An array of pointers to strings.
 *
 * Return: A pointer to the first of the linked lists.
 */
lists_t *arr_to_lists(string *arr)
{
	lists_t *first;
	lists_t *new;
	int index;

	first = NULL;
	for (index = 0; arr[index] != NULL; index++)
	{
		new = add_node_end(&first, arr[index]);
		if (new == NULL)
		{
			free_lists(first);
			return (NULL);
		}
	}
	return (first);
}
/**
 * lists_to_arr - Converts a linked lists to an array of pointers.
 * @first: The first pointer of the linked lists.
 *
 * Return: A pointer to an array of pointers.
*/
string *lists_to_arr(lists_t **first)
{
	int length, index;
	lists_t *temp;
	string *arr;

	length = lists_len(*first);
	arr = malloc(sizeof(string) * (length + 1));
	if (arr == NULL)
		return (NULL);
	temp = *first;
	for (index = 0; index < length; index++)
	{
		arr[index] = temp->str;
		temp = temp->next;
	}
	arr[index] = NULL;
	return (arr);
}
/**
 * free_arr - Frees an array of strings.
 * @arr: The array to free.
 *
 * Return: No return value.
 */
void free_arr(string *arr)
{
	int index, size;

	size = arr_size(arr);
	if (*arr == NULL || arr == NULL)
		return;
	for (index = 0; index < size; index++)
	{
		if (arr[index] != NULL)
			free(arr[index]);
	}
	free(arr);
}
