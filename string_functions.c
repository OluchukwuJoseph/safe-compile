#include "compile.h"

/**
 * add_strings - Function that concatenates three strings.
 * @first_string: The first string to be concatenated.
 * @second_string: The second string to be concatenated.
 * @thrid_string: The thrid string to be concatenated.
 * Return: Returns a dynamically allocated string containing the concatenated result.
 * Memory is allocated using malloc, and the caller is responsible for freeing it.
 * Returns NULL if all input strings are NULL or if memory allocation fails.
 */
char *add_strings(char *first_string, char *second_string, char *thrid_string)
{
	/*Calculate the lengths of the input strings*/
	int first_length = strlen(first_string);
	int second_length = strlen(second_string);
	int thrid_length = strlen(thrid_string);
	int i = 0, j;
	/*Calculate the total length needed for the concatenated string*/
	int length = first_length + second_length + thrid_length;
	char *output = NULL;

	/*Check if all input strings are NULL*/
	if (first_string == NULL && second_string == NULL && thrid_string == NULL)
		return (NULL);
	/*Allocate memory for the concatenated string*/
	output = (char *)malloc(sizeof(char) * (length + 1));
	/*check if memory allocation is sucessful*/
	if (output == NULL)
		return (NULL);

	/*Copy characters from the first string to the concatenated string*/
	for (j = 0; j < first_length; i++, j++)
		output[i] = first_string[j];
	/*Copy characters from the second string to the concatenated string*/
	for (j = 0; j < second_length; i++, j++)
		output[i] = second_string[j];
	/*Copy characters from the third string to the concatenated string*/
	for (j = 0; j < thrid_length; i++, j++)
		output[i] = thrid_string[j];
	output[i] = '\0';
	return (output);
}

/**
  * contains_string - Checks if a string is present in an array of strings.
  * @string_array: Array of strings to search.
  * @target_string: String to check for in the array.
  * @length: Length of compilation arguments.
  * Return: 0 if the target string is found in the array.
  * Returns 1 if the target string is not found.
  */
int contains_string(char **string_array, char *target_string, int length)
{
	int i = 0;

	while (i < length)
	{
		if (strcmp(string_array[i], target_string) == 0)
			return (0);
		i++;
	}
	return (1);
}
