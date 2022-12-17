#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: number of lines
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*stack)->next;
		temp->next = *stack;
		temp->prev = NULL;
		(*stack)->next = temp->next;
		(*stack)->prev = temp;
		(*stack)->next->prev = *stack;
		*stack = temp;
	}
}
