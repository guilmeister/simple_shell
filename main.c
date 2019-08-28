#include "holberton.h"
/**
 * main - starting point for the simple_shell program
 *
 * @argc: argument count
 * @argv: argument vector
 * @env: environ
 *
 * Return: exit success
 */
int main(int argc, char **argv, char **env)
{
	char *buffer = NULL, **token = NULL;
	size_t length = 0;
	int exiting, counter = 0;
	pid_t parentpid = getpid();

	(void)argc;
	(void)argv;
	while (1)
	{
		signal(SIGINT, signal_handler);
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		if (getline(&buffer, &length, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 2);
			break;
		}
		while (space_finder(*buffer))
		{	buffer++;
			counter++;		}
		if (_strcmp("\n", buffer) == 0)
			continue;
		if (_strcmp("env\n", buffer) == 0)
		{	my_env(env);
			continue;		}
		token = strbreak(buffer);
		exiting = exec(token);
		if (_strcmp("exit\n", buffer) == 0)
			break;
		if (parentpid != getpid())
			decrementBuffer(buffer, counter);
		free_tokens(token);
		free(token);
	}
	decrementBuffer(buffer, counter);
	return (exiting);
}
