#include "monty.h"
/**
 * execute - executes the opcod
 *
 * @stack: a linked list stack
 * @counter: line_counter
 * @file: pointer to the monty file(wit .m extension)
 * @content: line content
 *
 * Return: 1, if fail
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", _push},
				{"pall", _pall},
				{"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{NULL, NULL}
				};
	size_t i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	info.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			printf("This was what was compared: %s\n", op);
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		printf("this is the issue: %s :gatcha\n", op);
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
