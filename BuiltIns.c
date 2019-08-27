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
	args++;
	write(2, "Welcome to Trevor's and Ed's simple Unix shell!\n", 56);
	write(2, "type program names and arguments and press enter\n", 56);
	write(2, "cd, help, env, and exit are built in commmands\n", 48);
	write(2, "Use the man command to find info on other programs\n", 52);
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
	while (1 || args)
	{
		exit(EXIT_SUCCESS);
	}
}
/**
 * signal_handler -
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
