#ifndef SHELL_H
#define SHELL_H

/* System header file */
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/* MACROS */
#define PROMPT "#cisfun$ "
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

/* System Calls */
extern char **environ;

/* Functions to read in command */
void remove_newline(char *str);
void read_command(char *command);

/* Functions to print the prompt */
void print_prompt(void);
int main(int argc, char *argv[]);

/* Functions to execute command */
int execute_command(char *command, char *argv[]);

/* Functions to manipulate strings */
size_t _strcspn(const char *str, const char *reject);
int str_compare(const char *string1, const char *string2);

/* End_Of_File */
int readAndPrintFile(const char *filename);

/* For parsing inputed line */
void _parser(char *input);
#endif /* SHELL_H */
