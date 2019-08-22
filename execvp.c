#include "holberton.h"

void DoExec(char *file, char *argv[])
{
	register int i;
	char *newArgv[MAX_ARGS + 1];

	execve(file, argv, environ);
	if (errno == ENOEXEC)
	{
		for (i = 0; argv[i] != 0; i++)
		{
			/* Empty loop body */
		}
		if (i >= MAX_ARGS)
		{
			return;
		}
		newArgv[0] = "sh";
		newArgv[1] = file;
		for (i = 1; argv[i] != 0; i++)
		{
			newArgv[i+1] = argv[i];
		}
		newArgv[i+1] = 0;
		execve("/bin/sh", newArgv, environ);
	}
}
int __execvp(char *name, char *argv[])
{
	char *path;
	char fullName[MAX_NAME_SIZE+1];
	register char *first, *last;
	int nameLength, size, noAccess = 0;

	if (index(name, '/') != 0)
	{
	DoExec(name, argv);
	return -1;
	}
	path = pEnv("PATH");
	if (path == 0)
	{
		path = "/usr/local/bin:/bin:/usr/bin";
	}
	nameLength = strlen(name);
	for (first = path; ; first = last+1)
	{
		for (last = first; (*last != 0) && (*last != ':'); last++)
		{
		}
		size = last-first;
		if ((size + nameLength + 2) >= MAX_NAME_SIZE)
		{
			continue;
		}
		(void) strncpy(fullName, first, size);
		if (last[-1] != '/')
		{
			fullName[size] = '/';
			size++;
		}
		(void) strcpy(fullName + size, name);
		DoExec(fullName, argv);
		if (errno == EACCES)
		{
			noAccess = 1;
		} else if (errno != ENOENT)
		{
			break;
		}
		if (*last == 0)
		{
			if (noAccess)
			{
				errno = EACCES;
			}
			break;
		}
	}
	return -1;
}
int launch(char **token)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (__execvp(token[0], token) == -1)
			perror("Error");
			exit(1);
	}
	if (pid > 0)
		wait(&status);
	return (1);
}
