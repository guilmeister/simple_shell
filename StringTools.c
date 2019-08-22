#include "holberton.h"
/**
 * *_strchr - check string for certian char
 * @s: char pointer
 * @c: char.
 *
 * Return: Always 0.
 */
char *_strchr(char *s, char c)
{
	while (*s++)
	{
		if (*s == c)
			return (s);
	}
	return (0);
}
#include "holberton.h"

/**
 * _strcmp - compares string s1 and s2
 *
 * @s1: value from main
 * @s2: value from main
 *
 * Return: value of difference
 */

int _strcmp(char *s1, char *s2)
{
	int counter, difference;

	for (counter = 0; s1[counter] != '\0' || s2[counter] != '\0'; counter++)
	{
		difference = s1[counter] - s2[counter];
		if (difference != 0)
			break;
	}
	return (difference);
}
#include "holberton.h"
/**
 * _strcpy - copy string
 * @dest: char
 * @src: char
 * Return: Always 0.
 */
char *_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest);
}
#include "holberton.h"

/**
 * _strlen - counts string length
 *
 * @s: value from main
 *
 * Return: Always 0 (Success)
 */

int _strlen(char *s)
{
	int counter = 0;

	while (s[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}
#include "holberton.h"

/**
 * _strdup - copy a given string to an allocated memory
 *
 * @str: string to copy
 *
 * Return: string
 */

char *_strdup(char *str)
{
	int i;
	int n = 0;
	char *string;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		n++;

	string = (char *) malloc((n + 1) * sizeof(char));

	if (string == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
		string[i] = str[i];

	string[i] = '\0';

	return (string);
}
