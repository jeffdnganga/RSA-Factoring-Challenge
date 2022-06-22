#include "factors.h"

/**
 * main - entrypoint of our program
 * @argc: number of command line arguments
 * @argv: array containing command line arguments
 * Return: EXIT_SUCCESS on success and EXIT_FAULURE otherwise
 */

int main(int argc, char **argv)
{
	FILE *numbers_file = NULL;
	list_t *prime_factors = NULL;
	char *line = NULL;
	size_t n = 0;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	numbers_file = fopen(argv[1], "r");
	if (numbers_file == NULL)
	{
		printf("File Error\n");
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &n, numbers_file) != -1)
	{
		line[strlen(line) - 1] = '\0'; /* removes the trailing \n */
		prime_factors = factors(atol(line));
		print_results(line, prime_factors);
		free_list(prime_factors);
	}

	free(line);
	fclose(numbers_file);
	exit(EXIT_SUCCESS);
}

/**
 * print_results - prints the results of the prime factorization;
 * @number: number
 * @head: head of the linked list
 * Return: nothing
 */

void print_results(char *number, list_t *head)
{
	list_t *current_node = head;

	printf("%s=", number);
	while (current_node->next != NULL)
	{
		printf("%llu*", current_node->n);
		current_node = current_node->next;
	}

	printf("%llu\n", current_node->n);
}
