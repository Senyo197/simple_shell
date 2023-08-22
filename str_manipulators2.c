#include "shell.h"

char *_strtok(char *str, const char *delim)
{
	static char *last = NULL;
	char *start, *end;

	if (str != NULL)
		last = str;

	if (last == NULL || *last == '\0')
		return (NULL);

	start = last + strspn(last, delim);
	if (*start == '\0')
	{
		last = NULL;
		return (NULL);
	}

	end = start + strcspn(start, delim);
	if (*end == '\0')
	{
		last = NULL;
	}
	else
	{
		*end = '\0';
		last = end + 1;
	}

	return (start);
}
