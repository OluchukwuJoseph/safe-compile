#ifndef COMPILE_H
#define COMPILE_H

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

char *add_strings(char *first_string, char *second_string, char *thrid_string);
char *check_gcc(void);
int tokenize(char ***array, char **av);

#endif
