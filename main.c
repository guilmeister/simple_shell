#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "holberton.h"

int main(int ac, char **av, char **env)
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
		{	free(buffer);
			perror("Error");
			exit(98);
		}
		if (_strcmp("env\n", buffer) == 0)
		{
			my_env(env);
			continue;
		}
		if (_strcmp("path\n", buffer) == 0)
		{
			my_path(env);
			continue;
		}
		token = strbreak(buffer);
		exec(token);
	}
	free_tokens(token);
	free(buffer);
	return (EXIT_SUCCESS);
}

int my_cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("error");
	}
	else if (chdir(args[1]) != 0)
	{
		perror("Error");
	}
	return (EXIT_SUCCESS);
}

int my_help(char **args)
{
	args++;
	write(2, "Welcome to Trevor's and Ed's simple Unix shell!\n", 56);
	write(2, "type program names and arguments and press enter\n", 56);
	write(2, "cd, help, and exit are built in commmands\n", 45);
	write(2, "Use the man command to find info on other programs\n", 52);
	return (EXIT_SUCCESS);
}

int my_exit(char **args)
{
	args = args;
	exit(0);
}

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

int my_path(char **env)
{
	int x;

	for (x = 0; env[x] != NULL; x++)
	{
		if(_strstr(env[x], "PATH"))
		{	write(STDOUT_FILENO, env[x], _strlen(env[x]));
			_putchar('\n');
		}
	}
	return (EXIT_SUCCESS);
}
