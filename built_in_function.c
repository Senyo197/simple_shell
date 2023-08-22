#include "shell.h"
/**
  *execute_builtin - function that executes a built-in command
  *
  *@command: The command to be executed
  *
  *Return: 0 if successful execution of the built-in
  *        command, -1 otherwise
  */

int execute_builtin(char *command, char *args[])
{
	char **env_ptr;
	int exit_status;

	if(str_compare(command, "exit") == 1)
	{
		exit_status = 0;
		if (args[1] != NULL)
			exit_status = atoi(args[1]);
		exit(exit_status);
	}

	if(str_compare(command, "env") == 1)
	{
		env_ptr = environ;
		while (*env_ptr != NULL)
		{
			write(STDOUT_FILENO, *env_ptr, _strlen(*env_ptr));
			write(STDOUT_FILENO, "\n", 1);
			env_ptr++;
		}

		return (0);
	}

	return (-1);
}
