#include "shell.h"
/**
 * main - takes in one int and a character pointer
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char **argv)
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
