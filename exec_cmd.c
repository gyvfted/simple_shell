#include "shell.h"

/**
 * execute_command - execute a shell cmd
 * and its arguments by searching in PATH
 * @cmd_args: the cmd and its arguments as an array of strings
 * @env_vars: the environment var
 * @exit_status: the pointer to an int where the exit status will be stored
 * @argv: the program argument
 * @index: the execution count
 */
void execute_command(char **cmd_args, char **env_vars
		, int *exit_status, char **argv, int index)
{
	char *cmd_path = NULL;
	int child_pid;

	if (access(cmd_args[0], X_OK) == 0)
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			execve(cmd_args[0], cmd_args, env_vars);
		}
		else
		{
			wait_child_process(exit_status);
		}
	}
	else if (search_path(cmd_args[0], &cmd_path))
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			execve(cmd_path, cmd_args, env_vars);
		}
		else
		{
			wait_child_process(exit_status);
		}

		free(cmd_path);
	}
	else
	{
		*exit_status = 127;
		write_error(argv[0], cmd_args[0], index);
	}
}

/**
 * search_path - look for the full path of a command
 * in the PATH environment variable
 * @command:command to search for
 * @cmd_path: A Pointer to store the full path of the command
 *
 * Return: 1 (success), 0 (failure)
 */
int search_path(char *command, char **cmd_path)
{
	char *token, *path_env;
	int found = 0;

	path_env = mygetenv("PATH");

	if (path_env != NULL)
	{
		char *path_env_copy = strdup(path_env);

		token = strtok(path_env_copy, ":");

		while (token != NULL && !found)
		{
			*cmd_path = malloc(strlen(token) + strlen(command) + 2);
			if (*cmd_path != NULL)
			{
				strcpy(*cmd_path, token);
				strcat(*cmd_path, "/");
				strcat(*cmd_path, command);

				if (access(*cmd_path, X_OK) == 0)
				{
					found = 1;
				}

				if (!found)
				{
					free(*cmd_path);
				}
			}

			token = strtok(NULL, ":");
		}

		free(path_env_copy);
	}

	return (found);
}

/**
 * wait_child_process - waits for a child process to end
 * and gets its exit status
 * @exit_status: A  Pointer to the exit status
 * variable to store the exit status
 */
void wait_child_process(int *exit_status)
{
	int child_status;

	if (wait(&child_status) == -1)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}

	if (WIFEXITED(child_status))
	{
		*exit_status = WEXITSTATUS(child_status);
	}
}

/**
 * mygetenv - looks for an environment var
 * @var_name: name of the environment var to look for
 *
 * Return: A Pointer to the value of the environment variable,
 * or NULL if not found
 */
char *mygetenv(const char *var_name)
{
	int i;
	int name_length = _strlen((char *)var_name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (!strncmp(var_name, environ[i], name_length))
		{
			if (environ[i][name_length] == '=')
			{
				return (environ[i] + name_length + 1);
			}
		}
	}

	return (NULL);
}

/**
 * print_env_var - Prints the environment variables to stdout
 *
 * Return: void
 */
void print_env_var(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

