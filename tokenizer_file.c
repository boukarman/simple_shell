#include "shell.h"
#define DELIM " \n\t"

/**
 * _tokenizer - func to parse a string
 * @line: line to parse
 *
 * Return: commands table
*/

char **_tokenizer(char *line)
{
	char *line_copy = NULL;
	char *token = NULL;
	char **cmd = NULL;
	int len = 0, i;

	if (line == NULL)
		return (NULL);
	line_copy = _strdup(line);
	token = strtok(line_copy, DELIM);
	if (token == NULL)
	{
		free(line_copy), line_copy = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	while (token)
	{
		len++;
		token = strtok(NULL, DELIM);
	}
	free(line_copy), line_cpy = NULL;
	cmd = malloc(sizeof(char *) * (len + 1));
	if (cmd == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token  = strtok(line, DELIM);
	i = 0;
	while (token)
	{
		cmd[i++] = _strdup(token);
		token = strtok(NULL, DELIM);
	}
	cmd[i] = NULL;
	free(line), line = NULL;
	return (cmd);
}
