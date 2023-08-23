#include "shell.h"

/**
  *_atoi - Change string to integer
  *@str: String to be changed
  *Return: Integer
  */
int _atoi(const char *str)
{
	int result = 0, sign = 1, i = 0;

	while (str[i] == ' ')
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;

		i++;
	}

	for (; str[i] >= '0' && str[i] <= '9'; i++)
		result = result * 10 + (str[i] - '0');

	return (result * sign);

}
