#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>


#define MAX_ARGS 10
#define MAX_PATH_LENGTH 1024

#include "shell.h"

int printString(char *s);
void handle_status(char *file_name);
void exce_cmd(char **args, char *file_name);
char *find_cmd(char *command);

/******** String functions *******/
char *str_dup(char *string);
char *str_cpy(char *dest, char *src);
char *str_cat(char *dest, char *src);
int _strncmp(char *str1, char *str2, size_t n);
int str_len(char *string);

char *_strtok_r(char *str, char *delim, char **saveptr);
#endif
