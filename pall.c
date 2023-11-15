#include "monty.h"
/**
 * pall - prints all the values on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: line of number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *main_ptr = *stack;
	(void)line_number;

	for (main_ptr = *stack; main_ptr != NULL; main_ptr = main_ptr->next)
	{
		printf("%d\n", main_ptr->n);
	}
}
