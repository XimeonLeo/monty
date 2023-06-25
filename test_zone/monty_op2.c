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

/**
 * _pop - prints the element at the too of th list
 *
 * @head: pointwr to the head of the stack
 * @counter: line_number
 *
 * Return: void
 */
void _pop(stack_t **head, unsigned int counter)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = tmp->next;
	free(tmp);
}

/**
 * _swap - swaps the top to element of the stack
 *
 * @head: pointer to the head of the stack
 * @counter: line_number
 *
 * Return: void
 */
void _swap(stack_t **head, unsigned int counter)
{
	stack_t *tmp;
	int len = 0, elem;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	elem = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = elem;
}
