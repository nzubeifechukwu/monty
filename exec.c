#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * execute - executes the opcode
 * @head: points to the head of the stack
 * @file: points to the monty file
 * @line_num: line number in the monty file
 * @content: content of the line number
 */
void execute(stack_t **head, FILE *file, unsigned int line_num, char *content)
{
	instruction_t op_ins[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	char *op_arg, *op;
	unsigned int i = 0;

	op_arg = str_strip(content);
	op = strtok(op_arg, " ");

	if (op != NULL && op[0] == '#')
		return;
	arg = strtok(NULL, "");

	while (op_ins[i].opcode != NULL && op != NULL)
	{
		if (strcmp(op_ins[i].opcode, op) == 0)
		{
			op_ins[i].f(*head, line_num);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
	fclose(file);
	free(content);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
