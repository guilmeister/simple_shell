#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int exec(char **token);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char **strbreak(char *buffer);
char *_strdup(char *str);
void free_tokens(char **buffer);

#endif
