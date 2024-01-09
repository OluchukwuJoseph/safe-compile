#include "compile.h"

int main(int ac, char **av, char **environ)
{
	char *gcc_path = NULL, **args = NULL;
	int status;

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
	if (contains_string(av, "-o", ac) == 0)
	{
		status = add_arguments(&args, av, ac);
		if (status == 1)
		{
			fprintf(stderr, "Memry Allocation Failed\n");
			return (2);
		}
	}
	else
	{
		status = add_arguments_advanced(&args, av, ac);
		if (status == 1)
		{
			fprintf(stderr, "Memry Allocation Failed\n");
			return (3);
		}
		status = 2;
	}
	args[0] = gcc_path;
	if (execute_gcc(args, environ) == 1)
		return (98);
	free(gcc_path);
	if (status == 2)
		free_last_string(args);
	else
		free_double_pointer(args);
	return (0);
}
