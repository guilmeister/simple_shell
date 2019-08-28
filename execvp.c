#include "holberton.h"

/**
 * execArgs - function called by __execvp to execute args
 * @file: char pointer
 * @argv: arg vector
 * * * * *
 * ENOEXEC - exec format error (POSIX.1-2001)
 * * * * *
 * Return: void
 */

void execArgs(char *file, char *argv[])
{
	int i = 0;
	char *newArgv[MAX_ARGS + 1];

	execve(file, argv, environ);

	if (errno == ENOEXEC)
	{
		for (i = 0; argv[i] != 0; i++)
		{
		}
		if (i >= MAX_ARGS)
		{
			exit(EXIT_FAILURE);
		}
		newArgv[0] = "sh";
		newArgv[1] = file;
		for (i = 1; argv[i] != 0; i++)
		{
			newArgv[i + 1] = argv[i];
		}
		newArgv[i + 1] = NULL;

		execve("/bin/sh", newArgv, environ);
	}
}

/**
 * __execvp - implentation of the "execvp" function
 * @name: char pointer
 * @argv: argument vector
 * * * * *
 * ENOENT - No such file or directory (POSIX.1-2001)
 * EACCES - Permission denied (POSIX.1-2001)
 * * * * *
 * * * * *
 * Return: -1
 */

int __execvp(char *name, char *argv[])
{
	char *path = pEnv("PATH");
	char fullName[MAX_NAME_SIZE + 1];

	char *first, *last;
	int size = 0, noAccess = 0;

	if (_strchr(name, '/') != 0)
	{
		execArgs(name, argv);
		exit(1);
	}
	if (path == 0)
		path = "/usr/local/bin:/bin:/usr/bin";
	for (first = path; ; first = last + 1)
	{
		for (last = first; (*last != 0) && (*last != ':'); last++)
		{
		}
		size = last - first;
		_strncpy(fullName, first, size);
		if (last[-1] != '/')
			fullName[size++] = '/';
		_strcpy(fullName + size, name);
		execArgs(fullName, argv);
		if (errno == EACCES)
		{
			noAccess = 1;
		}
		else if (errno != ENOENT)
			break;
		if (*last == 0)
		{
			if (noAccess)
			{
				errno = EACCES;
			}
			break;
		}
	}
	return (-1);
}
/**
 * launch - launch child process and call __execvp
 * @token: char double pointer
 * * * * * * * * * * *
 * WUNTRACED - return if a child has stopped
 * WIFEXITED - returns true if the child terminated normally, that is, by
 * calling exit(3) or _exit(2), or by returning from main
 * WIFSIGNALED - returns true if the child process was terminated by a signal
 * * * * * * * * * * *
 *  Return: EXIT_FAILURE
 */
int launch(char **token)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (__execvp(token[0], token) == -1)
		{
			if (isatty(STDIN_FILENO) == 0)
				exit(1);
			perror("simple_shell");
			free_tokens(token);
			free(token);
			return (EXIT_SUCCESS);
		}
	}
	if (pid > 0)
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (EXIT_FAILURE);
}
