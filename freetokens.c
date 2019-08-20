#include <stdlib.h>
#include "holberton.h"

void free_tokens(char **buffer)
{
	int x;

	for (x = 0; buffer[x] != NULL; x++)
		free(buffer[x]);
}
