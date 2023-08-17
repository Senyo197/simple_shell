#include  "shell.h"
/**
  * execute_command - function that exe a command
  *@command: command to be entered
  *@argv: array of commands to be entered
  *Return: always 0
  */
int execute_external_command(char *command, char *argv[])
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
