#include "shell.h"

/**
 * execute - func execute commands
 * @command: commands
 * @av: arguments
 * @index: line index
 *
 * Return: the status
*/
int execute(char **command, char **av, int index)
{
	pid_t fork_result;
	int status = 0;
	char *path = NULL;

	path = _getpath(command[0]);
	if (path == NULL)
	{
		error_print(av, command[0], index);
		free(path), path = NULL;
		free_2d_array(cmd), cmd = NULL;
		return (127);
	}
	fork_result = fork();

	if (fork_result == 0)
	{
		if (execve(path, command, environ) == -1)
		{
			perror(av[0]);
			free_2d_array(cmd), path = NULL;
			free(path), path = NULL;
			return (127);
		}
	}
	else
	{
		waitpid(fork_result, &status, 0);
		free_2d_array(cmd), cmd = NULL;
		free(path), path = NULL;
	}
	return (WEXITSTATUS(status));
}
