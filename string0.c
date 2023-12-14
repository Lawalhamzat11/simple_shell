#include "shell.h"
/**
 * _strcmp - compares two strings
 * @s1: pointer to strings s1
 * @s2: pointer to strings s2
 * Return: difference in value of first char that's different
 */
int _strcmp(strings s1, strings s2)
{
	int index, dif;

	index = 0;
	while (s1[index] != '\0' || s2[index] != '\0')
	{
		if (s1[index] != s2[index])
		{
			dif = s1[index] - s2[index];
			return (dif);
		}
		index++;
	}
	if (s1[index] == s2[index] && s1[index] == '\0')
		dif = 0;
	return (dif);
}
/**
 * _strchr - locates character in strings
 * @str: pointer to a strings
 * @c: char to find
 * Return: pointer to the matched character or NULL
 */
strings _strchr(strings str, char c)
{
	int index;

	for (index = 0; str[index] != '\0'; index++)
	{
		if (str[index] == c)
			return ((strings)(str + index));
	}
	return (NULL);
}
/**
 * length_char - finds strings length to passed char
 * @str: pointer to a strings
 * @c: char to find
 * Return: length of strings before char or 0 if not found
 */
int length_char(strings str, char c)
{
	int index;

	index = 0;
	while (str[index] != c && str[index] != '\0')
		index++;
	if (str[index] == '\0')
		return (0);
	return (index);
}
/**
 * _atoi - converts strings to integer
 * @s: pointer to strings to print
 * Return: number or -1 on error
 */
int _atoi(strings s)
{
	int size, number, exponent, index;

	size = _strlen(s);
	exponent = 1;
	for (index = 1; index < size; index++)
		exponent *= 10;
	number = 0;
	for (index = 0; s[index] != '\0'; index++)
	{
		if (s[index] >= '0' && s[index] <= '9')
			number += (s[index] - '0') * exponent;
		else
		{
			perror("wrong input for exit status\n");
			return (-1);
		}
		exponent /= 10;
	}
	return (number);
}
