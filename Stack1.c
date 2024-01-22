#include "Monty.h"
/**
*mod - gets modulus of top two element
*
*@stack: pointer to list
*@line_number: line no being executed
*/
void mod(stack_t **stack, unsigned int line_number)
{
	int count = 0, temp;
	stack_t *curr = *stack;

	if (*stack)
	{
		while (curr)
		{
			curr = curr->next;
			count++;
		}
		if (count < 2)
		{
			fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
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
		(*stack)->n = (*stack)->n % temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}
/**
*pchar - prints ascii value of top element
*
*@stack: pointer to list
*@line_number: line no being executed
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack && stack)
	{
		if ((*stack)->n > 127 || (*stack)->n < 0)
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
			clear(stack);
			exit(EXIT_FAILURE);
		}
		putchar((*stack)->n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		clear(stack);
		exit(EXIT_FAILURE);
	}
}
/**
*pstr - prints string formed by list
*
*@stack: pointer to list
*@line_number: line no being executed
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
/**
*rotl - moves top element to the bottom
*
*@stack: pointer to list
*@line_number: line no being executed
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *new;
	int temp = (*stack)->n;

	if (*stack && (*stack)->next)
	{
		pop(stack, line_number);

		new = malloc(sizeof(stack_t));

		new->n = temp;
		current = *stack;
		while (current->next)
			current = current->next;

		current->next = new;
		new->prev = current;
		new->next = NULL;
	}
}
/**
*rotr - moves bottom element to the top
*
*@stack: pointer to list
*@line_number: line no being executed
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (*stack && (*stack)->next)
	{
		while (current->next)
			current = current->next;

		current->prev->next = NULL;
		current->prev = NULL;
		current->next = *stack;
		(*stack)->prev = current;
		(*stack) = current;
	}
}
