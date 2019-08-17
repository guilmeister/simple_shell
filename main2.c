#include "holberton.h"

int main(void)
{
	char *string = "hello i am bin slash ls";
	char **buf = malloc(sizeof(string));

	buf = parse(string);

	write(1, buf, 30);

	return (0);
}
