

/**
  *read_command - read in command from user
  *@command: command to be read
  */
void read_command(char *command)
{
	/* Check if the end of input is reached */
	if (_feof())
	{
		printf("\n"); /* Print a new line */
		/*to visually indicate end of input */
		command[0] = '\0'; /* Clear the command buffer */
		return;
	}

	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{/* Read user input */
		perror("fgets error"); /* Print error if fgets fails */
	}
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
