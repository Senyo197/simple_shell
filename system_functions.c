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
