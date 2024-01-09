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
 * add_arguments - Adds compilation arguments to an array,
 * combining a set of default flags with user-provided flags.
 * @compiler_arguments: Array to store compilation arguments.
 * @user_arguments: Array containing user-provided compilation arguments.
 * @length: Length of compilation arguments.
 * Return: 0 on success.
 * Returns 1 if memory allocation fails.
 */
int add_arguments(char ***compiler_arguments, char **user_arguments, int length)
{
	int i = 1, j = 1;

	*compiler_arguments = (char **)malloc(sizeof(char *) * (length + 6));
	if (*compiler_arguments == NULL)
		return (1);
	/*Set default compilation flags*/
	(*compiler_arguments)[j++] = "-Wall";
	(*compiler_arguments)[j++] = "-Werror";
	(*compiler_arguments)[j++] = "-Wextra";
	(*compiler_arguments)[j++] = "-pedantic";
	(*compiler_arguments)[j++] = "-std=gnu89";
	/*Copy user-provided flags to the compiler flags array*/
	for (i = 1; i < length; i++, j++)
		(*compiler_arguments)[j] = strdup(user_arguments[i]);
	(*compiler_arguments)[j] = NULL;

	return (0);
}

/**
 * add_arguments_advanced - Adds compilation arguments to an array,
 * combining a set of default flags, user-provided arguments, and new output file.
 * @compiler_arguments: Array to store compilation arguments.
 * @user_arguments: Array containing user-provided compilation arguments.
 * @length: Length of compilation arguments.
 * Return: 0 on success.
 * 1 if memory allocation fails.
 */
int add_arguments_advanced(char ***compiler_arguments, char **user_arguments, int length)
{
	int i = 1, j = 6;

	*compiler_arguments = (char **)malloc(sizeof(char *) * (length + 8));
	if (*compiler_arguments == NULL)
		return (1);
	/*Add standard flags to the modified array*/
	(*compiler_arguments)[1] = "-Wall";
	(*compiler_arguments)[2] = "-Werror";
	(*compiler_arguments)[3] = "-Wextra";
	(*compiler_arguments)[4] = "-pedantic";
	(*compiler_arguments)[5] = "-std=gnu89";
	/*Copy original arguments to the modified array*/
	for (i = 1; i < length; i++, j++)
		(*compiler_arguments)[j] = user_arguments[i];
	/*Add output file option and its name to the modified array*/
	(*compiler_arguments)[j++] = "-o";
	(*compiler_arguments)[j++] = remove_extension(user_arguments, length);
	(*compiler_arguments)[j] = NULL;
	return (0);
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

/*
 * remove_extension - Extracts filename without extension from command-line args
 * @argv: An array of strings representing command-line arguments.
 * Return: Name of file without extension if a non-flag argument is found
 * Memory is allocated using malloc, and the caller is responsible for freeing it.
 * If no such argument is found, or if memory allocation fails, it returns NULL.
 */
char *remove_extension(char **command_line_args, int length)
{
	int i = 1, j = 0, string_length = 0;
	char *file_name = NULL;

	while (i < length)
	{
		if (command_line_args[i][0] != '-')
		{
			/*Calculate the length of the filename without extension*/
			for (; command_line_args[i][j] != '.' || '\0'; j++)
				string_length++;
			/*Allocate memory for the filename without extension*/
			file_name = (char *)malloc(sizeof(char) * (string_length + 1));
			if (file_name == NULL)
				return (NULL);
			/*Copy characters to the new string*/
			for (j = 0; j < string_length; j++)
				file_name[j] = command_line_args[i][j];
			file_name[j] = '\0';
			return (file_name);
		}
		i++;
	}
	return (NULL);
}
