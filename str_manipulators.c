#include "shell.h"

/**
  _strcspn - Calculates the initial segment of the string
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
  *str_compare - To compare two strings
  *@string1: First string to be compared
  *@string2: Second string to be compared
  *Return: 1 if strings matches, 0 otherwise
  */

int str_compare(const char *string1, const char *string2)
{
	if (string1 == NULL || string2 == NULL)
		return (0); /* Return 0 (FALSE), if any of the strings is null */

	while (*string1 != '\0' && *string2 != '\0')
	{
		if (*string1 != *string2)
			return (0); /* Return 0 (FALSE), if the characters */
		/* in the strings differ */

		string1++;
		string2++;
	}

	if (*string1 == *string2)
		return (1); /* Return 1 (TRUE), if the strings are the same */

	return (0); /* Return 0 (FALSE), if the strings are different */
}
