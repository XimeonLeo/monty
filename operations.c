#include "monty.h"

/**
 * _add - adds the top two elments in a stack
 *
 * @head: pointer to the head of the stack
 * @lineNumber: currwnt line being read
 *
 * Return: void
 */
void _add(stack_t **head, unsigned int lineNumber)
{
	stack_t *tmp;
	int len = 0, aux;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNumber);
		fclose(mnty.file);
		free(mnty.lines);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	aux = tmp->n + tmp->next->n;
	tmp->next->n = aux;
	*head = tmp->next;
	free(tmp);
}

/**
  *_nop - nothing serious, does nothing
  *
  *@head: pointer to the head of the stack
  *@lineNumber: currwnt line being read
  *
  *Return: void
 */
void _nop(stack_t **head, unsigned int lineNumber)
{
	(void) lineNumber;
	(void) head;
}
