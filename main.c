#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "holberton.h"

int main(int ac, char **av)
{
	char *buffer = NULL;
	char **token;
	size_t length = 0;
	int check;

	(void)ac;
	(void)av;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		check = getline(&buffer, &length, stdin);
		if (check == -1)
		{free(buffer);
			perror("Error");
			exit(98);
		}
		token = strbreak(buffer);
		if (_strcmp("exit", buffer) == 0)
			break;
		exec(token);
	}
	free_tokens(token);
	free(buffer);
	return (0);
}
