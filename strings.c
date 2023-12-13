#include "myshell.h"
/**
 * _strlen - returns the lenght of a string
 * @s: pointer to s
 * Return: 0 on success
 */
int _strlen(string s)
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
 * @s1: pointer to string s1
 * @s2: pointer to string s2
 * @n: number of chars to compare
 * Return: 0 if identical
 *
 */
int _strncmp(string s1, string s2, int n)
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
 * _strcpy - copies the string with \0 to the buff
 * @dest: pointer to dest
 * @src: pointer to string
 *
 * Return: the pointer to dest
 *
 */
string _strcpy(string dest, string src)
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
 * _strcat - appends the src string to the dest string
 * @dest: pointer to dest string
 * @src: pointer to src string
 *
 * Return: pointer to resulting string dest
 *
 */
string _strcat(string dest, string src)
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
*           contains a copy of the string given as a parameter
* @str: string to copy
* Return: pointer to new string or NULL if str = NULL
*/
string _strdup(string str)
{
	int index, length;
	string new_str;

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
