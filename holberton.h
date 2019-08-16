#ifndef HOLBERTON_H
#define HOLBERTON_H
#define SIZE 1024
#include <stdio.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int exec(char **argv);
char **parse(char *token);
int main(int argc, char *argv[]);
char *readLine(void);
int _strlen(char *string);

#endif
