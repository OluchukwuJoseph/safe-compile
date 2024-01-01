#include "compile.h"

int main(int ac, char **av, char **environ)
{
	char *gcc_path = NULL, **args = NULL;

	gcc_path = check_gcc();
	if (gcc_path == NULL)
	{
		fprintf(stderr, "Error: Could not find GCC compiler on your system.\n"
				"You can install GCC by using the package manager for your system:\n"
				"- For Debian/Ubuntu: sudo apt-get install gcc\n"
				"- For Red Hat/Fedora: sudo yum install gcc\n"
				"- For macOS (using Homebrew): brew install gcc\n"
				"- For Windows: Download and install MinGW from https://mingw-w64.org/doku.php\n");
		return (1);
	}
	args = (char **)malloc(sizeof(char *) * (ac + 6));
	if (args == NULL)
	{
		free(gcc_path);
		return (-1);
	}
	args[0] = strdup(gcc_path);
	/*Add compilation flags to the args array*/
	add_flags(args, av);
	if (execute_gcc(args, environ) == 1)
		return (98);
	return (0);
}
