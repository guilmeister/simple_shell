#include "holberton.h"
/**
 * exec - exec builtins and if not builtin launch args to be executed
 *
 * @args: char double pointer
 *
 * Return: 1 or 0
 */
int exec(char **args)
{
	int i, exiting;

	int (*builtin_func[]) (char **) = {&my_cd, &my_help, &my_exit, &my_env};
	char *builtin_str[] = {"cd", "help", "exit", "env"};

	if (args[0] == NULL)
	{
		if (isatty(STDIN_FILENO) == 0)
			exit(127);
		perror("Error");
		free(args);
		return (EXIT_FAILURE);
	}
	for (i = 0; i < 4; i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	exiting = launch(args);

	return (exiting);
}
