#include "shell.h"

/**
<<<<<<< HEAD
 * handle_exit_status - Handles the exit status for a command
 * @my_status: status to be checked
 * @single_command:  command arguments
 * @token: A pointer to the allocated memory
 * @status: A pointer to hold the status value.
=======
 * handle_exit_status - Handles exit status for a command.
 * @custom_status:  Status to handle.
 * @cmd_args: Command arguments.
 * @token: Pointer to dynamically allocated memory.
 * @exit_status: Pointer to integer to hold the exit status value.
>>>>>>> 253920377c0a84ae9d178c302096056c7c92ef18
 *
 * Return: Void.
 */
void handle_exit_status(int my_status, char **single_command, char **token,
						int *status)
{
	if (my_status == -1 ||
		(my_status == 0 && single_command[1][0] != '0') ||
		my_status < 0)
	{
		write_exit_error(single_command[1]);
		*status = 2;
	}
	else
	{
		free(*token);
		free_array(single_command);
		exit(my_status);
	}
}

/**
<<<<<<< HEAD
 * handle_custom_exit - Handles custom exit statuses for a command
 * @my_status:  exit status to be checked
 * @commands:  array containing the command and its arguments
 * @line:  pointer to the input line
 * @status:  pointer to an int to hold the return status value
=======
 * handle_custom_exit - Handles  exit statuses for a command.
 * @custom_status:  Exit status to handle.
 * @cmd_args: Command and its arguments.
 * @input_line:  Pointer to input line.
 * @exit_status: Pointer to integer to hold the return exit status value.
>>>>>>> 253920377c0a84ae9d178c302096056c7c92ef18
 *
 * Return: Void.
 */
void handle_custom_exit(int my_status, char **commands,
						char *line, int *status)
{
	if (my_status == -1 ||
		(my_status == 0 && commands[1][0] != '0') ||
		my_status < 0)
	{
		write_exit_error(commands[1]);
		*status = 2;
	}
	else
	{
		free(line);
		free_array(commands);
		exit(my_status);
	}
}
/**
<<<<<<< HEAD
 * handle_getline_error - Handles getline error
 * @line: A pointer to the input line
 *
 * Return: void
=======
 * handle_getline_error - Handles getline error.
 * @input_line: Pointer to input line.
 *
 * Return: Void.
>>>>>>> 253920377c0a84ae9d178c302096056c7c92ef18
 */
void handle_getline_error(char *line)
{
	perror("getline");
	free(line);
	line = NULL;
	exit(EXIT_FAILURE);
}

