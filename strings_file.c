#include "shell.h"

/**
 * _strlen - the length of string
 * @str: string
 *
 * Return: string length
*/
int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * _strdup - a copy of string
 * @line: line to copy
 *
 * Return: string
*/
char *_strdup(char *line)
{
	char *line_copy = NULL;
	int i;

	if (line == NULL)
		return (NULL);
	line_copy = malloc(sizeof(char) * (_strlen(line) + 1));
	if (line_copy == NULL)
		return (NULL);
	for (i = 0; line[i] != '\0'; i++)
		line_copy[i] = line[i];
	line_copy[i] = '\0';
	return (line_copy);
}

/**
 * _strcpy - copy a string from source to destination including
 * the null byte (\0)
 * @dest: destination character array
 * @src: source characters array
 *
 * Return: characters array
 */
char *_strcpy(char *dest, char *src)
{
	char *orig_dest, *orig_src;

	orig_dest = dest;
	orig_src = src;
	for (; *orig_src != '\0'; orig_src++, orig_dest++)
		*orig_dest = *orig_src;
	*orig_dest = '\0';
	return (dest);
}
/**
 * _strcat - func to concatenate two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: concatenation result
 */
char *_strcat(char *dest, char *src)
{
	char *dest_copy, *src_copy;

	dest_copy = dest, src_copy = src;
	for (; *dest_copy != '\0'; dest_copy++)
		;
	for (; *src_copy != '\0'; src_copy++, dest_copy++)
	{
		*dest_copy = *src_copy;
	}
	*dest_copy = '\0';
	return (dest);
}
