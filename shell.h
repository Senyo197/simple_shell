#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


#define PROMPT ">> "
#define MAX_COMMAND_LENGTH 100

extern char **environ;

void remove_newline(char *str);
int main(int argc, char *argv[]);
void print_prompt(void);
void read_command(char *command);
int execute_command(char *command, char *argv[]);

size_t _strcspn(const char *str, const char *reject);
int str_compare(const char *string1, const char *string2);

#endif /* SHELL_H */
