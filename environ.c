#include "holberton.h"
/**
 * my_env - prints user enviroment
 *
 *
 * @env: char double pointer to environ
 *
 * Return: exit success
 */
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
/**
 * pEnv - prints user enviroment
 *
 * @name: char pointer
 *
 * Return: NULL
 */
char *pEnv(char *name)
{
	char **envPtr;
	char *ptr;
	char *namePtr;

	for (envPtr = environ; *envPtr; envPtr++)
	{
		for (ptr = *envPtr, namePtr = name; *ptr == *namePtr;
		     ptr++, namePtr++)
		{
			if (*ptr == '=')
				break;
		}
		if ((*ptr == '=') && (!*namePtr))
			return (ptr + 1);
	}
	return (NULL);
}
