#include "Monty.h"


/**
* swap - swaps top two elements
*
* @stack: pointer to list
* @line_number: line no being executed
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int count = 0, temp;
	stack_t *curr = *stack;

	if (curr)
	{
		while (curr)
		{
			curr = curr->next;
			count++;
		}
		if (count < 2)
		{
			fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
			clear(stack);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}


/**
* add - adds top two elements
*
* @stack: pointer to list
* @line_number: line no being executed
*/
void add(stack_t **stack, unsigned int line_number)
{
	int count = 0, temp;
	stack_t *curr = *stack;

	if (curr)
	{
		while (curr)
		{
			curr = curr->next;
			count++;
		}
		if (count < 2)
		{
			fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
			clear(stack);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n = temp + (*stack)->n;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}


/**
* sub - subtracts top two element
*
* @stack: pointer to list
* @line_number: line no being executed
*/
void sub(stack_t **stack, unsigned int line_number)
{
	int count = 0, temp;
	stack_t *curr = *stack;

	if (curr)
	{
		while (curr)
		{
			curr = curr->next;
			count++;
		}
		if (count < 2)
		{
			fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
			clear(stack);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n = (*stack)->n - temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}



/**
* _div - divides top two element
*
* @stack: pointer to list
* @line_number: line no being executed
*/
void _div(stack_t **stack, unsigned int line_number)
{
	int count = 0, temp;
	stack_t *curr = *stack;

	if (curr)
	{
		while (curr)
		{
			curr = curr->next;
			count++;
		}
		if (count < 2)
		{
			fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
			clear(stack);
			exit(EXIT_FAILURE);
		}
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			clear(stack);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n = (*stack)->n / temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}



/**
* mul - multiplies top two element
*
* @stack: pointer to list
* @line_number: line no being executed
*/
void mul(stack_t **stack, unsigned int line_number)
{
	int count = 0, temp;
	stack_t *curr = *stack;

	if (curr)
	{
		while (curr)
		{
			curr = curr->next;
			count++;
		}
		if (count < 2)
		{
			fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
			clear(stack);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n = temp * (*stack)->n;
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}

