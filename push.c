#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - add to the top of the stack
 *
 * @head: points to the head of the stack
 * @line_number: line number in the monty file
 */
void push(stack_t **head, unsigned int line_number)
{
	int i = 0;
	stack_t *new_node;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		if (*head != NULL)
			free_stack(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (arg[i] != '\0')
		{
			if (arg[i] < 48 || arg[i] > 57)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				if (*head != NULL)
					free_stack(head);
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (*head != NULL)
			free_stack(head);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(arg);
	if (*head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
	}
}
