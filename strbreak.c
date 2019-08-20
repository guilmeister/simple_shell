#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "holberton.h"

char **strbreak(char *buffer)
{
	char **words;
	size_t index = 0;
	char *token = NULL;

	if (buffer == NULL)
		return (NULL);

	words = malloc(sizeof(char) * (_strlen(buffer)));

	if (words == NULL)
		return (NULL);

	while ((token = strtok(buffer, " \n\t:")))
	{
		if (buffer)
			buffer = NULL;

		words[index] = _strdup(token);
		if (words[index] == NULL)
		{free(words[index]);
			return (NULL);
		}
		index++;
	}
	words[index] = NULL;

	return (words);
}
