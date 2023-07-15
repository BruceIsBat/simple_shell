#include "shell.h"
int main (int argc, char **argv)
{
        (void)argc;

        if (isatty(STDIN_FILENO) == 1)
        {
                handle_status(argv[0]);
        }
        else
        {
                /*non interactive*/
        }
        return (0);
}
