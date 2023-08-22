#include "shell.h"

/**
  *print_prompt - print the prompt command
  */
void print_prompt(void)
{/* Print the command prompt */
	write(STDOUT_FILENO, PROMPT, sizeof(PROMPT) - 1);
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
	char *path_env = getenv("PATH");


	(void)argc;
	(void)argv;

	if (path_env == NULL)
	{
		write(STDERR_FILENO, "PATH environment variable not set\n", 33);
		return (1);
	}

	while (1)
	{
		print_prompt();

		read_command(command);
		remove_newline(command);

		if (str_compare(command, "exit") == 1)
			break;
		parse_arguments(command, args);
/**
*		if (!execute_builtin(command))
*		{
*
*		arg_count = parse_arguments(command, args);
*/
		if (args[0] != NULL)
			execute_command(args[0], args, path_env);
/*		}*/
	}

	return (0); /* Return 0 to indicate successful execution */
}
