# Project Minishell

Minishell is a project that aims to create a simplified shell program. It provides a command-line interface where users can execute various commands and manage processes. This README provides instructions on installing, using, and understanding the project, as well as acknowledging the individuals who contributed to its development.

## Installation

To install and use Minishell, follow these steps:

1. Clone the Minishell repository from GitHub:
   ```
   git clone https://github.com/username/minishell.git
   ```

2. Change into the project directory:
   ```
   cd minishell
   ```

3. Compile the Minishell program using the provided Makefile:
   ```
   make
   ```

4. The `minishell` executable will be generated. You can now start using Minishell.

Note: Minishell requires a Unix-like operating system and a C compiler (e.g., GCC) to be installed on your system.

## Usage

To use Minishell, follow the syntax:

```
./minishell
```

This command starts the Minishell program and presents you with a command prompt where you can enter various commands.

Example usage:

```
./minishell
$ ls -l
```

This will start Minishell and execute the `ls -l` command, displaying a list of files and directories in the current directory.

Minishell supports various shell functionalities, including command execution, environment variable expansion, input/output redirection, pipelines, and more. You can explore these features by entering different commands and using standard shell syntax.

## Documentation

Minishell has the following key features and considerations:

- The project uses system calls and various standard C library functions to implement shell functionalities.
- Command parsing and execution are handled through a combination of string manipulation, process management, and input/output redirection.
- Minishell provides a basic environment with built-in shell commands and supports executing external programs.
- The project implements error handling to report any encountered errors and provide feedback to the user.

For further details on the implementation, code structure, and supported features, refer to the source code comments and documentation provided within the Minishell repository.

## Credits

Minishell is the result of the collective effort of several individuals :

- [Thibault GIRAUDON (tgiraudo)](https://github.com/Thib1708)
- [Elias ZANOTTI (ezanotti)](https://github.com/eliaszanotti)
