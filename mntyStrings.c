#include "monty.h"
/**
 * _pchar - cinverts the element at the top of tne stack to a char
 *
 *
 * @head: pointer to the head of the stack
 * @lineNumber: current line read
 *
 * Return: void
 */
void _pchar(stack_t **head, unsigned int lineNumber)
{
	stack_t *tmp;

	tmp = *head;
	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
		fclose(mnty.file);
		free(mnty.lines);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	if (tmp->n > 127 || tmp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
		fclose(mnty.file);
		free(mnty.lines);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}

/**
 * _pstr - creates a string by converting each elements from the top
 * into a character then a newline
 *
 * @head: pointer to the head of the stack
 * @lineNumber: current line read
 *
 * Return: void
 */
void _pstr(stack_t **head, unsigned int lineNumber)
{
	stack_t *tmp;
	(void)lineNumber;

	tmp = *head;
	while (tmp)
	{
		if (tmp->n > 127 || tmp->n <= 0)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
