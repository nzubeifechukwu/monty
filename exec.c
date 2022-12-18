#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

char *arg = "0"; /* this holds the int part of the opcode */

/**
 * execute - executes the opcode
 * @head: points to the head of the stack
 * @file: points to the monty file
 * @line_num: line number in the monty file
 * @content: content of the line number
 */
void execute(stack_t **stack, FILE *file, unsigned int line_num, char *content)
{
	instruction_t op_ins[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
	       	{NULL, NULL}
	};
	char *op;
	unsigned int i = 0;

	op = strtok(content, " \n\t");

	if (op != NULL && op[0] == '#')
		return;
	arg = strtok(NULL, " \n\t");

	while (op_ins[i].opcode != NULL && op != NULL)
	{
		if (strcmp(op_ins[i].opcode, op) == 0)
		{
			op_ins[i].f(stack, line_num);
			return;
		}
		i++;
	}
	if (op_ins[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
		fclose(file);
		free(content);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
