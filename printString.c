#include "shell.h"

/**
 *  * printString - prints a string to stdout
 *   * @s: pointer to a string
 *    * Return: number of bytes written
 *     * On error, -1 is returned, and errno is set appropriately.
 *      */
int printString(char *s)
{
                return (write(STDOUT_FILENO, s, str_len(s)));
}
