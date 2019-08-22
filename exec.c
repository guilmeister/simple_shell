#include "holberton.h"
int launch(char **tokens);
int exec(char **args, char **env)
{
	int i, x;
	int (*builtin_func[]) (char **) = {&my_cd, &my_help, &my_exit, &my_env};
	char *builtin_str[] = {"cd", "help", "exit", "env"};
	char *token;
	char *concat;

	if (args[0] == NULL)
	{
		perror("error");
		return (EXIT_FAILURE);
	}
	for (i = 0; i < 4; i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}

	if (i == 4)
	{
		for (x = 0; env[x] != NULL; x++)
		{
			token = strtok(env[x], "=");

			if (_strcmp(env[x], "PATH") == 0)
			{
				while (token != NULL)
				{
					token = _strdup_path(strtok(NULL, ":"));
					if (token == NULL)
						break;
					concat = _strcat(token, args[0]);
					if (access(concat, F_OK) == 0)
						execve(concat, args, NULL);
				}
			}
		}
	}
	return (EXIT_SUCCESS);
}
