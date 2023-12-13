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
 * arr_to_list - Converts an array of pointers to strings into a linked list.
 * @arr: An array of pointers to strings.
 *
 * Return: A pointer to the head of the linked list.
 */
list_t *arr_to_list(string *arr)
{
	list_t *head;
	list_t *new;
	int index;

	head = NULL;
	for (index = 0; arr[index] != NULL; index++)
	{
		new = add_node_end(&head, arr[index]);
		if (new == NULL)
		{
			free_list(head);
			return (NULL);
		}
	}
	return (head);
}
/**
 * list_to_arr - Converts a linked list to an array of pointers.
 * @head: The head pointer of the linked list.
 *
 * Return: A pointer to an array of pointers.
*/
string *list_to_arr(list_t **head)
{
	int length, index;
	list_t *temp;
	string *arr;

	length = list_len(*head);
	arr = malloc(sizeof(string) * (length + 1));
	if (arr == NULL)
		return (NULL);
	temp = *head;
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
