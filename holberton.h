#ifndef HOLBERTON_H
#define HOLBERTON_H
#define SIZE 1024

#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int my_cd(char **args);
int my_help(char **args);
int my_exit(char **args);
int exec(char **argv);
char **parse(char *line);
char *readLine(void);
int _strlen(char *string);
int exec(char **token);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char **strbreak(char *buffer);
char *_strdup(char *str);
void free_tokens(char **buffer);
int my_env(char **env);
int _putchar(char c);
char *_strstr(char *haystack, char *needle);
int my_path(char **env);

#endif
