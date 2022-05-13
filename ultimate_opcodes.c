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
			if (!__isascii(tmp->n) || tmp->n == 0)
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
	(void)line_number;

	if (*stack && global.quantity > 0)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		final = tmp->n;
		delete_dnodeint_at_index(stack, global.quantity);
		add_dnodeint(stack, final);
	}
}

/**
 * rotr - rotates the stack to the bottom.
 * @stack: Double pointer to stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: void
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int first = 0;
	(void)line_number;

	if (*stack && global.quantity > 0)
	{
		first = tmp->n;
		delete_dnodeint_at_index(stack, 0);
		add_dnodeint_end(stack, first);
	}
}
