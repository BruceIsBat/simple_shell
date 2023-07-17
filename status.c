#include "shell.h"

void handle_status (char *file_name)
{
        char *args = NULL;
        ssize_t read;
        size_t n = 0;

        while (1)
        {
                printf("#cisfun$ ");

                read = getline(&args, &n, stdin);
        /*      printf("%s", args);
        */
                if (read == -1)
                {
                        free(args);
                        exit(EXIT_FAILURE);
                }

                int i=0;
                while(args[i])
                {
                        if (args[i] == '\n')
                                args[i]=0;
                        i++;
                }

                exce_cmd(args, file_name);
        }
}
