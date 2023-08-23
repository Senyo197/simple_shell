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
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": No such file or directory\n", 28);
			_exit(1);  /* Exit the child process */
		}
	}
	else if (child_pid > 0) /* Parent process */
	{ /* Wait for child process */
		if (waitpid(child_pid, &status, 0) == -1)
		{  /* Print error if waitpid fails */
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": waitpid error\n", 17);
		}
	}
	else
	{ /* Print error if fork fails */
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": Fork error\n", 13);
	}

	return (0);
}


