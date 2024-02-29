#include "main.h"

/**
 * _strtoint - convert string to integer
 * @n: integer
 *
 * Return: converted integer
 */
char *_strtoint(int n)
{
	char buffer[20];
	int i = 0, j, len, n_copy;
	char tmp;

	if (n == 0)
		return (_strdup("0"));
	n_copy = n;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (n_copy < 0)
		buffer[i++] = '-';
	buffer[i] = '\0';
	len = i - 1;
	i = 0, j = len;
	while (i < j)
	{
		tmp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = tmp;
		i++;
		j--;
	}
	return (_strdup(buffer));
}
/**
 * print_error - print error
 * @av: argument array
 * @cmd: command
 * @index: index
 *
 * Return: nothing
*/
void print_error(char **av, char *cmd, int index)
{
	char *str_index = NULL;

	str_index =  _itoa(index);
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str_index, _strlen(str_index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
	free(str_index);
}
/**
 * _strtoint - func convert string to integer
 * @s: string
 *
 * Return: converted integer
 */
int _strtoint(char *s)
{
	int minus, plus, sign, len, multi, result;
	char *slen;

	minus = 0, plus = 0, len = 0, multi = 1, result = 0;
	while ((*s < 48 || *s > 57) && *s != '\0')
	{
		if (*s == '-')
			minus++;
		else if (*s == '+')
			plus++;
		s++;
	}
	if (*s == '\0')
	{
		result = 0;
	}
	else
	{
		sign = (minus % 2 != 0) ? -1 : 1;
		slen = s;
		while (*slen >= 48 && *slen <= 57)
		{
			len++;
			slen++;
		}
		while (len > 1)
		{
			multi *= 10;
			len--;
		}
		while (multi != 1)
		{
			result += multi * ((*s) - 48) * sign;
			s++;
			multi /= 10;
		}
		result = result + ((*s) - 48) * sign;
	}
	return (result);
}

/**
 * is_number - checking if string is integer
 * @str: string
 *
 * Return: 1 if number or 0 if not
*/
int is_number(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}
