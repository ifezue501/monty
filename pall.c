#include "monty.h"

/**
 * _pall - prints the stack
 * @stack: head of stack given by main
 * @line_number: ammount of lines
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;
	tmp = *head;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
