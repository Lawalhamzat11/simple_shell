#include "myshell.h"
/**
 * total_words - counts separate words in string
 * @str: pointer to s
 * @delim: delimiter
 * Return: number of words
 */
int total_words(string str, char delim)
{
	int index, count;

	index = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (str[index] != delim && (str[index + 1] == delim || str[index + 1]  ==
					'\t' || str[index + 1] == '\0'))
			count++;
		index++;
	}
	return (count);
}
/**
 * wordlen - returns the lenght of a word
 * @s: pointer to s
 * @delim: delimiter
 * Return: lenght
 */
int wordlen(string s, char delim)
{
	int c = 0; /* count  */

	while (*(s + c) != delim && *(s + c) != '\0' && *(s + c) != '\t')
		c++;
	return (c);
}
/**
 * _strtok - splits a string into words
 * @str: string to break
 * @delim: delimiter
 * Return: arr of strings(words)
 */
string *_strtok(string str, char delim)
{
	int index, j, k, h, c, length;
	string *words;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	c = total_words(str, delim);
	if (c == 0)
		return (NULL);
	words = malloc(sizeof(string) * (c + 1));
	if (words == NULL)
		return (NULL);
	index = 0;
	j = 0;
	while (str[index] != '\0')
	{
		while ((str[index] == delim || str[index] == '\t') && str[index] != '\0')
			index++;
		if (str[index] == '\0')
		{
			words[j] = NULL;
			return (words);
		}
		words[j] = malloc(sizeof(char) * (wordlen(str + index, delim) + 1));
		if (words[j] == NULL)
		{
			for (k = j - 1; k >= 0; k--)
				free(words[k]);
			free(words);
			return (NULL);
		}
		length = wordlen(str + index, delim);
		for (h = 0; h < length && str[index] != '\0'; h++, index++)
			words[j][h] = str[index];
		words[j][h] = '\0';
		j++;
	}
	words[j] = NULL;
	return (words);
}
