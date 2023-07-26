#include "shell.h"
/**
 * exce_cmd - Running the execve in a child process
 * @args: gets the buffer address of the input
 * @file_name: the file name
 *
 * Return: returns -1 for error or 0 for successful child process.
 */
void exce_cmd(char **args, char *file_name)
{
	pid_t child;
	char *command_path;
	int status;

	command_path = find_cmd(args[0]);

	if (command_path == NULL)
	{
		printf("Command not found: %s\n", args[0]);
		return;
	}

	child = fork();

	if (child == -1)
	{
		free(command_path);
		perror(file_name);
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		if (execve(command_path, args, NULL) == -1)
		{
			perror(file_name);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	free(command_path);
}
