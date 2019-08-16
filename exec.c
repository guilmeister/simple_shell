#include "holberton.h"

int exec(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("error");
	}
	if (pid > 0)
		waitpid(pid, &status, NULL);
	return (1);
}
