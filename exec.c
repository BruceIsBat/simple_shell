#include "shell.h"
/**
 * exce_cmd - Running the execve in a child process
 * @args: gets the buffer address of the input
 * @file_name: the file name
 *
 * Return: returns -1 for error or 0 for successful child process.
 */
void exce_cmd(char *args, char *file_name)
{
	char *ags[10];
	int index = 0;

	/*please explain again*/
	ags[0] = strtok(ads, " ");

	while (ags[index] != NULL)
	{
		index++;
		ags[index] = strtok(NULL, " ");
	}
	ags[index] = NULL;/* to this place*/
	pid_t child = fork();

	if (child == -1)
	{
		free(args);
		perror(file_name);
	}
	else if (child == 0)
	{
		if (execve(ags[0], ags, NULL) == -1)
		{
			perror(file_name);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}
