#include "holberton.h"

int _cd(char **args)
{
	if (chdir(args[1]) != 0)
	{
		perror("Error");
	}
	return (1);
}
int _help(char **args)
{
	write(2, "Welcome to Trevor's and Ed's simple Unix shell!\n", 45);
	write(2, "type program names and arguments and press enter\n", 40);
	write(2, "cd, help, and exit are built in commmands", 35);
	write(2, "Use the man command to find info on other programs", 40);
	return (1);
}

int _exit(char **args)
{
	return (0);
}
