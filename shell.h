#ifndef SHELL_H
#define SHELL_H

/* System header file */
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>

/* MACROS */
#define PROMPT ":) "
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define BUFFER_SIZE 128

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
int _strncmp(const char *s1, const char *s2, size_t n);
size_t _strcspn(const char *str, const char *reject);
int str_compare(const char *string1, const char *string2);
char *_strtok(char *str, const char *delim);
size_t _strlen(const char *str);
char *_strchr(char *s, char c);
char *_strncpy(char *dest, const char *src, size_t n);
unsigned int _strspn(const char *s, const char *bytes);

/* System functions */
char *_getenv(const char *name);
int _snprintf(char *str, ssize_t size, const char *format, ...);

/* Parse function  */
void parse_arguments(char *command, char *args[]);

/* Functions to print the prompt */
void print_prompt(void);
int main(int argc, char *argv[]);

/* Function to execute built_in(s) */
int execute_builtin(char *command, char *args[]);

/* Change string to integer function */
int _atoi(const char *str);

#endif /* SHELL_H */
