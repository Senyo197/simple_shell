#include "shell.h"
#include <stdio.h>
/**
  *readAndPrintFile - a function that reads a line by line and
  *                 prints its contents.
  *@filename: The name of the file to be read
  *Return: 0 if the operation was successful, otherwise a
  *        on-zero value
  */

int readAndPrintFile(const char *filename)
{
	FILE *file;
	char line[256];

	file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Failed to open the file.\n");
		return (1);
	}

	while (!feof(file))
	{
		if (fgets(line, sizeof(line), file) != NULL)
			prinft("%s", line);
	}

	fclose(file);

	return (0);
}
