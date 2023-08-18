#include "shell.h"

/**
  *print_prompt - print the prompt command
  */
void print_prompt(void)
{
	printf("%s", PROMPT); /* Print the command prompt */
}


/**
  *main - Display a shell prompt
  *@argc: number of command line arguments
  *@argv: array of command line arguments
  *Return: 0 success
  */
int main(int argc, char *argv[])
{
	char *args[MAX_ARGUMENTS];
	char command[MAX_COMMAND_LENGTH];

	int arg_count;

	(void)argc;
	(void)argv;

	while (1)
	{
		print_prompt();

		read_command(command);
		remove_newline(command);

		if (str_compare(command, "exit") == 1)
			break;

		arg_count = parse_arguments(command, args);
		if (arg_count > 0)
			execute_command(args[0], args);
	}

	return (0); /* Return 0 to indicate successful execution */
}
