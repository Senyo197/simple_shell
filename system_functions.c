#include "shell.h"

/**
  *_snprintf - Function for formatting and writting text to a character array
  *@str: Pointer to the character array
  *@size: Maximum number of characters to be written
  *@format: Specifies how the data should be formatted
  *Return: The number of characters written
  */
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


/**
  *_getenv - Function to get the environment variables to execute
  *@name: name of the environment variable
  *Return: nothing
  */
char *_getenv(const char *name)
{
	size_t name_len;
	char **env;

	if (name == NULL || environ == NULL)
		return (NULL);

	name_len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
			return (&(*env)[name_len + 1]);
	}

	return (NULL);
}
