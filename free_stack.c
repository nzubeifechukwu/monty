#include <stdlib.h>
#include "monty.h"

/**
 * free_stack - frees the stack
 * @head: points to the head of the stack
 */
void free_stack(stack_t **head)
{
	stack_t *temp;
	stack_t *current;

	if (head != NULL)
	{
		current = *head;
	}
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*head = NULL;
}
