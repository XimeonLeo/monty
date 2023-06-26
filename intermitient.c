#include "monty.h"
/**
 * _rotl- rotates the stack left
 *
 * @head: pointer to the head of the atavk
 * @lineNumber: currwnt line reaf
 *
 * Return: void
 */
void _rotl(stack_t **head,  __attribute__((unused)) unsigned int lineNumber)
{
	stack_t *tmp = *head, *newHead;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	newHead = (*head)->next;
	newHead->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = newHead;
}

/**
 * _rotr- rotates the stack right
 *
 * @head: pointer to the head of the stack
 * @lineNumber: currwnt line read
 *
 *Return: void
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int lineNumber)
{
	stack_t *tmp;

	tmp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*head)->prev = tmp;
	(*head) = tmp;
}


