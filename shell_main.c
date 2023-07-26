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
		char *line = NULL;
		size_t len = 0;
		ssize_t read;

		char **cmd_args = NULL;

		while ((read = getline(&line, &len, stdin)) != -1)
		{
			/* Removes newline character at the end of the line */
			if (line[read - 1] == '\n')
				line[read - 1] = '\0';

			cmd_args = malloc(4 * sizeof(char *));
			if (cmd_args == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}

			cmd_args[0] = "/bin/sh";
			cmd_args[1] = "-c";
			cmd_args[2] = line;
			cmd_args[3] = NULL;

			exce_cmd(cmd_args, argv[0]);

			free(cmd_args);
		}

		free(line);
	}
	return (0);
}
