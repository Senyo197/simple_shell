#include  "shell.h"
/**
  * execute_command - function that exe a command
  *@command: command to be entered
  *@argv: array of commands to be entered
  *Return: always 0
  */

int execute_command(char *command, char *argv[])
{
	int status;

	pid_t child_pid = fork();  /* Create a child process */

	if (child_pid == 0)
	{                /* Child process */
		if (execve(command, argv, environ) == -1)
		{       /* Execute the command */
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
			_exit(1);  /* Exit the child process */
		}
	}
	else if (child_pid > 0)
	{  /* Parent process */
		if (waitpid(child_pid, &status, 0) == -1)
		{  /* Wait for child process */
			perror("waitpid error");  /* Print error if waitpid fails */
		}
	}
	else
	{
		perror("Fork error");  /* Print error if fork fails */
	}

	return (0);
}

/**
  *parse_arguments - function that parse a command string into
  *                  arguments
  *
  *@command: the command to be parsed
  *@args: an array of store the parsed arguments
  *Return: always 0
  */

int parse_arguments(char *command, char *args[])
{
	char *token;
	int arg_count;

	arg_count = 0;
	token = strtok(command, " ");

	while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
	{
		remove_newline(token);
		args[arg_count++] = token;
		token = strchr(token, ' ');

		if (token != NULL)
		{
			*token != '\0';
			token++
		}
	}

	args[arg_count] = NULL;

	return (arg_count);
}
