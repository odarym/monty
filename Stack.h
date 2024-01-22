#ifndef STACK_H
#define STACK_H


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;



void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int linenumber);
void swap(stack_t **stack, unsigned int linenumber);
void add(stack_t **stack, unsigned int linenumber);
void sub(stack_t **stack, unsigned int linenumber);
void _div(stack_t **stack, unsigned int linenumber);
void mul(stack_t **stack, unsigned int linenumber);
void mod(stack_t **stack, unsigned int linenumber);
void FreeList(stack_t **stack);
void pchar(stack_t **stack, unsigned int linenumber);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int linenumber);
void rotr(stack_t **stack, unsigned int line_number);
void clear(stack_t **stack);




#endif


