#include "shell.h"


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

	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
