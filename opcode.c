#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * opcode - function in charge of running builtins
 * @head: head given by main
 * @count: line_counter
 * @file: poiner to monty file
 * @command: line content
 * Return: nothing
 */

int exec_op(string command, stack_t **head, unsigned int count, FILE *file)
{
	string delim = " \n\t";
	unsigned int i = 0;
	string c_op;

	/*Declaring the opcodes struct*/
	instruction_t opt[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{NULL, NULL}
	};
	/*Tokenzing the commands args to be executed */
	c_op = strtok(command, delim);
	if (c_op && c_op[0] == '#')
		return (0);
	buf.arg = strtok(NULL, delim);
	while (opt[i].opcode && c_op)
	{
		if (strcmp(c_op, opt[i].opcode) == 0)
		{
			opt[i].f(head, count);
			return (0);
		}
		i++;
	}
	if (c_op && !opt[i].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, c_op);
		fclose(file);
		free(command);
		free_dlist(*head);
		exit(EXIT_FAILURE);
	}
	return (1);


}

