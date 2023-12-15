#include "monty.h"

/**
 * _mul - divides the next top value by the top value
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_cnt)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}

	res = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_cnt);/*For top node*/
	(*stack)->n = res;
}

