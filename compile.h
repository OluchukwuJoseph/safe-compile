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
int tokenize(char ***array, char **av);
void add_flags(char **compiler_flags, char **user_flags);
int execute_gcc(char **gcc_flags, char **env);

#endif
