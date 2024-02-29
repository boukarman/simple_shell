#include "main.h"

/**
 * is_builtin - check if build in
 * @command: command
 * @index: line inde
 * @av: argument table
 * @status: status
 * @ac: argument count
 *
 * Return: 1 if builtin or 0 if not
*/
int is_builtin(char **av, int ac, char **cmd, int *index, int *status)
{
	char *builtin[] = {"exit", "env", NULL};
	int i;
	(void)av;
	(void)status;
	(void)index;
	(void)ac;

	for (i = 0; builtin[i] != NULL; i++)
	{
		if (_strcmp(builtin[i], cmd[0]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * builtin_handle - handle build
 * @cmd: command table
 * @index: line index
 * @av: argument table
 * @status: status
 * @ac: argument count
 *
 * Return: 1 if builtin or 0 if not
*/
void builtin_handle(char **av, int ac, char **cmd, int *index, int *status)
{
	(void)av;
	(void)index;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		exit_builtin(av, ac, cmd, status, index);
	}
	else if (_strcmp(cmd[0], "env") == 0)
		_print_env(cmd, status);
}
/**
 * print_env - print env content
 * @status: status
 * @command: command array
 *
 * Return: nothing
*/
void print_env(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	*status = 0;
	free_2d_array(cmd), cmd = NULL;
}

/**
 * builtin_exit - exit builtin
 * @av: argument array
 * @ac: argument count
 * @command: command array
 * @status: status
 * @index: index
 *
 * Return: nothing
*/
void builtin_exit(char **av, int ac, char **cmd, int *status, int *index)
{
	int len = 0, n;
	(void)ac;

	while (cmd[len])
		len++;
	if (len >= 2)
	{
		n = _strtoint(cmd[1]);
		if (is_number(cmd[1]) && n >= 0)
		{
			*status = _strtoint(cmd[1]) % 256;
			free_2d_array(cmd), cmd = NULL;
			exit(*status);
		}
		else
		{
			exit_error(av, index, cmd);
			free_2d_array(cmd), cmd = NULL;
			*status = 2;
			return;
		}
	}
	else
	{
		free_2d_array(cmd);
		exit(*status);
	}
}

/**
 * exit_error - print exit error
 * @av: array argument
 * @index: index
 * @command: command array
 *
 * Return: nothing
*/
void exit_error(char **av, int *index, char **cmd)
{
	char *str_index = NULL;

	str_index =  _itoa(*index);
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str_index, _strlen(str_index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd[0], _strlen(cmd[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "Illegal number", 14);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
	write(STDERR_FILENO, "\n", 1);
	free(str_index);

}
