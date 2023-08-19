#ifndef SHELL_H
#define SHELL_H

/* System header file */
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/* MACROS */
#define PROMPT ":) "
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_UNGETC_BUFFER 1

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

/* System Calls */
extern char **environ;

/* Functions to read in command */
void remove_newline(char *str);
void read_command(char *command);

/* Functions to execute command */
int execute_command_line(char *command, char *argv[]);
int search_execute(char *command, char *argv[]);
int execute_command(char *command, char *argv[]);

/* Functions to manipulate strings */
size_t _strcspn(const char *str, const char *reject);
int str_compare(const char *string1, const char *string2);

/* System functions */
int _feof(void);
int _fgetc(FILE *str);
char *_fgets(char *str, int size, FILE *stream);
int _ungetc(int c, FILE *str);

/* Parse function  */
int parse_arguments(char *command, char *args[]);
char *allocate_and_copy(const char *source);
void free_arguments(char *argv[], int count);

/* Functions to print the prompt */
void print_prompt(void);
int main(int argc, char *argv[]);

int execute_builtin(char *command);
#endif /* SHELL_H */
