#include "holberton.h"
/**
 * strbreak - parse string by spaces and save each arg into
 * a 2D array
 *
 * @buffer: char string of args
 *
 * Return: 2D array of args, NULL upon failure
 */
char **strbreak(char *buffer)
{
	char **words = NULL;
	size_t index = 0;
	char *token = NULL;

	if (buffer == NULL)
		return (NULL);

	words = malloc(SIZE);
	if (words == NULL)
		return (NULL);

	while ((token = strtok(buffer, " \n\t:")))
	{
		if (buffer)
			buffer = NULL;

		words[index] = _strdup(token);
		if (words[index] == NULL)
		{	free_tokens(words);
			free(words);
			return (NULL);
		}
		index++;
	}
	words[index] = NULL;

	return (words);
}
