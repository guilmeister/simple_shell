#include "holberton.h"

void signal_handler(int signum)
{
	(void)signum;
	_putchar('\n');
	write(STDOUT_FILENO, "$ ", 2);
}

int main(int argc, char *argv[], char **env)
{
	char *buffer = NULL;
	char **token = NULL;
	size_t length = 0;
	int check, counter = 0;
	pid_t parentpid = getpid();

	(void)argc;
	(void)argv;
	while (1)
	{
		signal(SIGINT, signal_handler);
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		check = getline(&buffer, &length, stdin);
		if (isatty(STDIN_FILENO) == 0)
		{
			if (check == -1)
			{
				exit(1);
			}
		}
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
			decrementBuffer(buffer, counter); }
		free_tokens(token);
		free(token);	}
	decrementBuffer(buffer, counter);
	return (EXIT_SUCCESS);
}

int my_cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("Error");
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
