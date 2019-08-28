#include "holberton.h"
/**
 * my_cd - attempt to recreate the "cd" builtin using chdir
 *
 * @args: char double pointer
 *
 * Return: exit success
 */
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
/**
 * my_help - implementation of the "help" builtin cmd
 *
 *
 * @args: char double pointer
 *
 * Return: exit success
 */
int my_help(char **args)
{

	if (args[1])
	{
		if (_strcmp("cd", args[1]) == 0)
		{
			write(2, "cd is used to navigate directories\n", 36);
			write(2, "Usage: cd <directory>\n", 23);
		}
		else if (_strcmp("env", args[1]) == 0)
		{
			write(2, "env prints the content of your enviroment\n", 43);
			write(2, "Usage: env\n", 12);
			write(2, "for more information use man env\n", 34);
		}
		else if (_strcmp("exit", args[1]) == 0)
		{
			write(2, "exit terminates all current processes\n", 39);
			write(2, "Usage: exit\n", 13);
			write(2, "for more information use man exit\n", 35);
		}
		else
		{
			write(2, "help: no help topics match ", 27);
			write(2, args[1], _strlen(args[1]));
			write(2, "\n", 2);
		}
	}
	if (!args[1])
	{
		write(2, "Welcome to Trevor's and Ed's simple Unix shell!\n", 56);
		write(2, "type program names and arguments and press enter\n", 56);
		write(2, "cd, help, env, and exit are built in commands\n", 47);
		write(2, "Use the man command to find info on other programs\n", 52);
		write(2, "Usage: help <command>\n", 23);
	}
	return (EXIT_SUCCESS);
}
/**
 * my_exit - exits program
 *
 * @args: char double pointer
 *
 * Return: exit success
 */
int my_exit(char **args)
{
	(void)args;
	while (1)
	{
		exit(EXIT_SUCCESS);
	}
}
/**
 * signal_handler - handles signal inturupt from ctrl+c
 *
 * @signum: value from main
 *
 * Return: void
 */
void signal_handler(int signum)
{
	(void)signum;
	_putchar('\n');
	write(STDOUT_FILENO, "$ ", 2);
}
