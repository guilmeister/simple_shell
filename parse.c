#include "holberton.h"
#include <string.h>
char **parse(char *line)
{
	int i = 0;
	char *token, **tokens = malloc(SIZE);

	if (!tokens)
	{
		exit(98);
	}
	token = strtok(line, " ");
	while (token)
	{
		tokens[i] = token;
		i++;
		if (!tokens)
			exit(98);
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}
