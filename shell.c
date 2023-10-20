#include "shell.h"

/**
 * begin_shell - Begins shell main loop.
 * @argv: Arguments vector.
 * Description: Initialises the shell, handles user input,
 * tokenises and executes commands.
 */
void begin_shell(char **argv)
{
	char *line = NULL, **commands, *envp[] = {NULL};
	size_t line_size = 0;
	ssize_t nread;
	int status = 0, count = 0;

	while (++count)
	{
		nread = read_command(&line, &line_size);
		if (nread == -1)
			handle_getline_error(line);
		commands = tokenize_string(line, " \n\t");
		if (commands[0])
		{
			if (!_strcmp(commands[0], "exit"))
			{
				if (commands[1])
				{
					int custom_status = _atoi(commands[1]);

					handle_custom_exit(custom_status, commands, line, &status);
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
				print_env_var();
				status = 0;
			}
			else
				execute_command(commands, envp, &status, argv, count);
		}
		free_array(commands);
		free(line);
		line = NULL;
	}
}

/**
 * read_command - Reads a line of command.
 * @line: Buffer to store the command.
 * @line_size: Size of buffer.
 *
 * Return: Number of characters.
 */
ssize_t read_command(char **line, size_t *line_size)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	return (getline(line, line_size, stdin));
}

/**
 * write_error - Writes error message to STDERR.
 * @index: Execution counter.
 * @name: Error name.
 * @command: Command.
 * Description: Writes error message.
 */
void write_error(char *name, char *command, int index)
{
	char i[10] = {'\0'};

	if (index == 0)
		index = 1;

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, i, _strlen(i));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * write_exit_error - Writes exit error message to STDERR.
 *
 * @number: Number.
 * Description: Writes exit error message.
 */
void write_exit_error(char *number)
{
	write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
	write(STDERR_FILENO, number, _strlen(number));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * free_array - Frees memory allocated for array of strings.
 * @array: Pointer to dynamically allocated array of strings.
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
