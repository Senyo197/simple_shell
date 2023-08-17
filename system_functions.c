#include "shell.h"

/**
  *_feof - a function that indicates end of file
  *Return: 1 if the operation was successful, 0 if otherwise
  */

int _feof(void)
{
	int c = fgetc(stdin); /* Pass the user input to c */

	/* Checks if the c is end of file */
	if (c == EOF)
		return (1); /* Returns 1 if the c is end of file */
	else
	{
		ungetc(c, stdin);/* Put the c in the stream */
		return (0); /* Input is not at the end */
	}
}

/**
  *_fgetc - function that reads a text line or a string
  *         from the specified file
  *@str: the text line to read
  *Return: The next character from the stream,
  *        or EOF if end-of-file or an error occurs
  */

int _fgetc(FILE *str)
{
              /* if there are characters in the unget buffer, retrieve and return one */
	if (ungetc_index > 0)
		return (ungetc_buffer[--ungetc_index]);

	else
	{
		return (getchar()); /* If unget buffer is empty, read from standard input */
	}
}

/**
  *_ungetc - function that takes a single character and
  *              shoves back onto an input stream
  *
  *@c: character to be pushed back
  *@str: the pointer to the FILE structure
  */

int _ungetc(int c, FILE *str)
{       /* If there's space in the unget buffer, add the character to it */
	if (ungetc_index < MAX_UNGETC_BUFFER)
	{
		ungetc_buffer[ungetc_index++] = c;
		return (c);
	}

	else
	{
		return (EOF); /*  Buffer is full, cannot unget more characters */
	}
}

/**
  *_fgets - function that reads a line from a file stream
  *
  *@string: the pointer to the buffer where the line will be stored
  *@size: Maximum number of characters to read
  *@stream: pointer to file stream to read from
  *
  *Return: On success, returns the string, If no characters are read and
  *         EOF is reached, or if an error occurs, returns NULL
  */

char *_fgets(char *str, int size, FILE *stream)
{
	int i;
	int read_BufferSize;
	int read_BufferIndex;
	char c;
            /* if there's space in the unget buffer, add the character to it */
	if (read_BufferIndex >= read_BufferSize)
	{
		 read_BufferSize = fread(my_read_buffer, 1, MAX_COMMAND_LENGTH, stream);
		 read_BufferIndex = 0;
	}

	i = 0;

	while (i < size - 1 && read_BufferIndex < read_BufferSize)
	{
               /* Read a character from the read buffer */
		c = my_read_buffer[read_BufferIndex++];
               /* Copy the character to the output string */
		str[i++] = c;

		if (c == '\n')
			break;
	}
	str[i] = '\0';

	return (i > 0 ? str : NULL);
}
