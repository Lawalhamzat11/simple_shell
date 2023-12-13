#include "myshell.h"
/**
 * _strcmp - compares two strings
 * @s1: pointer to string s1
 * @s2: pointer to string s2
 * Return: difference in value of first char that's different
 */
int _strcmp(string s1, string s2)
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
 * _strchr - locates character in string
 * @str: pointer to a string
 * @c: char to find
 * Return: pointer to the matched character or NULL
 */
string _strchr(string str, char c)
{
	int index;

	for (index = 0; str[index] != '\0'; index++)
	{
		if (str[index] == c)
			return ((string)(str + index));
	}
	return (NULL);
}
/**
 * length_char - finds string length to passed char
 * @str: pointer to a string
 * @c: char to find
 * Return: length of string before char or 0 if not found
 */
int length_char(string str, char c)
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
 * _atoi - converts string to integer
 * @s: pointer to string to print
 * Return: number or -1 on error
 */
int _atoi(string s)
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
