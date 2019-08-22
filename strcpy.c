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
