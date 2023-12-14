#include "shell.h"
/**
 * _getenv - Retrieve environment var without using the "getenv" function.
 * @name: The name of the environment variable.
 * @firster: A pointer to the lists of environment variables.
 *
 * Return: A pointer to the strings containing specified environment variable
 * NULL if it is not found.
 */
strings _getenv(strings name, lists_t **firster)
{
	lists_t *temp;
	int length, index;

	temp = *firster;
	length = lists_len(temp);
	if (!firster || !temp || !name)
		return (NULL);
	index = 0;
	while (index < length)
	{
		if (_strncmp(temp->str, name, _strlen(name)) == 0)
			return (temp->str);
		index++;
		temp = temp->next;
	}
	return (NULL);
}
/**
 * _setenv - Add or modify an environment variable with a specified value.
 * @name: The name of the variable to be added or modified.
 * @value: The value to be assigned to the variable.
 * @firster: A pointer to the lists of environment variables.
 *
 * Return: A pointer to the first of the modified environment lists or NULL
 * if operation failed.
 */
int _setenv(strings name, strings value, lists_t **firster)
{
	strings ptr;
	strings new_ptr;
	lists_t *ret_ptr;

	new_ptr = _var_string(name, value);
	if (new_ptr == NULL)
	{
		perror("Insuffient memory");
		return (1);
	}
	/* use _getenv(name) to get a pointer to strings of variable */
	ptr = _getenv(name, firster);
	/* if variable not found add it */
	if (ptr == NULL)
	{
		ret_ptr = add_node_end(firster, new_ptr);
		if (ret_ptr == NULL)
		{
			free(new_ptr);
			perror("Insufficent memory");
			return (1);
		}
		free(new_ptr);
		return (0);
	}

	ret_ptr = get_node(firster, ptr);
	free(ret_ptr->str);
	ret_ptr->str = new_ptr;
	return (0);
}
/**
 * _unsetenv - Delete a variable from the environment. If 'name' does not exist
 *             the environment, the function succeeds, and the
 *	       environment remains unchanged.
 * @name: The name of the environment variable to be removed.
 * @firster: A pointer to the lists of environment variables.
 *
 * Return: Always 0 on success, or 1 on error.
 */
int _unsetenv(strings name, lists_t **firster)
{
	strings equal;
	strings str_ptr;
	int deleted;
	lists_t *temp;

	temp = *firster;
	equal = _strchr(name, '=');
	if ((name == NULL) || ((name[0] == '\0') != 0) || (equal != NULL))
	{
		perror("Invalid argument");
		return (1);
	}
	str_ptr = _getenv(name, &temp);
	if (str_ptr == NULL)
	{
		perror("unsetenv: no variable\n");
		return (1);
	}
	deleted = _delete(&temp, str_ptr);
	return (deleted);
}
/**
 * _delete - Delete a node with a specified strings in a lists_t.
 * @first: A pointer to the first pointer of the linked lists.
 * @str: A pointer to the strings of the node to be deleted.
 *
 * Return: 0 on success, or 1 on failure.
 */
int _delete(lists_t **first, strings str)
{
	lists_t *temp;
	lists_t *removeNode;

	temp = *first;
	if (temp == NULL || *first == NULL)
	{
		return (1);
	}


	if (_strcmp(temp->str, str) == 0)
	{
		*first = temp->next;
		free(temp->str);
		free(temp);
		return (0);
	}

	while (temp->next != NULL)
	{
		if (_strcmp(temp->next->str, str) == 0)
		{
			removeNode = temp->next;
			temp->next = removeNode->next;
			free(removeNode->str);
			free(removeNode);
			return (0);
		}
		temp = temp->next;
	}

	return (1);
}
/**
 * _var_string - Create a strings in the format "name=value".
 * @name: The name to be included in the strings.
 * @value: The value to be included in the strings.
 *
 * Return: A new strings in the format "name=value", or NULL on error.
 */
strings _var_string(strings name, strings value)
{
	strings new_ptr;


	if (((name[0] == '\0') != 0) || (_strchr(name, '=') != NULL))
	{
		perror("Invalid argument");
		return (NULL);
	}

	if ((name == NULL) || (value == NULL))
	{
		perror("Insufficent memory");
		return (NULL);
	}

	new_ptr = malloc(_strlen(name) + _strlen(value) + 2);
	if (new_ptr == NULL)
	{
		perror("Insufficent memory");
		return (NULL);
	}

	new_ptr = _strcpy(new_ptr, name);
	new_ptr = _strcat(new_ptr, "=");
	new_ptr = _strcat(new_ptr, value);
	return (new_ptr);
}
