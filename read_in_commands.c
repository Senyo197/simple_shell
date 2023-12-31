#include "shell.h"

/**
  *_getline - function that reads a line from a file descriptor
  *
  *@buffer: Pointer to the buffer where the line will be stored
  *@fd: File descriptor to read from
  *@size: Maximum number of bytes to read
  *
  *Return: On success, the number of bytes read
  */

ssize_t _getline(char *buffer, size_t size, int fd)
{
	size_t pos = 0;
	char chr;

	while (read(fd, &chr, 1) > 0)
	{
		if (pos >= size - 1 || chr == '\n')
			break;
		buffer[pos++] = chr;
	}
	buffer[pos] = '\0';
	return (pos);
}


/**
  *read_command - read in command from user
  *@command: command to be read
  */
void read_command(char *command)
{
/*	char line_buffer[BUFFER_SIZE];*/
	ssize_t read_bytes;

	if (isatty(0))
	{
		print_prompt();
		read_bytes = _getline(command, MAX_COMMAND_LENGTH, 0);
	}
	else
	{
		read_bytes = _getline(command, MAX_COMMAND_LENGTH, 0);
		if (read_bytes == 0)
			exit(0);
	}


	if (read_bytes == -1)
	{
		write(2, "Getline Error\n", 14);
	}
	else if (read_bytes >= MAX_COMMAND_LENGTH)
	{
		write(2, "Command not found\n", 18);
	}
	else
		remove_newline(command);
}


/**
  *remove_newline - remove trailing new lines from the command lines
  *@str: command to be entered
  */
void remove_newline(char *str)
{
	str[_strcspn(str, "\n")] = '\0'; /* Remove trailing newline */
}

