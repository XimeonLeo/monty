#include "monty.h"

/**
 * runMonty - handles all function (the power house)
 *
 * @stack: the head of the stack linked list
 * @lineNumber: the current line number
 * @file: poiner to monty file
 * @line: current line read
 *
 * Return: void
 */
int runMonty(char *line, stack_t **stack, unsigned int lineNumber, FILE *file)
{
	instruction_t opst[] = {
				{"push", _push},
				{"pall", _pall},
				{"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{NULL, NULL}
				};
	size_t i = 0;
	char *op;

	op = strtok(line, " \n\t");
	if (op && op[0] == '#')
		return (0);
	mnty.args = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, lineNumber);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, op);
		fclose(file);
		free(line);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
