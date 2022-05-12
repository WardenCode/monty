#include "monty.h"

/**
 * pall - Print a stack.
 *
 * @stack: Double pointer to the stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: Void.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack)
		print_dlistint(*stack);
}

/**
 * push - Add a node at the head of the linked list.
 *
 * @stack: Double pointer to the stack.
 *
 * @line_number: Number of line of the monty file.
 *
 * Return: Void.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int num = 0;

	if (global.tokens[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_cases(0);
		exit(EXIT_FAILURE);
	}

	if (is_a_num(global.tokens[1]))
	{
		num = atoi(global.tokens[1]);
		new_node = add_dnodeint_end(stack, num);
		global.quantity++;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_cases(0);
		exit(EXIT_FAILURE);
	}
}
