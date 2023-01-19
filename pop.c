#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * _pop - removes the top element o d11
 * @head: head of d11 
 * @line_number: line number for error messages
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	tmp = *head;
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*head = tmp->next;
	if(*head)
		(*head)->prev = NULL;
	free(tmp);
}
