#include "shell.h"

/**
  *parse_arguments - function that parse a command string into
  *                  arguments
  *
  *@command: the command to be parsed
  *@args: an array of store the parsed arguments
  *Return: always 0
  */

void parse_arguments(char *command, char *args[])
{
	int arg_count = 0;
	char *token;

	token = strtok(command, " ");

	while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
	{
		remove_newline(token);
		args[arg_count++] = token;
		token = strtok(NULL, " ");

	}

	args[arg_count] = NULL;
}
