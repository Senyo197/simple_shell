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

	end = start + _strcspn(start, delim);
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

/**
  *_strspn - function the that gets the length of a prefix
  *         substring that matches a set of bytes
  *
  *@bytes: The set of bytes to search for
  *@@s: The string to be searched
  *
  *Return: length of the initial segment of @s that consists of
  *        only bytes from @bytes
  */

unsigned int _strspn(char *s, char *bytes)
{
	unsigned int count = 0;
	int i, j, fd;

	for (i = 0; s[i] != '\0'; i++)
	{
		fd = 0;
		for (j = 0; bytes[j] != '\0'; j++)
		{
			if (s[i] == bytes[j])
			{
				count++;
				fd = 1;
				break;
			}
		}

		if (!fd)
			break;
	}

	return (count);
}

/**
  *_strncpy - function that copys a certain number of characters
  *          from one string to another
  *
  *@n: The maximum number of characters to copy
  *@dest: The destination buffer to copy to
  *@src: The source string to copy from
  *
  *Return: pointer to the destination string @dest
  */

char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (i = 0; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
