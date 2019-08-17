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

int exec(char **argv);
char **parse(char *line);
int main(void);
char *readLine(void);
int _strlen(char *string);

#endif
