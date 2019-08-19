#include "holberton.h"

int exec(char **token)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(token[0], token, NULL) == -1)
			perror("error");
	}
	if (pid > 0)
		wait(&status);
	return (1);
}
