#include <stdio.h>
#include <stdlib.h>
#include <monty.h>

/**
 * main - calls the execute function for the monty interpreter
 * @ac: argument cont
 * @av: argument vectors
 *
 * Return: 0
 */
int main(int ac, char *av[])
{
	ssize_t read_line = 1;
	char *line_content = NULL;
	size_t size = 0;
	FILE *file;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		read_line = getline(&content, &size, file);
		line_number++;
		if (read_line > 0)
			execute(content, &stack, line_number, file);
		free(content);
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
