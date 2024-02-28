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
	char **command = NULL;
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
		command = _tokenizer(line);
		if (command == NULL)
			continue;
		if (is_builtins(av, ac, command, &index, &status) == 1)
		{
			handle_builtins(av, ac, command, &index, &status);
		}
		else
			status = execute(command, av, index);
	}
}
