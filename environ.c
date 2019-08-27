#include "holberton.h"

int my_env(char **env)
{
	int x;

	for (x = 0; env[x] != NULL; x++)
	{
		write(STDOUT_FILENO, env[x], _strlen(env[x]));
		_putchar('\n');
	}
	return (EXIT_SUCCESS);
}
char *pEnv(char *name)
{
	char **envPtr;
	char *charPtr;
	char *namePtr;

	for (envPtr = environ; *envPtr; envPtr++)
	{
		for (charPtr = *envPtr, namePtr = name; *charPtr == *namePtr;
		     charPtr++, namePtr++)
		{
			if (*charPtr == '=')
				break;
		}
		if ((*charPtr == '=') && (!*namePtr))
			return (charPtr + 1);
	}
	return (NULL);
}
