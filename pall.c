#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the stack
 * @line_number: number of lines
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
