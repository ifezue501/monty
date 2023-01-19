#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * _pint - print the top data
 * @head: headgiven by main
 * @line_number: ammount of lines
 */
void _pint(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	tmp = *head;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}
