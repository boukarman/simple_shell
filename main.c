#include "shell.h"

/**
 * main - the entry point
 * @ac: argument count
 * @av: argument table
 *
 * Return: Nothing
*/

int main(int ac, char **av)
{
	char *line = NULL;
	char **cmd = NULL;
	int status = 0;
	int index = 0;
	(void) ac;

	while (1)
	{
		line = _getline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		index++;
		cmd = _tokenizer(line);
		if (cmd == NULL)
			continue;
		if (is_builtin(av, ac, cmd, &index, &status) == 1)
		{
			builtin_handle(av, ac, cmd, &index, &status);
		}
		else
			status = execute(cmd, av, index);
	}
}
