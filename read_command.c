#include "shell.h"


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
