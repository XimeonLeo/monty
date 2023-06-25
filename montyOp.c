#include "monty.h"

/**
 * freeStack - frees a node in a stack or queue
 *
 * @head: head of the stack
 *
 * Return: void!
 */
void freeStack(stack_t *head)
{
	stack_t *tmp;

	tmp = head;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * newNode - add a new node to the head stack
 *
 * @head: pointer to the head of the stack
 * @n: element held by new node
 *
 * Return: (void)!
 */
void newNode(stack_t **head, int n)
{
	stack_t *new_node, *tmp;

	tmp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (tmp)
		tmp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * _queue - prints the top of the queue
 *
 * @head: pointer to the head of the queue
 * @lineNumber: current line number
 *
 * Return: void
 */
void _queue(stack_t **head, unsigned int lineNumber)
{
	(void)head;
	(void)lineNumber;
	mnty.flag = 1;
}

/**
 * newQueue - add a new element to the end of the queue
 *
 * @n: element contained in the new node
 * @head: pointer to the head of the queue
 *
 * Return: void
 */
void newQueue(stack_t **head, int n)
{
	stack_t *new_node, *tmp;

	tmp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!tmp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tmp->next = new_node;
		new_node->prev = tmp;
	}
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
