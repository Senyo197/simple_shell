#include  "shell.h"

/**
  *execute_command_line - function that exe a command
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
			write(2, "execve error\n", 13);
			_exit(1);  /* Exit the child process */
		}
	}
	else if (child_pid > 0) /* Parent process */
	{ /* Wait for child process */
		if (waitpid(child_pid, &status, 0) == -1)
		{  /* Print error if waitpid fails */
			write(2, "waitpid error\n", 14);
		}
	}
	else
	{ /* Print error if fork fails */
		write(2, "Fork error\n", 11);
	}

	return (0);
}


/**
  *search_execute - Search for path to execute
  *@command: Command to be executed
  *@argv: Array of command line arguments
  *@path_env: path environment to be searched
  *Return: 0 for successful execution, 1 for otherwise
  */
int search_execute(char *command, char *argv[], char *path_env)
{
	char full_path[MAX_COMMAND_LENGTH];
	char *path;

	path = _strtok(path_env, ":");
	while (path != NULL)
	{
		_snprintf(full_path, sizeof(full_path), "%s/%s", path, command);

		if (access(full_path, X_OK) == 0)
		{
			execute_command_line(full_path, argv);
			return (0);
		}

		path = _strtok(NULL, ":");
	}

	write(2, "No such file or directory\n", 26);
	return (1);
}

/**
  *execute_command - Function to execute the command
  *@command: Command to be executed
  *@argv: Array of command line arguments
  *@path_env: path environment to be searched
  *Return: 0 for successful execution, 1 for otherwise
  */
int execute_command(char *command, char *argv[], char *path_env)
{
	if (_strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			execute_command_line(command, argv);
		else
			write(2, "Command not found or not executable\n", 36);
	}
	else
	{
		search_execute(command, argv, path_env);
	}

	return (0);
}

