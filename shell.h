#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 10
#define MAX_PATH_LENGTH 1024

void handle_status(char *file_name);
void exce_cmd(char **args, char *file_name);
char *find_cmd(char *command);

#endif
