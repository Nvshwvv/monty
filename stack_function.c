#include "monty.h"


/**
 * add_to_stack - Adds a node to the stack.
 * @newnode: Pointer to the new node.
 * @ln: Interger representing the line number
 */
void add_to_stack(stack_t **newnode, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (newnode == NULL || *newnode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newnode;
		return;
	}
	tmp = head;
	head = *newnode;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer
 * @line_number: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
