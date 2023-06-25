#include "monty.h"

/**
 * _push - add a new node to the topof the stack
 *
 * @head: pointer to the head of the stack
 * @lineNumber: the current line read
 *
 * Return: void
*/
void _push(stack_t **head, unsigned int lineNumber)
{
	int elem, itr = 0;
	int flag = 0;

	if (mnty.args)
	{
		if (mnty.args[0] == '-')
			itr++;
		for (; mnty.args[itr] != '\0'; itr++)
		{
			if (mnty.args[itr] > 57 || mnty.args[itr] < 48)
				flag = 1; }
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
			fclose(mnty.file);
			free(mnty.lines);
			freeStack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
		fclose(mnty.file);
		free(mnty.lines);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	elem = atoi(mnty.args);
	if (mnty.flag == 0)
		newNode(head, elem);
	else
		newQueue(head, elem);
}

/**
 * _pall - prints out all element in a stack on a new line
 *
 * @head: pointer to the head of the stack
 * @lineNumber: the current line read
 *
 * Return: void
 */
void _pall(stack_t **head, unsigned int lineNumber)
{
	stack_t *tmp;
	(void)lineNumber;

	tmp = *head;
	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pint - prints the element at the top if the queue
 *
 * @head: pointer to the head of the stack
 * @lineNumber: the current line read
 *
 * Return: void
 */
void _pint(stack_t **head, unsigned int lineNumber)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineNumber);
		fclose(mnty.file);
		free(mnty.lines);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * _pop - returns the element at the top of the queue
 *
 * @head: pointer to the head of the stack
 * @lineNumber: the current line read
 *
 * Return: void
 */
void _pop(stack_t **head, unsigned int lineNumber)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineNumber);
		fclose(mnty.file);
		free(mnty.lines);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = tmp->next;
	free(tmp);
}

/**
 * _swap - switches the top two elements in a stack
 *
 * @head: pointer to the head of the stack
 * @lineNumber: the current line read
 *
 * Return: void
 */
void _swap(stack_t **head, unsigned int lineNumber)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineNumber);
		fclose(mnty.file);
		free(mnty.lines);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	elem = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = elem;
}
