#include "monty.h"

/**
 * IsDigit - Checks for a digit 0 through 9
 * Return: 0 or 1
 * @c: Variable
 **/
int IsDigit(char *c)
{
	char *aux = c;

	if (c == NULL)
		return (0);
	if (*aux == '-')
		aux++;

	for (; *aux != '\0'; aux++)
	{
		if ((*aux < '0' || *aux > '9'))
		{
			return (0);
		}
	}
	return (1);
}


/**
* len - counts numer of elements in an array
*
* @c: array
*
* Return: number of elements
*/
int len(char **c)
{
	int i = 0;

	while (c[i])
	{
		i++;
	}
	return (i);
}


/**
 * _strcmp - compares two strings
 *
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if identical
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}

	return (s1[i] - s2[i]);
}
