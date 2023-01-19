#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * _sub - substracts the first two nodes of the stack
 * @head: head given by main
 * @line_number: line number
 * 
 */
void _sub(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int result, count;

	tmp = *head;
	for (count = 0; tmp != NULL; count++)
		tmp = tmp->next;
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	result = tmp->next->n - tmp->n;
	tmp->next->n = result;
	(*head) = tmp->next;
	free(tmp);
}

