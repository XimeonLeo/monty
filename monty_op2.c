#include "monty.h"

/**
 * _pall - prints the entire elements in the stack
 *
 * @head: head node of the stack
 * @counter: not needed for this operation
 *
 * Return: void
*/
void _pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * _pint - prints the stavk at the top
 *
 * @head: pointer to head of stack
 * @counter: line_number
 *
 * Return: void
*/
void _pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
