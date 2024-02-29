#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <error.h>
#include <fcntl.h>

extern char **environ;

char *read_line(void);
char **_tokenizer(char *line);
char *_getpath(char *cmd);
char *_getenv(char *name)
int execute(char **cmd, char **av, int index);
void print_error(char **av, char *cmd, int index);
int is_builtin(char **av, int ac, char **cmd, int *index, int *status);
void builtin_handle(char **av, int ac, char **cmd, int *index, int *status);
void print_env(char **cmd, int *status);
void exit_error(char **av, int *index, char **cmd);
void builtin_exit(char **av, int ac, char **cmd, int *status, int *index);

int _strlen(char *str);
char *_strdup(char *line);
int _strncmp(char *str1, char *str2, int n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strtoint(char *s);
char *_inttostr(int n);
int _strcmp(char *str1, char *str2);
int is_number(char *str);

void free_2d_array(char **cmd);

#endif
