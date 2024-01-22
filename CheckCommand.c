#include "Monty.h"

/**
* CheckCommand - checks if command exist
*
* @command: array of commands
*
* Return: true or false
*/
bool CheckCommand(char **command)
{
	int i = 0;
	char *array[] = {"push", "pall", "pint", "pop", "nop", "swap",
	"add", "sub", "div", "mul", "mod", "pchar", "pstr", "rotl", "rotr", NULL};

	while (array[i])
	{
		if (_strcmp(array[i], command[0]) == 0)
			return (false);
		i++;
	}

	return (true);
}
