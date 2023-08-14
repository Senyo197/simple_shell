#include "shell.h"

/**
  *read_command - read in command from user
  *@command: command to be read
  */
void read_command(char *command)
{
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{/* Read user input */
		if (feof(stdin))
		{
			printf("\n"); /* Print a new line */
			/*to visually indicate end of input */
		}
		else
		{
			perror("fgets error"); /* Print error if fgets fails */
		}
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
