#include "monty.h"

/**
 * _push - add a new node to the top of the stack
 *
 * @head: head of the stack
 * @counter: line_number
 *
 * Return: void
 */
void _push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (info.arg)
	{
		if (info.arg[0] == '-')
			j++;
		for (; info.arg[j] != '\0'; j++)
		{
			if (info.arg[j] > 57 || info.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(info.file);
			free(info.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(info.arg);
	if (info.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
* free_stack - frees a the node(top node)
*
* @head: pointer to the head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}

/**
 * addnode - add a new node to the top of the stack
 *
 * @head: pointer to the head of the stack
 * @n: value the new node will hold
 *
 * Return: void
 */
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

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
 * @n: element held by the new node
 * @head: pointer to the head of the stack
 *
 * Return: void
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
