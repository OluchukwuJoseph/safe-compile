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

/**
 * add_flags - Adds compilation flags to an array, combining a set of default flags with user-provided flags.
 * @compiler_flags:  Array to store compilation flags.
 * @user_flags: Array containing user-provided compilation flags.
 * Return: Nothing
 */
void add_flags(char **compiler_flags, char **user_flags)
{
	int i = 1, j = 1;

	/*Set default compilation flags*/
	compiler_flags[j++] = "-Wall";
	compiler_flags[j++] = "-Werror";
	compiler_flags[j++] = "-Wextra";
	compiler_flags[j++] = "-pedantic";
	compiler_flags[j++] = "-std=gnu89";

	/*Copy user-provided flags to the compiler flags array*/
	while (user_flags[i] != NULL)
	{
		compiler_flags[j] = strdup(user_flags[i]);
		i++;
		j++;
	}
	compiler_flags[j] = NULL;
}

int execute_gcc(char **gcc_flags, char **env)
{
	pid_t id;
	int status;

	id = fork();
	if (id < 0)
		return (1);
	if (id > 0)
	{
		wait(&status);

		if (WEXITSTATUS(status) == 0)
			return (0);
		else
			return (1);
	}

	if (id == 0)
	{
		if (execve(gcc_flags[0], gcc_flags, env) == -1)
		{
			perror("Could not execute file\n");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	return (0);
}
