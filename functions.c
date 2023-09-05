#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * push - add
 * @stack: pointer
 * @line_number: integer
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;

	if (scanf(" %d ", &value) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * pall - print all
 * @stack: pointer
 *
 */
void pall(stack_t **stack)
{
	if (*stack == NULL)
	{
		return;
	}

	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d ", current->n);
		current = current->next;
	}

	printf("\n");
}
