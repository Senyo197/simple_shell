#include "shell.h"

/**
  *print_prompt - print the prompt command
  */
void print_prompt(void)
{/* Print the command prompt */
	write(1, PROMPT, sizeof(PROMPT) - 1);
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
	char *args[MAX_ARGUMENTS];
	char *path_env = _getenv("PATH");

	(void)argc;
	(void)argv;

	while (1)
	{
		read_command(command);

		parse_arguments(command, args);

		if (str_compare(command, "exit") == 1)
			return (1);

		execute_command(args[0], args, path_env);
	}

	return (0); /* Return 0 to indicate successful execution */
}
