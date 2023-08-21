#include "shell.h"
/**
  *execute_builtin - function that executes a built-in command
  *
  *@command: The command to be executed
  *
  *Return: 0 if successful execution of the built-in
  *        command, -1 otherwise
  */

int execute_builtin(char *command)
{
	char **env_ptr;

	if(str_compare(command, "env") == 1)
	{
		env_ptr = environ;
		while (*env_ptr != NULL)
		{
			printf("%s\n", *env_ptr);
			env_ptr++;
		}
	}

	return (0);
}
