#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * _push - push element into the stack
 * @stack: head of a stack  given by main
 * @line_number: ammount of lines
 */
void _push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (buf.arg)
	{
		if (buf.arg[0] == '-')
			j++;
		for (; buf.arg[j] != '\0'; j++)
		{
			if (buf.arg[j] > 57 || buf.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(buf.file);
			free(buf.command);
			free_dlist(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(buf.file);
		free(buf.command);
		free_dlist(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(buf.arg);
	if (buf.flag == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
