#include "monty.h"

/**
* rotr - rotates the last node of a stack_t stack
* @stack: stack head
* @line_count: line count
*
* Return: void
*/
void rotr(stack_t **stack, unsigned int line_count)
{
	stack_t *bottom_elem;
	stack_t *prev_elem;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	bottom_elem = *stack;

	while (bottom_elem->next)
		bottom_elem = bottom_elem->next;

	prev_elem = bottom_elem->prev;
	bottom_elem->next = *stack;
	bottom_elem->prev = NULL;
	prev_elem->next = NULL;
	(*stack)->prev = bottom_elem;
	*stack = bottom_elem;
}

