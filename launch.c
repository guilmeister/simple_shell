#include "holberton.h"

int launch(char **token)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(token[0], token, NULL) == -1)
			perror("error");
		exit(1);
	}
	if (pid > 0)
		wait(&status);
	return (1);
}
