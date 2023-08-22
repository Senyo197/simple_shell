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
			write(STDERR_FILENO, "execve error\n", 13);
			_exit(1);  /* Exit the child process */
		}
	}
	else if (child_pid > 0)
	{  /* Parent process */
		if (waitpid(child_pid, &status, 0) == -1)
		{  /* Wait for child process */
			write(STDERR_FILENO, "waitpid error\n", 14);  /* Print error if waitpid fails */
		}
	}
	else
	{
		write(STDERR_FILENO, "Fork error\n", 11);  /* Print error if fork fails */
	}

	return (0);
}


int search_execute(char *command, char *argv[], char *path_env)
{
	char full_path[MAX_COMMAND_LENGTH];
	char *path;

	path = _strtok(path_env, ":");
	while (path != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", path, command);

		if (access(full_path, X_OK) == 0)
		{
			execute_command_line(full_path, argv);
			return (0);
		}

		path = _strtok(NULL, ":");
	}

	write(STDERR_FILENO, "No such file or directory\n", 26);
	return (1);
}


int execute_command(char *command, char *argv[], char *path_env)
{
	if (_strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			execute_command_line(command, argv);
		else
			write(STDERR_FILENO, "Command not found or not executable\n", 36);
	}
	else
	{
		search_execute(command, argv, path_env);
	}

	return (0);
}

