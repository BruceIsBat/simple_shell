#include "shell.h"
/**
 * find_cmd - Handles the path
 * @command: command
 *
 * Return: returns the ful pathe.
 */
char *find_cmd(char *command)
{
	char *path_env;
	char *path;
	char *full_path;

	path_env = getenv("PATH");

	if (path_env == NULL)
	{
		printf("Error: PATH environment variable not set.\n");
		return (NULL);
	}

	path = strtok(path_env, ":");

	while (path != NULL)
	{
		full_path = (char *)malloc(MAX_PATH_LENGTH);
		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, command);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
			free(full_path);
		}

		free(full_path);
		path = strtok(NULL, ":");
	}

	return (NULL);
}
