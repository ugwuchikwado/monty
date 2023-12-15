#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
* pop - removes the very top element of the stack
* @stack: stack given by main in start.c
* @line_cnt: line number for error messages
*
* Return: void
*/
void pop(stack_t **stack, unsigned int line_cnt)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: operation not possible,  empty stack\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (!*stack)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack)->prev = NULL;
}

