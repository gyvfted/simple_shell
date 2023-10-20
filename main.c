#include "shell.h"

/**
<<<<<<< HEAD
 * main - Entry point for the shell program
 *
 * Return: 0 (success)
=======
 * main - Entry point.
 * @ac: Argument counter.
 * @argv: Argument vector
 * Return: Success, or status of the non_interactive_mode
>>>>>>> 253920377c0a84ae9d178c302096056c7c92ef18
 */
int main(void)
{
	size_t size_line = 0;
	char *line = NULL;
	int status = 0;

	if (!isatty(0))
	{
		while (getline(&line, &size_line, stdin) != -1)
		{
			non_interactive_mode(line, &status);
		}
		if (line)
		{
			free(line);
			line = NULL;
		}
		return (status);
	}
	begin_shell();
	return (0);
}
/**
<<<<<<< HEAD
 * non_interactive_mode - executes shell commands in non_nteractive_mode
 * @token: string containing commands
 * @status: integer to store the number
 * Return: Status
=======
 * non_interactive_mode - Executes commands in non_interactive_mode
 * @token: String with commands separated by newline characters
 * @status: Pointer to integer that stores the exit status.
 * @argv: Argument vector.
 * Return: Exit status.
>>>>>>> 253920377c0a84ae9d178c302096056c7c92ef18
 */
void non_interactive_mode(char *token, int *status)
{
	char **single_command;
	char *envp[] = {NULL};

	token[strlen(token) - 1] = '\0';
	single_command = tokenize_string(token, " \t");
	if (single_command[0])
	{
		if (!_strcmp(single_command[0], "exit"))
		{
			if (single_command[1])
			{
				int my_status = _atoi(single_command[1]);

				handle_exit_status(my_status, single_command, &token, status);
			}
			else
			{
				free(token);
				free_array(single_command);
				exit(*status);
			}
		}
		else if (!_strcmp(single_command[0], "env"))
		{
			print_env_variable();
			*status = 0;
		}
		else
			execute_command(single_command, envp, status);
	}
	free_array(single_command);
}

/**
<<<<<<< HEAD
 * tokenize_string - Splits a string into diff tokens
 * @str: The string to tokenize
 * @delimiters: The delimiters to use for tokenization
 *
 * Return: Result
=======
 * tokenize_string - Splits the string into tokens.
 * @str: String to tokenise.
 * @delimiters: Delimiters used for tokenisation.
 *
 * Return: Result.
>>>>>>> 253920377c0a84ae9d178c302096056c7c92ef18
 */
char **tokenize_string(char *str, char *delimiters)
{
	int count = 0;
	char *token;
	char **result = malloc(20 * sizeof(char *));

	if (result == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, delimiters);
	while (token != NULL)
	{
		result[count] = _strdup(token);
		count++;
		token = strtok(NULL, delimiters);
	}
	while (count < 20)
	{
		result[count] = NULL;
		count++;
	}

	return (result);
}

