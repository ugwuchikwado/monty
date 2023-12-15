#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * _add -  adds the first two nodes of the stack
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_cnt)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	res = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_cnt); /*For top node*/
	(*stack)->n = res;
}

