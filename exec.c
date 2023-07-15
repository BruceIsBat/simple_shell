#include "shell.h"

void exce_cmd (char *args, char *file_name)

{       char *ags[] = {NULL};
        pid_t child = fork();

        if (child == -1)
        {
                perror(file_name);
        }
        else if (child == 0)
        {
                if (execve(args, ags, NULL) == -1)
                {
                        perror(file_name);
 	                exit(EXIT_FAILURE);
                }
        }
        else
        {
                wait(NULL);
        }
}
