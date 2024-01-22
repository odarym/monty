#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Stack.h"
#include "String.h"

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - global variables
 * @fd: File descriptor
 * @line: Line to getline
 * @element: element to add when pushing
 *
 * Description: To handle the file and getline
 */
typedef struct globals
{
	FILE *fd;
	char *line;
	int element;
} globals_t;

extern globals_t global;


char **parser(char *buffer);
void OpcodeMapper(char **command, unsigned int line_number, stack_t **head);

#endif
