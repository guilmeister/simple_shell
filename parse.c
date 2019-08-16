#include "holberton.h"

char **parse(char *line)
{
	char **tokens = malloc(SIZE);
	char *token;
	int i = 0;

	if (!tokens)
		return (NULL);

	*token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
