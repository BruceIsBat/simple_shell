#ifndef SHELL_H
#define SHELL_H

#define BUFSIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
<<<<<<< HEAD
#include <sys/types.h>

void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void _memset(char *str, int fill, int n);
void _memcpy(char *dest, char *src, unsigned int bytes);
char *_getline(int file);
=======

#define MAX_ARGS 10
#define MAX_PATH_LENGTH 1024
>>>>>>> ededaeeb9759acd91bd29e0dc79d18fdebcbcd37

void handle_status(char *file_name);
void exce_cmd(char **args, char *file_name);
char *find_cmd(char *command);

#endif
