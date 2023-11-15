#include "monty.h"

/**
 * push - Push the element into the stack.
 * @stack: Double pointer
 * @line_number: Line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node_n;
	int value;

	if (!stack)
	{
		fprintf(stderr, "L%u: stack is NULL\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (data_m.argument == NULL || !is_integer(data_m.argument))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(data_m.argument);
	node_n = malloc(sizeof(stack_t));

	if (!node_n)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node_n->n = value;
	node_n->prev = NULL;
	node_n->next = *stack;

	if (*stack)
	{
		(*stack)->prev = node_n;
	}
	*stack = node_n;
}
