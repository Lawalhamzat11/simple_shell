#include "shell.h"
/**
 * lists_len - returns the number of elements in a linked lists_t lists
 * @first: linked lists
 * Return: number of elements
 */
size_t lists_len(lists_t *first)
{
	size_t length;

	length = 0;
	while (first != NULL)
	{
		length++;
		first = first->next;
	}
	return (length);
}
/**
 * addnode_begin - adds a new node at the beginning of a lists_t lists
 * @first: first node in the lists
 * @str: second node in the lists
 * Return: the address of the new element, or NULL if it failed
 */
lists_t *addnode_begin(lists_t **first, strings str)
{
	lists_t *new;

	new = malloc(sizeof(lists_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	if (new->str == NULL)
		return (NULL);
	new->length = _strlen(str);
	new->next = *first;
	*first = new;
	return (*first);
}
/**
 * add_node_end - check the code for Holberton School students.
 * @first: pointer to first node in linked lists
 * @str: data to be copied to strings field of the node
 * Return: the address of the new element, or NULL if it failed
 */
lists_t *add_node_end(lists_t **first, strings str)
{
	lists_t *new;
	lists_t *tail;

	new = malloc(sizeof(lists_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	if (new->str == NULL)
		return (NULL);
	new->length = _strlen(str);
	new->next = NULL;
	if (*first == NULL)
	{
		*first = new;
		return (new);
	}
		tail = *first;
		while (1)
		{
			if (tail->next == NULL)
			{
				tail->next = new;
				break;
			}
			tail = tail->next;
		}
	return (new);
}
/**
 * free_lists - frees a lists_t lists
 * @first: linked lists to free
 * Return: none
 */
void free_lists(lists_t *first)
{
	lists_t *temp;

	while (1)
	{
		if (first == NULL)
			break;
		temp = first;
		first = temp->next;
		free(temp->str);
		free(temp);
	}
}
/**
 * get_node - returns the node with strings str
 * @first: pointer to first node
 * @str: strings to search for
 * Return: n-th node, if the node does not exist, return NULL
 */
lists_t *get_node(lists_t **first, strings str)
{
	lists_t *temp;

	temp = *first;
	while (first && temp)
	{
		if (_strcmp(temp->str, str) == 0 && temp)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
