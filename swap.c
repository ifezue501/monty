#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * _swap - swaps data from top to previous
 * @head: head given by main
 * @line_number: ammount of line
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int num;

	tmp = *head;
	if(tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = num;

}

