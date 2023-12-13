#include "myshell.h"
/**
 * _getenv - Retrieve environment var without using the "getenv" function.
 * @name: The name of the environment variable.
 * @header: A pointer to the lists of environment variables.
 *
 * Return: A pointer to the string containing specified environment variable
 * NULL if it is not found.
 */
string _getenv(string name, lists_t **header)
{
	lists_t *temp;
	int length, index;

	temp = *header;
	length = lists_len(temp);
	if (!header || !temp || !name)
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
 * @header: A pointer to the lists of environment variables.
 *
 * Return: A pointer to the first of the modified environment lists or NULL
 * if operation failed.
 */
int _setenv(string name, string value, lists_t **header)
{
	string ptr;
	string new_ptr;
	lists_t *ret_ptr;

	new_ptr = _var_string(name, value);
	if (new_ptr == NULL)
	{
		perror("Insuffient memory");
		return (1);
	}
	/* use _getenv(name) to get a pointer to string of variable */
	ptr = _getenv(name, header);
	/* if variable not found add it */
	if (ptr == NULL)
	{
		ret_ptr = add_node_end(header, new_ptr);
		if (ret_ptr == NULL)
		{
			free(new_ptr);
			perror("Insufficent memory");
			return (1);
		}
		free(new_ptr);
		return (0);
	}

	ret_ptr = get_node(header, ptr);
	free(ret_ptr->str);
	ret_ptr->str = new_ptr;
	return (0);
}
/**
 * _unsetenv - Delete a variable from the environment. If 'name' does not exist
 *             the environment, the function succeeds, and the
 *	       environment remains unchanged.
 * @name: The name of the environment variable to be removed.
 * @header: A pointer to the lists of environment variables.
 *
 * Return: Always 0 on success, or 1 on error.
 */
int _unsetenv(string name, lists_t **header)
{
	string equal;
	string str_ptr;
	int deleted;
	lists_t *temp;

	temp = *header;
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
 * _delete - Delete a node with a specified string in a lists_t.
 * @first: A pointer to the first pointer of the linked lists.
 * @str: A pointer to the string of the node to be deleted.
 *
 * Return: 0 on success, or 1 on failure.
 */
int _delete(lists_t **first, string str)
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
 * _var_string - Create a string in the format "name=value".
 * @name: The name to be included in the string.
 * @value: The value to be included in the string.
 *
 * Return: A new string in the format "name=value", or NULL on error.
 */
string _var_string(string name, string value)
{
	string new_ptr;


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
