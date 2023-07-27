#include "shell.h"
/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
	printString("#cisfun$ ");
}
/**
 * handle_status - handle status
 * @file_name: gets the file name
 *
 * Return: return success or -1.
 */
void handle_status(char *file_name)
{
	char *args = NULL, *token, *arguments[MAX_ARGS];
	ssize_t read;
	size_t n;
	int i;

	n = 0;
	while (1)
	{
		display_prompt();

		read = getline(&args, &n, stdin);

		if (*args != '\n')
		{
			if (read == -1)
			{
				free(args);
				exit(EXIT_FAILURE);
			}

			i = 0;

			token = strtok(args, " \n");

			while (token != NULL && i < MAX_ARGS)
			{
				arguments[i] = token;
				token = strtok(NULL, " \n");
				i++;
			}
			arguments[i] = NULL;

			if (strcmp(arguments[0], "exit") == 0)
			{
				break;
			}
			exce_cmd(arguments, file_name);
		}
	}
	free(args);
}
