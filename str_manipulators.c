#include "shell.h"

/**
 * _strcspn - Calculates the initial segment of the string
  *@str: string to be calculated
  *@reject: specifies characters
  *that are not allowed to appear in the initial segment
  *Return: The length of the initial segment of the string
  */
size_t _strcspn(const char *str, const char *reject)
{
	const char *string1 = str, *string2;
	size_t count = 0;

	/* Iterate through the characters in 'str' */
	while (*string1)
	{
		string2 = reject; /* Set string2 to the beginning of */
							/*reject for each character in 'str' */

		/* Iterate through the characters in 'reject' */
		while (*string2)
		{
			/* Incase the characters match, return the count */
			if (*string1 == *string2)
				return (count);

			string2++; /* Move to the next character in 'reject' */
		}
		string1++; /* Move to the next character in 'str' */
		count++; /* Increment the count of the characters checked */
	}

	return (count); /* Return the final count,*/
	/* which is the length of the final segment of the initial string */
}




/**
  *_strlen - function that calculates the length of a string
  *@str: the string
  *Return: The length of the string
  */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}


/**
  *_strchr - function that locate a character in a string
  *
  *@c: The character to be located
  *@s: Pointer to the string to be searched
  *Return: Pointer to the first occurrence of the character c
  *        or NULL if the character is not found
  */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	if (*s == c)
		return (s);

	return (NULL);
}


/**
  *_strncmp - Compares two strings
  *@s1: first string
  *@s2: Second string
  *@n: Maximum number of characters to be compared
  *Return: Difference between non-matching characters
  */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}

	if (n == 0)
		return (0);
	else
		return (*s1 - *s2);
}
