#include "shell.h"
/**
 *   * _setenv_usr - sets environmental variables as user defines
 *     * @tokens: KEY=VALUE pair
 *       * Return: 0 on success, -1 on failure
 *         */
int _setenv_usr(char **tokens)
{
        int i, status, wc;
        char *key, *value, *saveptr;

        for (i = 0, wc = 1; tokens[1][i]; i++)
        if (tokens[1][i] == '=')
                wc++;
        for (i = 0; tokens[i]; i++)
                ;
        if (!tokens[1] || i == 0 || wc != 2)
                {
        printString("setenv: Usage: setenv KEY=VALUE\n");
                        return (-1);
                }
        key = _strtok_r(tokens[1], "=", &saveptr);
        value = _strtok_r(NULL, "=", &saveptr);
        status = _setenv(key, value, 0);
                if (status == 0)
        return (status);
        return (-1);
}
/**
 *   * _alias - sets aliases or prints them out when no options are supplied
 *     * Return: 0
 *       */
int _alias(void)
{
        printString("alias: usage: alias [-p] [name[=value] ... ]\n");
        printString("\tSet or view aliases.\n\tSet with name=value\n");
        printString("\tView list of aliases with no arugments or -p\n");
        return (0);
}

/**
 * * _history - prints out history with no options,
 * *  or clears history with -c
 * * Return: 0 on success, 1 if history cannot be cleared.
 * */
int _history(void)
{
        printString("history: usage: history [-c]\n");
        printString("\tView the history of commands\n ");
        printString("\t'history -c' clears the history\n");
        return (0);
}
