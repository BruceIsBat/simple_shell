#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void handle_status(char *file_name);
void exce_cmd(char *args, char *file_name);

#endif
