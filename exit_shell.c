#include "shell.h"

/**
 * handle_exit_status - Handles the exit status for a command
 * @custom_status:  status to check
 * @cmd_args: command arguments
 * @token: pointer to dynamically allocated memory
 * @exit_status: pointer to an int to hold the exit status value
 *
 * Return: void.
 */
void handle_exit_status(int custom_status, char **cmd_args, char **token,
		int *exit_status)
{
	if (custom_status == -1 ||
		(custom_status == 0 && cmd_args[1][0] != '0') ||
		custom_status < 0)
	{
		write_exit_error(cmd_args[1]);
		*exit_status = 2;
	}
	else
	{
		free(*token);
		free_array(cmd_args);
		exit(custom_status);
	}
}

/**
 * handle_custom_exit - Handles  exit statuses for a command
 * @custom_status:  exit status to check
 * @cmd_args: array containing the command and its arguments
 * @input_line:  pointer to the input line
 * @exit_status:  pointer to an int to hold the return exit status value
 *
 * Return: void.
 */
void handle_custom_exit(int custom_status, char **cmd_args,
		char *input_line, int *exit_status)
{
	if (custom_status == -1 ||
		(custom_status == 0 && cmd_args[1][0] != '0') ||
		custom_status < 0)
	{
		write_exit_error(cmd_args[1]);
		*exit_status = 2;
	}
	else
	{
		free(input_line);
		free_array(cmd_args);
		exit(custom_status);
	}
}

/**
 * handle_getline_error - Handles getline error
 * @input_line: pointer to the input line.
 *
 * Return: void.
 */
void handle_getline_error(char *input_line)
{
	perror("getline");
	free(input_line);
	input_line = NULL;
	exit(EXIT_FAILURE);
}
