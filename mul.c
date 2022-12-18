#include "monty.h"

/**
 * mul - multiplies the second element with the top element
 * @stack: pointer to the stack
 * @line_number: number of lines
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		a = (*stack)->n;
		b = (*stack)->next->n * a;
		(*stack)->next->n = b;
		pop(stack, line_number);
	}
}
