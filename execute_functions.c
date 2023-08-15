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
  *extract_arguments - Funtion to extract the arguments
  *@command: Argument to be extracted
  *@argv: Array of command line arguments
  *Return: total number of the argument extracted
  */
int extract_arguments(char *command, char *args[])
{
	char *arg_start = command; /* Pointer to the start of the argument */
	char *arg_end; /* Pointer to the end of the argument */
	int arg_count = 0; /* Initialize the argument count */

	/* Loop through command strings to extract arguments */
	while (*arg_start != '\0' && arg_count < MAX_ARGUMENTS - 1)
	{
		/* Skip leading spaces */
		while (*arg_start == ' ')
			arg_start++;

		/* If we reached the end of the string, break the loop */
		if (*arg_start == '\0')
			break;

		/* Find the end of the current argument */
		arg_end = arg_start;
		while (*arg_end != ' ' && *arg_end != '\0')
			arg_end++;

		/* If the end is not the end of the string, */
		/* null_terminate the argument */
		if (*arg_end != '\0')
		{
			*arg_end = '\0';
			arg_end++;
		}

		/* Storing the argument in the arg array */
		args[arg_count++] = arg_start;

		/* Moving the start pointer to the next argument */
		arg_start = arg_end;
	}
	/* Set the last element to null for execve */
	args[arg_count] = NULL;

	return (arg_count); /* Return the total number of arguments */
}
