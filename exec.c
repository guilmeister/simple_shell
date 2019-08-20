#include "holberton.h"
int launch(char **tokens);
int exec(char **args)
{
	int i;
	int (*builtin_func[]) (char **) = {&my_cd, &my_help, &my_exit};
	char *builtin_str[] = {"cd", "help", "exit"};

	if (args[0] == NULL)
	{
		perror("error");
		return (EXIT_FAILURE);
	}
	for (i = 0; i < 3; i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	launch(args);
	return(1);
}
int my_exit(char **args)
{
	args = args;
	return (-1);
}
