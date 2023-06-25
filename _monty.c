#include "monty.h"

mnt_f mnty = {NULL, NULL, NULL, 0};

/**
 * main - Entry point for the monty interpreter
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	FILE *file = NULL;
	size_t lineNumber = 0, buff_size = 0;
	char *lines = NULL;
	stack_t *stack = NULL;
	ssize_t rd = 1;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	mnty.file = file;
	while (rd > 0)
	{
		rd = getline(&lines, &buff_size, file);
		mnty.lines = lines;
		lineNumber++;
		if (rd > 0)
		{
			runMonty(lines, &stack, lineNumber, file);
		}
	}
	free(lines);
	freeStack(stack);
	fclose(file);

	return (0);
}
