# Basic C++ Windows Terminal
This is a simple Windows terminal application written in C++. It provides several basic commands like ls, cd, mkdir, rmdir, touch, rm, echo, help, and exit.
# Usage
The program accepts command-line arguments, which are passed to the main function. If no arguments are provided, the program starts in interactive mode.

# Interactive mode
In interactive mode, the program displays a prompt (> ), and waits for the user to enter a command.

# Supported commands are:

ls - List files in the current directory
pwd - Print the current working directory
cd <path> - Change the current working directory to <path>
mkdir <directory> - Create a new directory with the specified name
rmdir <directory> - Remove a directory with the specified name
touch <file> - Create a new file with the specified name
rm <file> - Remove a file with the specified name
echo <message> - Display a message on the console
help - Display a help message
exit - Quit the program
Non-interactive mode
In non-interactive mode, the program executes a single command specified as a command-line argument.
