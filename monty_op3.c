#include "monty.h"

/**
 * _queue - returns the top of the stack
 *
 * @head: pointer to the head of the stack
 * @counter: line_number
 *
 * Return: void
 */
void _queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	info.lifi = 1;
}

/**
 * addqueue - add a new node to the end of the stack
 *
 * @n: element of the new stack
 * @head: pointer to the head of the stack
 *
 * Return: void
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *elem;

	elem = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (elem)
	{
		while (elem->next)
			elem = elem->next;
	}
	if (!elem)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		elem->next = new_node;
		new_node->prev = elem;
	}
}

/**
 *_add - adds the top two elements of the stack
 * @head: pointer to head of the stack
 * @counter: line_number
 *
 * Return: void
 */
void _add(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	elem = tmp->n + tmp->next->n;
	tmp->next->n = elem;
	*head = tmp->next;
	free(tmp);
}

/**
 *_nop- does nothing
 *
 *@head: pointer to the head of stack
 *@counter: line_number
 *
 *Return: void
 */
void _nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
