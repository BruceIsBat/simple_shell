#include "shell.h"
/**
 * handle_status - handle status
 * @file_name: gets the file name
 *
 * Return: return success or -1.
 */
void handle_status(char *file_name)
{
	char *args = NULL;
	ssize_t read;
	size_t n;

	n = 0;

	while (1)
	{
		printf("#cisfun$ ");

		read = getline(&args, &n, stdin);

		if (*args != '\n')
		{
			if (read == -1)
			{
				free(args);
				exit(EXIT_FAILURE);
			}

			int i;

			i = 0;

			while (args[i])
			{
				if (args[i] == '\n')
					args[i] = 0;
				i++;
			}


			if (strcmp(args, "exit") == 0)
			{
				break;
			}
			exce_cmd(args, file_name);
		}
	}
}
