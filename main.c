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
	int check, exiting, counter = 0;
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
			if (check == -1 || check == EOF)
			{
				exit(EXIT_FAILURE);
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
		exiting = exec(token);
		if (parentpid != getpid())
			decrementBuffer(buffer, counter);
		free_tokens(token);
		free(token);
	}
	decrementBuffer(buffer, counter);
	return (exiting);
}
