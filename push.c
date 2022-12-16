#include <stdlib.h>
#include "main.h"

/**
 */
char *str_strip(char *str, char *str1)
{
    int idx = 0, j, k = 0;

    // Iterate String until last
    // leading space character
    while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
    {
        idx++;
    }

    // Run a for loop from index until the original
    // string ends and copy the content of str to str1
    for (j = idx; str[j] != '\0'; j++)
    {
        str1[k] = str[j];
        k++;
    }

    // Insert a string terminating character
    // at the end of new string
    str1[k] = '\0';

    // Print the string with no whitespaces
    return (str1);
}

/**
 * push - add to the top of the stack
 *
 * @head: points to the head of the stack
 * @line_number: line number in the monty file
 */
void push(stack_t **head, unsigned int line_number)
{
	if (op_arg.prop == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n");
		exit(EXIT_FAILURE);
	}

	op_arg.prop = str_strip(op_arg.prop);
}
