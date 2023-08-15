#include "shell.h"
/**
  *_parser - function that parses the input line
  *@input: the inputed line to parse
  */

void _parser(char *input)
{
	char *line[MAX_WORDS];
	int num_words = 0;
	char *token;
	int i;

	/* Tokenize the input line using strtok */
	token = strtok(input, " ");

	while (token != NULL && num_words < MAX_WORDS)
	{
		line[num_words++] = token;
		token = strtok(NULL, " ");
	}

	/* Print the parsed words */
	printf("Parsed words:\n");

	for (i = 0; i < num_words; i++)
		printf("%d: %s\n", i + 1, line[i]);
}
