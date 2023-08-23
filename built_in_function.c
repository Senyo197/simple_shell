#include "shell.h"

/**
  *execute_builtin - function that executes a built-in command
  *
  *@command: The command to be executed
  *
  *@args: Array of  character of arguments
  *
  *Return: 0 if successful execution of the built-in
  *        command, -1 otherwise
  */

int execute_builtin(char *command, char *args[])
{
	int exit_status;

	if (str_compare(command, "exit") == 1)
	{
		exit_status = 0;
		if (args[1] != NULL)
			exit_status = _atoi(args[1]);
		exit(exit_status);
	}

	return (-1);
}
