#include "monty.h"

/**
 * pstr - function that prints the stack like a string.
 * @stack: Double pointer to stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: void
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack && global.quantity >= 0)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;

		while (tmp->prev != NULL)
		{
			if (tmp->n > 127 || tmp->n <= 0)
				break;
			printf("%c", tmp->n);
			tmp = tmp->prev;
		}
	}
	putchar('\n');
}

/**
 * rotl - rotates the stack to the top.
 * @stack: Double pointer to stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: void
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int final = 0;

	if (*stack && global.quantity > 0)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		final = tmp->n;
		pop(stack, line_number);
		add_dnodeint(stack, final);
	}
}