#include "monty.h"

/**
 * mod - computes the rest of division of second element by the top element
 * @stack: pointer to the stack
 * @line_number: number of lines
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		a = (*stack)->n;
		b = (*stack)->next->n % a;
		(*stack)->next->n = b;
		pop(stack, line_number);
	}
}
