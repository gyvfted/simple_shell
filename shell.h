#ifndef SHELL_H
#define SHELL_H

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<stddef.h>
#include<string.h>
#include<sys/wait.h>
#include <limits.h>

extern char **environ;

void execute_command(char **cmd_args, char **env_vars, int *exit_status
		, char **agrv, int index);
int search_path(char *command, char **cmd_path);
void wait_child_process(int *exit_status);
char *mygetenv(const char *var_name);
void print_env_var(void);
void handle_getline_error(char *input_line);

/* exit_shell */
void handle_exit_status(int custom_status, char **cmd_args, char **token,
	int *exit_status);
void handle_custom_exit(int custom_status, char **cmd_args,
	char *input_line, int *exit_status);

/* shell.c */
void begin_shell(char **argv);
ssize_t read_command(char **line, size_t *line_size);
void write_error(char *name, char *command, int index);
void write_exit_error(char *number);
void free_array(char **array);

/* main */
int main(int ac, char **argv);
void non_interactive_mode(char *token, int *status, char **argv);
char **tokenize_string(char *str, char *delimiters);

/* strings */
char *_strdup(const char *src);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
#endif
