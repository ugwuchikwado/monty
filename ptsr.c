#include "monty.h"

/**
 * pstr - prints the contents of a stack_t stack as a string
 * @stack: stack given by main
 * @line_cnt: line counter for error messages
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	stack_t *current_node = *stack;

	while (current_node)
	{
		if (current_node->n <= 0 || current_node->n > 127)
			break;
		putchar((char) current_node->n);
		current_node = current_node->next;
	}
	putchar('\n');
}

