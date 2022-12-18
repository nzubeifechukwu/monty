#include <stdlib.h>
#include "monty.h"

/**
 * free_stack - frees the stack
 * @head: points to the head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *temp = head;

	while (head != NULL)
	{
		free(head);
		head = temp->next;
	}
}
