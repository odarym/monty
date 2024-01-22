#include "Monty.h"

globals_t global;

int main(int argc, char **argv)
{
	FILE *f;
	char *line, **command;
	size_t buffersize = 0;
	unsigned int line_number = 1;
	stack_t *head = NULL;
	(void) global;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	global.fd = f;
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &buffersize, f) != -1)
	{
		global.line = line;
		command = parser(line);
		if (command == NULL)
			continue;
		if (command[0][0] == '#')
			continue;
		if (CheckCommand(command))
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, command[0]);
			fclose(f);
			exit(EXIT_FAILURE);
		}
		OpcodeMapper(command, line_number, &head);
		line_number++;
	}
	free(command);
	FreeList(&head);
	fclose(f);
	return (0);
}


/**
* parser- parses the commmand input
*
* @buffer: string containing command
*
* Return: Parsed command
*/
char **parser(char *buffer)
{
	char **cmd, *token;
	int i;

	if (buffer == NULL)
		return (NULL);

	token = strtok(buffer, " \t\n\r");
	if (token == NULL)
		return (NULL);

	cmd = malloc(sizeof(char *) * 1024);

	if (cmd == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		fclose(global.fd);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (token)
	{
		cmd[i++] = token;
		token = strtok(NULL, " \t\r\n");
	}
	cmd[i] = NULL;
	return (cmd);
}

