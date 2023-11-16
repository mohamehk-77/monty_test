#define _GNU_SOURCE
#include "monty.h"

monty_t data_m;
/**
 * main - strting point
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode, *argument;
	stack_t *your_stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	data_m.file = fopen(argv[1], "r");
	if (!data_m.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, data_m.file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		argument = strtok(NULL, " \t\n");

		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				data_m.argument = argument;
				push(&your_stack, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&your_stack, line_number);
			}
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}

	free(line);
	fclose(data_m.file);
	return (0);
}
