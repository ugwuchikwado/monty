#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * queue_node - adds a node to a stack_t stack in queue_node
 * @stack: stack head
 * @n: number of the node
 *
 * Return: newly created node, if memory allocation fails, the function will
 * return NULL.
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *current_node = *stack;

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}
	new_node->n = n;

	if (!*stack)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
		return (new_node);
	}

	while (current_node)
	{
		if (!current_node->next)
		{
			new_node->next = NULL;
			new_node->prev = current_node;
			current_node->next = new;
			break;
		}
		current_node = current_node->next;
	}

	return (new_node);
}

/**
 * add_node - adds a node to the start of a stack_t stack
 * @stack: stack head
 * @n: number for the new node
 *
 * Return: newly created node, if creation fails, the
 * function will return NULL.
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		return (NULL);
	}
	new_node->n = n;

	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;

	return (new_node);
}

/**
 * print_stack - prints the contents of a stack_t stack
 * @stack: stack head
 *
 * Return: number of elements of the list
 */
size_t print_stack(const stack_t *stack)
{
	size_t s = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		s++;
	}

	return (s);
}

/**
 * free_stack - frees a dlistint_t linked list
 * @stack: list head
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current_node = stack;
	stack_t *next_node;

	if (stack)
	{
		next_node = stack->next;
		while (current_node)
		{
			free(current_node);
			current_node = next_node;
			if (next_node)
				next_node = next_node->next;
		}
	}
}

