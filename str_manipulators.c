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


