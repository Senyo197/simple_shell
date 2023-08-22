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
	char line_buffer[BUFFER_SIZE];
	ssize_t read_bytes = _getline(line_buffer, sizeof(line_buffer),
			STDIN_FILENO);

	if (read_bytes == -1)
		write(STDERR_FILENO, "Getline Error\n", 14);
	else if (read_bytes >= MAX_COMMAND_LENGTH)
		write(STDERR_FILENO, "Command not found\n", 18);
	else
		strncpy(command, line_buffer, MAX_COMMAND_LENGTH);
}


/**
  *remove_newline - remove trailing new lines from the command lines
  *@str: command to be entered
  */
void remove_newline(char *str)
{
	str[_strcspn(str, "\n")] = '\0'; /* Remove trailing newline */
}

/**
  *read_more - function that reads a line from a file and allocate
  *            memory dynamically
  *
  *@n: A pointer to the size of the allocated buffer
  *@stream: The file stream to read from
  *@lineptr: A pointer to a buffer that will hold the read line
  *
  *Return: number of characters read (including the newline
  *        character), or -1 if an error occurred
  *        or end of file was reached
  */

ssize_t read_more(char **lineptr, size_t *n, FILE *stream)
{
	 size_t pos = 0;
	 int ch;
	 char *new_lineptr;

	while ((ch = fgetc(stream)) != EOF)
	{
		if (pos >= *n - 1)
		{
			*n *= 2;
			new_lineptr = (char *)realloc(*lineptr, *n);

			if (new_lineptr == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*lineptr = new_lineptr;
		}

		(*lineptr)[pos++] = ch;

		if (ch == '\n')
		{
			break;
		}
	}

	if (pos == 0)
	{
		free(*lineptr);
		return (0);
	}

	(*lineptr)[pos] = '\0';
	return (pos);
}
