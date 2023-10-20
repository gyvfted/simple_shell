#include "shell.h"

/**
<<<<<<< HEAD
 * begin_shell - Starts the shell's main loop
 *
 * Description: Initializes the shell, handles user input,
 * tokenizes cmds and executes them.
 * Return: Void
=======
 * begin_shell - Begins shell main loop.
 * @argv: Arguments vector.
 * Description: Initialises the shell, handles user input,
 * tokenises and executes commands.
>>>>>>> 253920377c0a84ae9d178c302096056c7c92ef18
 */
void begin_shell(void)
{
	char *line = NULL, **commands, *envp[] = {NULL};
	size_t size_line = 0;
	ssize_t nread;
	int status = 0;

	while (1)
	{
		nread = read_command(&line, &size_line);
		if (nread == -1)
			handle_getline_error(line);
		commands = tokenize_string(line, " \n\t");
		if (commands[0])
		{
			if (!_strcmp(commands[0], "exit"))
			{
				if (commands[1])
				{
					int my_status = _atoi(commands[1]);

					handle_custom_exit(my_status, commands, line, &status);
				}
				else
				{
					free(line);
					free_array(commands);
					exit(status);
				}
			}
			else if (!_strcmp(commands[0], "env"))
			{
				print_env_variable();
				status = 0;
			}
			else
				execute_command(commands, envp, &status);
		}
		free_array(commands);
		free(line);
		line = NULL;
	}
}


/**
<<<<<<< HEAD
 * read_command - Reads a line of command from the user
 * @line: Line buffer to be stored command
 * @size_line: Size of line buffer
 *
 * Return: The number of char to read.
=======
 * read_command - Reads a line of command.
 * @line: Buffer to store the command.
 * @line_size: Size of buffer.
 *
 * Return: Number of characters.
>>>>>>> 253920377c0a84ae9d178c302096056c7c92ef18
 */
ssize_t read_command(char **line, size_t *size_line)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	return (getline(line, size_line, stdin));
}
/**
<<<<<<< HEAD
 * write_error - Writes an error message to STDERR
 *
 * @command: The command
 * Description: Writes an error message
=======
 * write_error - Writes error message to STDERR.
 * @index: Execution counter.
 * @name: Error name.
 * @command: Command.
 * Description: Writes error message.
>>>>>>> 253920377c0a84ae9d178c302096056c7c92ef18
 */
void write_error(char *command)
{
	write(STDERR_FILENO, "./hsh: 1: ", 10);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
}
/**
<<<<<<< HEAD
 * write_exit_error - Writes an error message to STDERR
 *
 * @number: The number
 * Description: Writes an error message
=======
 * write_exit_error - Writes exit error message to STDERR.
 *
 * @number: Number.
 * Description: Writes exit error message.
>>>>>>> 253920377c0a84ae9d178c302096056c7c92ef18
 */
void write_exit_error(char *number)
{
	write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
	write(STDERR_FILENO, number, _strlen(number));
	write(STDERR_FILENO, "\n", 1);
}
/**
<<<<<<< HEAD
 * free_array - Frees memory allocated for an array of strings
 * @array: Pointer to the allocated array of strings
=======
 * free_array - Frees memory allocated for array of strings.
 * @array: Pointer to dynamically allocated array of strings.
>>>>>>> 253920377c0a84ae9d178c302096056c7c92ef18
 */
void free_array(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
}
