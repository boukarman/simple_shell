#include "main.h"

/**
 * free_2d_array - func to free 2 dimentional array
 * @command: arguments array
 *
 * Return: Nothing
*/
void free_2d_array(char **cmd)
{
	int i;
	if (cmd == NULL)
		return;
	for (i = 0; cmd[i] != NULL; i++)
		free(cmd[i]), cmd[i] = NULL;
	free(cmd), cmd = NULL;
}

/**
 * _strncmp - compare if two strings are equal
 * @str1: string number 1
 * @str2: string number 2
 * @n: length
 *
 * Return: 0 if equal or 1 if not
*/
int _strncmp(char *str1, char *str2, int n)
{
	if (str1 == NULL || str2 == NULL)
		return (-1);
	while (n > 0)
	{
		if (*str1 != *str2 || *str1 == '\0' || *str2 == '\0')
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
/**
 * _strcmp - compare two values
 * @str1: string number 1
 * @str2: string number 2
 *
 * Return: 0 if equal or n if not
*/
int _strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
/**
 * _getenv - get envirment value
 * @name: envirement variable name
 *
 * Return: pointer to the value or NULL value
*/
char *_getenv(char *name)
{
	int len, i;

	if (name == NULL)
		return (NULL);
	len = _strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
			return (_strdup(&environ[i][len + 1]));
	}
	return (NULL);
}
/**
 * _getpath - get the path
 * @cmd: command
 *
 * Return: path or NULL
*/
char *_getpath(char *cmd)
{
	char *token = NULL, *env = NULL, *path = NULL;
	struct stat st;
	int i;

	if (cmd == NULL)
		return (NULL);
	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	env = _getenv("PATH");
	if (env == NULL)
		return (NULL);
	token = strtok(env, ":");
	while (token)
	{
		path = malloc(sizeof(char) * (_strlen(token) + _strlen(cmd) + 2));
		if (path == NULL)
		{
			free(env), env = NULL;
			return (NULL);
		}
		_strcpy(path, token);
		_strcat(path, "/");
		_strcat(path, cmd);
		if (stat(path, &st) == 0)
		{
			free(env), env = NULL;
			return (path);
		}
		token = strtok(NULL, ":");
		free(path), path = NULL;
	}
	free(env), env = NULL;
	return (NULL);
}
