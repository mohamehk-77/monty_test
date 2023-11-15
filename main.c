#include "monty.h"

monty_t data_m;

/**
 * main - starting point
 * @argv: 1 argument
 * @argc: 2 arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "monty file\n");
		exit(EXIT_FAILURE);
	}

	data_m.file = fopen(argv[1], "r");
	if (!data_m.file)
	{
		fprintf(stderr, "Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fclose(data_m.file);
	return (0);
}
