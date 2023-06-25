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
	int len = 0, elem;

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
	elem = tmp->n + tmp->next->n;
	tmp->next->n = elem;
	*head = tmp->next;
	free(tmp);
}

/**
  * _sub - performs the subtraction operation
  *
  * @head: pointer to the head of the stack
  * @lineNumber: current line read
  *
  * Return: void
 */
void _sub(stack_t **head, unsigned int lineNumber)
{
	stack_t *elem;
	int dif, nodes;

	elem = *head;
	for (nodes = 0; elem != NULL; nodes++)
		elem = elem->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
		fclose(mnty.file);
		free(mnty.lines);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	elem = *head;
	dif = elem->next->n - elem->n;
	elem->next->n = dif;
	*head = elem->next;
	free(elem);
}

/**
 * _div - divides the top two elements of the stack
 *
 * @head: pointer to the head of the stack
 * @lineNumber: current line read
 *
 * Return: void
 */
void _div(stack_t **head, unsigned int lineNumber)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", lineNumber);
		fclose(mnty.file);
		free(mnty.lines);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		fclose(mnty.file);
		free(mnty.lines);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	elem = tmp->next->n / tmp->n;
	tmp->next->n = elem;
	*head = tmp->next;
	free(tmp);
}

/**
 * _mul - multiplies the top two elements of the stack
 *
 * @head: pointer to the head of the stack
 * @lineNumber: current line read
 *
 * Return: void
 */
void _mul(stack_t **head, unsigned int lineNumber)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", lineNumber);
		fclose(mnty.file);
		free(mnty.lines);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	elem = tmp->next->n * tmp->n;
	tmp->next->n = elem;
	*head = tmp->next;
	free(tmp);
}

/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 *
 * @head: pointer to the head of the nodes
 * @lineNumber: the current line being read
 *
 * Return: no return
 */
void _mod(stack_t **head, unsigned int lineNumber)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", lineNumber);
		fclose(mnty.file);
		free(mnty.lines);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		fclose(mnty.file);
		free(mnty.lines);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	elem = tmp->next->n % tmp->n;
	tmp->next->n = elem;
	*head = tmp->next;
	free(tmp);
}
