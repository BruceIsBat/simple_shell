#include "shell.h"

void handle_status (char *file_name)
{
        char *args = NULL;
        int read;
       size_t n = 0;

        while (1)
        {
                printf("$ ");

                read = getline(&args, &n, stdin);

                if (read == -1)
                {
                        free(args);
                }
        }
}
