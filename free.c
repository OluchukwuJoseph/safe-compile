#include "compile.h"

/**
 * free_last_string - frees the last string in an array of strings
 * @double_pointer: array of strings
 * Return: Nothing
 */
void free_last_string(char **double_pointer)
{
	int i = 0;

	while (double_pointer[i] != NULL)
		i++;
	free(double_pointer[i - 1]);
	free(double_pointer);
}

/**
 * free_double_pointer - frees a double pointer
 * @double_pointer: array of strings
 * Return: Nothing
 */
void free_double_pointer(char **double_pointer)
{
	int i = 5;

	while (double_pointer[i] != NULL)
	{
		i++;
		free(double_pointer[i]);
	}
	free(double_pointer);
}
