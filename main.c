#include "holberton.h"

void signal_handler(int signum)
{
	(void)signum;
	_putchar('\n');
	write(STDOUT_FILENO, "$ ", 2);
}

int main(int acUnused __attribute__((unused)), char **av, char **env)
{
	char *buffer = NULL;
	char **token = NULL;
	size_t length = 0;
	int x, check, counter = 0;
	pid_t parentpid = getpid();

	(void)av;
	while (1)
	{	signal(SIGINT, signal_handler);
		write(STDOUT_FILENO, "$ ", 2);
		check = getline(&buffer, &length, stdin);
		if (check == -1 || !buffer)
		{	free(buffer);
			perror("Error");	}
		while (space_finder(*buffer))
		{	buffer++;
			counter++;		}
		if (_strcmp("\n", buffer) == 0)
			continue;
		if (_strcmp("env\n", buffer) == 0)
		{	my_env(env);
			continue;		}
		if (_strcmp("exit\n", buffer) == 0)
			break;
		token = strbreak(buffer);
		exec(token);
		if (parentpid != getpid())
		{
			for (x = 0; x < counter; x++)
				buffer--;
			free(buffer);
			exit(1);
		}
		free_tokens(token);
		free(token);
	}
	for (x = 0; x < counter; x++)
		buffer--;
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
	write(2, "cd, help, env, and exit are built in commmands\n", 48);
	write(2, "Use the man command to find info on other programs\n", 52);
	return (EXIT_SUCCESS);
}

int my_exit(char **args)
{
	while (1 || args)
	{
		exit(EXIT_SUCCESS);
	}
}
