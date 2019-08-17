#include "holberton.h"

char *readLine(void)
{
	char *line = NULL;
	size_t linesize = 0;
	int stat;

	stat = getline(&line, &linesize, stdin);
      	if (stat == -1 || _strlen(line - 1) == EOF)
	{
		exit(1);
	}
	return (line);
}
int _strlen(char *string)
{
	int i = 0;

	for (i = 0; string[i]; ++i)
		;
	return(i);
}
