#ifndef HOLBERTON_H
#define HOLBERTON_H
#define SIZE 256
#define MAX_NAME_SIZE 1000
#define MAX_ARGS 1000

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
#include <signal.h>

extern char **environ;

char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int launch(char **token);
int __execvp(char *name, char *argv[]);
char *pEnv(char *name);
void DoExec(char *file, char *argv[]);
char *_strchr(char *s, char c);
char *_memcpy(char *dest, char *src, unsigned int n);
size_t _strnlen(const char *str, size_t maxlen);
int my_cd(char **args);
int my_help(char **args);
int my_exit(char **args);
int exec(char **args);
char **parse(char *line);
char *readLine(void);
int _strlen(char *string);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char **strbreak(char *buffer);
char *_strdup(char *str);
void free_tokens(char **buffer);
int my_env(char **env);
int _putchar(char c);
int space_finder(char buffer);

#endif
