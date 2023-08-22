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


int _snprintf(char *str, ssize_t size, const char *format, ...)
{
	int written = 0, i = 0, j;
	char *arg_str;

	va_list args;
	va_start(args, format);

	if (str == NULL || format == NULL || size == 0)
		return (-1);

	while (format[i] != '\0' && written < size - 1)
	{
		if (format[i] == '%' && format[i + 1] == 's')
		{
			arg_str = va_arg(args, char *);
			if (arg_str != NULL)
			{
				j = 0;
				while (arg_str[j] != '\0' && written < size - 1)
				{
					str[written++] = arg_str[j++];
				}
			}
			i += 2;
		}
		else
		{
			str[written++] = format[i++];
		}
	}
	str[written] = '\0';
	va_end(args);
	return (written);
}
