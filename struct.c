#include "myshell.h"
/**
 * list_len - returns the number of elements in a linked list_t list
 * @head: linked List
 * Return: number of elements
 */
size_t list_len(list_t *head)
{
	size_t length;

	length = 0;
	while (head != NULL)
	{
		length++;
		head = head->next;
	}
	return (length);
}
/**
 * _addNode_begin - adds a new node at the beginning of a list_t list
 * @head: first node in the list
 * @str: second node in the list
 * Return: the address of the new element, or NULL if it failed
 */
list_t *_addNode_begin(list_t **head, string str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	if (new->str == NULL)
		return (NULL);
	new->length = _strlen(str);
	new->next = *head;
	*head = new;
	return (*head);
}
/**
 * add_node_end - check the code for Holberton School students.
 * @head: pointer to first node in linked list
 * @str: data to be copied to string field of the node
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, string str)
{
	list_t *new;
	list_t *tail;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	if (new->str == NULL)
		return (NULL);
	new->length = _strlen(str);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
		tail = *head;
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
 * free_list - frees a list_t list
 * @head: linked list to free
 * Return: none
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (1)
	{
		if (head == NULL)
			break;
		temp = head;
		head = temp->next;
		free(temp->str);
		free(temp);
	}
}
/**
 * _get_node - returns the node with string str
 * @head: pointer to first node
 * @str: string to search for
 * Return: n-th node, if the node does not exist, return NULL
 */
list_t *_get_node(list_t **head, string str)
{
	list_t *temp;

	temp = *head;
	while (head && temp)
	{
		if (_strcmp(temp->str, str) == 0 && temp)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
