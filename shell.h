#ifndef SHELL_H
#define SHELL_H

/* System header file */
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>

/* MACROS */
#define PROMPT ":) "
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_UNGETC_BUFFER 1
#define BUFFER_SIZE 128

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

/* System Calls */
extern char **environ;

/* Functions to read in command */
void remove_newline(char *str);
void read_command(char *command);
ssize_t _getline(char *buffer, size_t size, int fd);

/* Functions to execute command */
int execute_command_line(char *command, char *argv[]);
int search_execute(char *command, char *argv[], char *path_env);
int execute_command(char *command, char *argv[], char *path_env);

/* Functions to manipulate strings */
size_t _strcspn(const char *str, const char *reject);
int str_compare(const char *string1, const char *string2);
char *_strtok(char *str, const char *delim);
size_t _strlen(const char *str);
char *_strchr(char *s, char c);

/* System functions */
int _snprintf(char *str, ssize_t size, const char *format, ...);
int _feof(void);
int _fgetc(FILE *str);
char *_fgets(char *str, int size, FILE *stream);
int _ungetc(int c, FILE *str);

/* Parse function  */
void parse_arguments(char *command, char *args[]);
char *allocate_and_copy(const char *source);
void free_arguments(char *argv[], int count);

/* Functions to print the prompt */
void print_prompt(void);
int main(int argc, char *argv[]);

int execute_builtin(char *command, char *args[]);
ssize_t read_more(char **lineptr, size_t *n, FILE *stream);
#endif /* SHELL_H */
