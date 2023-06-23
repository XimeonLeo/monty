#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

/**
 * struct info_s - contains info about the monty file
 *
 * @arg: the argument passed
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag for either stack or queue
 *
 */
typedef struct info_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  info_t;
extern info_t info;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode from the monty file and its instructions
 *
 * @opcode: the opcode from the monty file
 * @f: the function to execute the required file
 *
 * Description: opcode and its function
 * for stack, queues, FILO, LILO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void _push(stack_t **head, unsigned int counter);
void free_stack(stack_t *head);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void _queue(stack_t **head, unsigned int counter);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void _pall(stack_t **head, unsigned int counter);
void _pint(stack_t **head, unsigned int counter);
void _pop(stack_t **head, unsigned int counter);
void _swap(stack_t **head, unsigned int counter);
void _add(stack_t **head, unsigned int counter);
void _nop(stack_t **head, unsigned int counter);

#endif /* MONTY_H */
