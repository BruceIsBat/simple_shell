#include "shell.h"

void exce_cmd (char *args, char *file_name)

{
        char *ags[] = {NULL, NULL};
        ags[0] = args;
        pid_t child = fork();

        if (child == -1)
        {
                free(args);
                perror(file_name);
        }
        else if (child == 0)
        {
                if (execve(ags[0], ags, NULL) == -1)
                {
                        perror(file_name);
                        exit(EXIT_FAILURE);
                }
        }
        else
                wait(NULL);
}
