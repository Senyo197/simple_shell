#include "shell.h"
/**
  *free_arguments - function that frees memory allocated for
  *            an array of strings
  *@args: the array of strings to be freed
  */

void free_arguments(char *args[])
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}

	free(args);
}

/**
  *allocate_and_copy - function that allocates memory for a new
  *       string and copies the content from the source string
  *
  *@source: source string to be copied
  *
  *Return: On success, a pointer to the new string is returned.
  *         On failure, NULL is returned
  */

char *allocate_and_copy(const char *source)
{
	char *destination;

	destination = (char *)malloc(strlen(source) + 1);

	if (destination == NULL)
		perror("malloc error");

	else
		strcpy(destination, source);

	return (destination);
}
