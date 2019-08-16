#include "holberton.h"

char *readLine(void)
{
	char *line = NULL;
	ssize_t linesize = 0;

	getline(&line, &linesize, stdin);
	return (line);
}
int _strlen(char *string)
{
	int i = 0;

	for (i = 0; string[i]; ++i)
		;
	return(i);
}
