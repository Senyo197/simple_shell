#include  "shell.h"

/**
  * execute_command - function that exe a command
  *@command: command to be entered
  *@argv: array of commands to be entered
  *Return: always 0
  */
int execute_command_line(char *command, char *argv[])
{
	int status;

	pid_t child_pid = fork();  /* Create a child process */

	if (child_pid == 0)
	{                /* Child process */
		if (execve(command, argv, environ) == -1)
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

	return (0);
}


int search_execute(char *command, char *argv[])
{
	char full_path[MAX_COMMAND_LENGTH];
	char *path_env, *path;

	path_env = getenv("PATH");
	if (path_env == NULL)
	{
		fprintf(stderr, "Path variable not set\n");
		return (1);
	}

	path = strtok(path_env, ":");
	while (path != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", path, command);

		if (access(full_path, X_OK) == 0)
		{
			execute_command_line(full_path, argv);
			return (0);
		}

		path = strtok(NULL, ":");
	}

	fprintf(stderr, "%s: No such file or directory\n", command);
	return (1);
}


int execute_command(char *command, char *argv[])
{
	if (strchr(command, '/') != NULL)
	{
		execute_command_line(command, argv);
	}
	else
	{
		if (search_execute(command, argv) != 0)
			return (1);
	}

	return (0);
}

