#include "shell.h"

/**
  *read_command - read in command from user
  *@command: command to be read
  */
void read_command(char *command)
{
	/* Check if the end of input is reached */
	if (_feof())
	{
		printf("\n"); /* Print a new line */
		/*to visually indicate end of input */
		command[0] = '\0'; /* Clear the command buffer */
		return;
	}

	if (_fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{/* Read user input */
		perror("fgets error"); /* Print error if fgets fails */
	}
}


/**
  *remove_newline - remove trailing new lines from the command lines
  *@str: command to be entered
  */
void remove_newline(char *str)
{
	str[_strcspn(str, "\n")] = '\0'; /* Remove trailing newline */
}
