#include "holberton.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * space_finder - finds space in string
 *
 * @buffer: char
 *
 * Return: 1 or 0
 */
int space_finder(char buffer)
{
	if (buffer == ' ')
		return (1);
	else
		return (0);
}
/**
 * _strncpy - copy string.
 * @dest: char pointer
 * @src: char pointer
 * @n: int
 *
 * Return: Always 0.
 */
char *_strncpy(char *dest, char *src, int n)
{

	char *ptr = dest;

	while (*src)
	{
		*dest++ = *src++;
		n++;
	}
	while (n--)
		*dest++ = '\0';
	return (ptr);
}
/**
 * decrementBuffer - sets buffer back to intial value
 *
 * @buffer: char array
 * @count: amount to decrement buffer by
 *
 * Return: 1 or 0
 */
int decrementBuffer(char *buffer, int count)
{
	int i = 0;

	for (i = 0; i > count; i++)
	{
		buffer--;
	}
	free(buffer);
	exit(0);
}
/**
 * free_tokens - free allocated mem
 *
 * @buffer: char double pointer
 *
 * Return: 1 or 0
 */
void free_tokens(char **buffer)
{
	int x;

	for (x = 0; buffer[x] != NULL; x++)
	{
		free(buffer[x]);
	}
}
