#include "monty.h"

/**
* rotl - rotates the first element of the stack
* @stack: stack head
* @line_count: line count
*
* Return: void
*/
void rotl(stack_t **stack, unsigned int line_count)
{
	stack_t *left_hand;
	stack_t *right_hand;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	left_hand = right_hand = *stack;

	while (right_hand->next) /* move the right pointer to the last node */
		right_hand = right_hand->next;
	right_hand->next = left_hand; /* a circle infinite linked list loop */
	left_hand->prev = right_hand;
	*stack = left_hand->next; /* so we cut the link between the 0 and 1 element */
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

