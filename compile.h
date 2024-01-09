#ifndef COMPILE_H
#define COMPILE_H

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

char *add_strings(char *first_string, char *second_string, char *thrid_string);
char *check_gcc(void);
int add_arguments(char ***compiler_arguments, char **user_arguments, int length);
int add_arguments_advanced(char ***compiler_arguments, char **user_arguments, int length);
int execute_gcc(char **gcc_flags, char **env);
char *remove_extension(char **command_line_args, int length);
int contains_string(char **string_array, char *target_string, int length);
void free_double_pointer(char **double_pointer);
void free_last_string(char **double_pointer);

#endif
