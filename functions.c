#include "compile.h"

/**
 * check_gcc - Checks for GCC compiler in the PATH environment variable.
 *
 * Return: Returns the full path to the GCC executable if GCC exits.
 * Otherwise, returns NULL.
 */
char *check_gcc(void)
{
	char *path_env = getenv("PATH");
	char *path_env_copy = strdup(path_env);
	char *full_gcc_path = NULL, *current_path = NULL;
	struct stat file_info;

	current_path = strtok(path_env_copy, ":");
	while (current_path != NULL)
	{
		/*Combine the current path segment with "/gcc" to form a potential GCC path*/
		full_gcc_path = add_strings(current_path, "/", "gcc");
		if (full_gcc_path == NULL)
		{
			free(path_env_copy);
			return (NULL);
		}
		/*Check if the file at the combined path exists using stat*/
		if (stat(full_gcc_path, &file_info) == 0)
		{
			free(path_env_copy);
			return (full_gcc_path);
		}
		free(full_gcc_path);
		/*Move to the next path segment*/
		current_path = strtok(NULL, ":");
	}
	free(path_env_copy);
	return (NULL);
}
