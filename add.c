#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * _add -  adds the first two nodes of the stack
 * @head: head given by main
 * @line_number: line counter
 */
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int len;
	int sum;

	tmp = *head;
	len = 0;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (head == NULL ||(*head)->next == NULL || len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		fclose(buf.file);
		free(buf.command);
		free_dlist(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	sum = tmp->n + tmp->next->n;
	tmp->next->n = sum;
	*head = tmp->next;
	free(tmp);

}

