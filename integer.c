#include "monty.h"

/**
 * is_integer - Checks if a valid integer
 * @str: check input
 * Return: 1 if is a valid integer, 0 otherwise
 */
int is_integer(const char *str)
{
	if (!str || *str == '\0' || (*str == '-' && *(str + 1) == '\0'))
	{
		return (0);
	}

	for (; *str; str++)
	{
		if (*str != '-' && (*str < '0' || *str > '9'))
		{
			return (0);
		}
	}

	return (1);
}
