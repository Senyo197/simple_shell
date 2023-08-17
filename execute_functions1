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
	char executable[MAX_COMMAND_LENGTH];

	pid_t child_pid;

	if (search_executable(command, executable))
	{
		child_pid = fork();  /* Create a child process */

		if (child_pid == 0)
		{                /* Child process */
			if (execve(executable, argv, environ) == -1)
			{       /* Execute the command */
				perror("execve error");
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


int search_executable(char *command, char *executable)
{
	char *path = getenv("PATH");
	char *start, *end;
	size_t dir_len, command_len;

	if (path == NULL)
	{
		perror("NO PATH variable set");
		return (0);
	}

	start = path;
	while (*start != '\0')
	{
		end = strchr(start, ':');
		if (end == NULL)
			end = start + strlen(start);


		dir_len = (size_t)(end - start);
		command_len = strlen(command);
		if (dir_len + 1 + command_len + 1 <= MAX_COMMAND_LENGTH)
		{
			snprintf(executable, MAX_COMMAND_LENGTH, "%.*s/%s",
					(int)dir_len, start, command);

			if (access(executable, X_OK) == 0)
				return (1);
		}

		if (*end == '\0')
			end = start + dir_len;

		start = end + 1;
	}

	fprintf(stderr, "Command not found: %s\n", command);
	return (0);
}
