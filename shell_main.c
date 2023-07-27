#include "shell.h"
/** Global variable: Flag, to handle interrupt signals **/
unsigned char sig_flag = 0;
/**
 *  * * sighandler - handles signals from keyboard interrupts
 *   * * @sig: the signal caught
 *    * */
static void sighandler(int sig)
{

        if (sig == SIGINT && sig_flag == 0)
                printString("\n#cisfun$: ");
        else if (sig_flag != 0)
               printString("\n");
}

int main(void)
{
        char pipe_flag, *buffer, *cmds, *saveptr, **tokens;
        env_t *linkedlist_path;
        struct stat fstat_buf;

        if (signal(SIGINT, sighandler) == SIG_ERR)
        perror("signal error\n");

        if (fstat(STDIN_FILENO, &fstat_buf) == -1)
        perror("fstat error\n"), exit(98);

        pipe_flag = (fstat_buf.st_mode & S_IFMT) == S_IFCHR ? 0 : 1;

        linkedlist_path = list_from_path();

        if (linkedlist_path == NULL)
                return (-1);
                saveptr = NULL;
	 while (1)
                {
                sig_flag = 0;
                        if (pipe_flag == 0)
                        printString("#cisfun$: ");
                       buffer = _getline(STDIN_FILENO);
                        if (!buffer)
                                break;
                cmds = _strtok_r(buffer, "\n;", &saveptr);

                while (cmds)
                {
                        tokens = parser(cmds, "\t ");
                        if (!tokens)
                                break;
                        if (is_builtin(tokens[0]))
                is_builtin(tokens[0])(tokens, linkedlist_path, cmds);
                        else
                        sig_flag = 1, executor(tokens, linkedlist_path);
                        free(tokens);
                        cmds = _strtok_r(NULL, "\n;", &saveptr);
                }

                free(buffer);
                }
                return (0);
}

