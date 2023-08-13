#include "shell.h"

/**
  *print_prompt - print the prompt command
  */
void print_prompt(void)
{
	printf("%s", PROMPT); /* Print the command prompt */
}

/**
  *read_command - read in command from user
  *@command: command to be read
  */
void read_command(char *command)
{
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{ /* Read user input */
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

/**
  *main - Display a shell prompt
  *@argc: number of command line arguments
  *@argv: array of command line arguments
  *Return: 0 success
  */
int main(int argc, char *argv[])
{
	char command[MAX_COMMAND_LENGTH];
	(void)argc;

	while (1)
	{
		print_prompt();

		read_command(command);
		remove_newline(command);

		if (str_compare(command, "exit") == 1)
			break;

		execute_command(command, argv);
	}

	return (0); /* Return 0 to indicate successful execution */
}
