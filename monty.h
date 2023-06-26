#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct montyFiledetails - contains infirmation about the montyfile globally
 *
 * @file: the monty file opened
 * @args: opcode read from the file
 * @lines: each line read from the file
 * @flag: just to diff stack and queue
 *
 * Description: a structure that holds vital info
 * for the monty file opened
 */
typedef struct montyFiledetails
{
	FILE *file;
	char *args;
	char *lines;
	int flag;

} mnt_f;
extern mnt_f mnty;

/* Power house */
int runMonty(char *line, stack_t **stack, unsigned int lineNumber, FILE *file);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void freeStack(stack_t *head);
void _stack(stack_t **head, unsigned int lineNumber);
void _queue(stack_t **head, unsigned int lineNumber);
void newNode(stack_t **head, int n);
void newQueue(stack_t **head, int n);

/* Basic functions**/
void _push(stack_t **head, unsigned int lineNumber);
void _pall(stack_t **head, unsigned int lineNumber);
void _pint(stack_t **head, unsigned int lineNumber);
void _pop(stack_t **head, unsigned int lineNumber);
void _swap(stack_t **head, unsigned int lineNumber);
void _nop(stack_t **head, unsigned int lineNumber);

/* Functions that has to do with operations */
void _add(stack_t **head, unsigned int lineNumber);
void _sub(stack_t **head, unsigned int lineNumber);
void _div(stack_t **head, unsigned int lineNumber);
void _mul(stack_t **head, unsigned int lineNumber);
void _mod(stack_t **head, unsigned int lineNumber);

/* Functions that has to do with characters */
void _pchar(stack_t **head, unsigned int lineNumber);
void _pstr(stack_t **head, unsigned int lineNumber);

/* Advanced functions*/
void _rotl(stack_t **head,  __attribute__((unused)) unsigned int lineNumber);
void _rotr(stack_t **head, __attribute__((unused)) unsigned int lineNumber);

#endif
