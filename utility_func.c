#include "main.h"

/**
 * free_2d_array - func to free 2 dimentional array
 * @command: arguments array
 *
 * Return: Nothing
*/
void free_2d_array(char **command)
{
	int i;
	if (command == NULL)
		return;
	for (i = 0; command[i] != NULL; i++)
		free(command[i]), command[i] = NULL;
	free(command), command = NULL;
}
