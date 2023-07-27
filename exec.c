#include "shell.h"

void executor(char *argv[], env_t *linkedlist_path)
{
    pid_t child_status = 0;
      char *abs_path;

    abs_path = search_os(argv[0], linkedlist_path);

    if (!abs_path)
    {
        perror("command not found\n");
        return;
    }

    child_status = fork();
        if (child_status == -1)
        {
                perror("fork failed\n");
        } else if (child_status == 0){
            if (execve(abs_path, argv, environ) == -1)
                 {
                        perror("execution failed\n");

                }
       } else {
            free(abs_path);
           if (wait(NULL) == -1) {
                  perror("wait failed\n");
               }
        }
}
