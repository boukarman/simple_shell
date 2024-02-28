#include "shell.h"

/**
 * read_line - get command line
 *
 * Return: the number of read characters or -1
*/
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	int num_char = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	num_char = getline(&line, &len, stdin);
	if (num_char == -1)
	{
		free(line), line = NULL;
		return (NULL);
	}
	return (line);
}
