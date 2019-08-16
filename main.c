#include "holberton.h"

int main(int argc, char *argv[])
{
	char *line = malloc(SIZE), *args;
	int stat;

	while (1)
	{
		write(1, "$ ", 2);
		line = readLine();
		argv = parse(line);
		exec(argv);
	}
	free(line);
	free(argv);
	return (1);
}
