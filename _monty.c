#include "monty.h"

info_t info = {NULL, NULL, NULL, 0};

/**
* main - The monty code interpreter
*
* @argc: Argument count #expected to be 2
* @argv: Argument vector: to contain exec cmd and monty file location
*
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	char *monty_file_cntent;
	FILE *monty_file;
	size_t cntent_size = 0, counter = 0;
	size_t line = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	info.file = monty_file;
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line > 0)
	{
		monty_file_cntent = NULL;
		line = getline(&monty_file_cntent, &cntent_size, monty_file);
		info.content = monty_file_cntent;
		counter++;
		if (line > 0)
		{
			execute(monty_file_cntent, &stack, counter, monty_file);
		}
		free(monty_file_cntent);
	}
	free_stack(stack);
	fclose(monty_file);

	return (0);
}
