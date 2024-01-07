# Safe Compile

Safe Compile is a program designed to enhance the safety of compiling your C code by integrating essential safety flags such as `-Wall`, `-Werror`, `-Wextra`, `-pedantic`, and `-std=gnu89`.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [Issues](#issues)
- [Lincense](#license)

## Installation

### Step 1: Clone or Fork the Repository

You have two options to get started:
- **Clone the repository:** Use the following command in your terminal:

`git clone https:/github.com/OluchukwuJoseph/safe-compile.git`

- **Fork the Repository:** Navigate to the repository's page and fork it to your own GitHub account.

### Step 2: Run the Bash Script

Once you've cloned or forked the repository, navigate to the directory and execute the following command in your terminal:

`./install_safe_compile`

## Usage

There are two primary ways to use Safe-Compile:

1. **With the `-o` Flag**:
```shell
compile main.c [other files] -o main
```
This command compiles the specified files, including `main.c` and any additional files provided, into an executable named `main`.

2. **Without the `-o` Flag**:
```shell
compile main.c [other files]
```
When running `safe-compile` without the `-o` flag, the output file will be named after the first file that was passed. In this case, it will generate an executable named `main`.

**Additional Notes**:
- Ensure the necessary files are listed in the correct order for compilation.
- If no output file is explicitly specified with the `-o` flag, the resulting executable will adopt the name of the first file passed in the command.

## Contributing

1. Fork the repository and clone it locally.
2. Create a new branch for your contributions.
3. Make your changes and ensure they work as expected.
4. Test your changes thoroughly.
5. Commit your changes and provide meaningful commit messages.
6. Push your changes to your fork.
7. Submit a pull request to the `main` branch of the original repository.

## Issues

If you encounter any issues with the code or have suggestions for improvements, please open an issue on the repository. We appreciate detailed descriptions, steps to reproduce, and any additional context that might help us address the problem.

## License

Safe Compile is licensed under the [MIT License](LICENSE).
