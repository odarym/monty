#include "monty.h"



/**
* FreeList - frees a list
*
* @stack: pointer to list
*/
void FreeList(stack_t **stack)
{
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = (*stack)->next;
		free(current);
	}
}


/**
* clear - frees list and closes file
*
* @stack: pointer to list
*/
void clear(stack_t **stack)
{
	FreeList(stack);
	fclose(global.fd);
}
