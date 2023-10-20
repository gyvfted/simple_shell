#include "shell.h"

/**
 * handle_exit_status - Handles exit status for a command.
 * @custom_status:  Status to handle.
 * @cmd_args: Command arguments.
 * @token: Pointer to dynamically allocated memory.
 * @exit_status: Pointer to integer to hold the exit status value.
 *
 * Return: Void.
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
 * handle_custom_exit - Handles  exit statuses for a command.
 * @custom_status:  Exit status to handle.
 * @cmd_args: Command and its arguments.
 * @input_line:  Pointer to input line.
 * @exit_status: Pointer to integer to hold the return exit status value.
 *
 * Return: Void.
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
 * handle_getline_error - Handles getline error.
 * @input_line: Pointer to input line.
 *
 * Return: Void.
 */
void handle_getline_error(char *input_line)
{
	perror("getline");
	free(input_line);
	input_line = NULL;
	exit(EXIT_FAILURE);
}
