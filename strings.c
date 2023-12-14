#include "shell.h"
/**
 * _strlen - returns the lenght of a strings
 * @s: pointer to s
 * Return: 0 on success
 */
int _strlen(strings s)
{
	int count = 0;

	if (*s)
	{
		while (*(s + count) != '\0')
			count++;
	}
	return (count);
}
/**
 * _strncmp - compares two strings for n amount of chars
 * @s1: pointer to strings s1
 * @s2: pointer to strings s2
 * @n: number of chars to compare
 * Return: 0 if identical
 *
 */
int _strncmp(strings s1, strings s2, int n)
{
	int index, dif;

	index = 0;
	while (index < n)
	{
		if (s1[index] == '\0' || s2[index] == '\0')
			return (-1);
		if (s1[index] != s2[index])
		{
			dif = s1[index] - s2[index];
			return (dif);
		}
		index++;
	}
	return (0);
}
/**
 * _strcpy - copies the strings with \0 to the buffer
 * @dest: pointer to dest
 * @src: pointer to strings
 *
 * Return: the pointer to dest
 *
 */
strings _strcpy(strings dest, strings src)
{
	int index;

	index = 0;
	while (*(src + index) != '\0')
	{
		*(dest + index) = *(src + index);
		index++;
	}
	*(dest + index) = '\0';
	return (dest);
}
/**
 * _strcat - appends the src strings to the dest strings
 * @dest: pointer to dest strings
 * @src: pointer to src strings
 *
 * Return: pointer to resulting strings dest
 *
 */
strings _strcat(strings dest, strings src)
{
	int index, length;

	length = _strlen(dest);

	for (index = 0 ; src[index] != '\0' ; index++)
		dest[length + index] = src[index];
	dest[length + index] = '\0';

	return (dest);
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
*           contains a copy of the strings given as a parameter
* @str: strings to copy
* Return: pointer to new strings or NULL if str = NULL
*/
strings _strdup(strings str)
{
	int index, length;
	strings new_str;

	if (str == NULL)
		return (NULL);
	length = _strlen(str);
	new_str = malloc(sizeof(char) * (length + 1));
	if (new_str == NULL)
		return (NULL);
	for (index = 0; index < length; index++)
		new_str[index] = str[index];
	new_str[length] = '\0';
	return (new_str);
}
