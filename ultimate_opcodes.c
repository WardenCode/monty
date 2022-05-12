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

	if (*stack && global.quantity >= 0)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;

		while (tmp->prev != NULL)
		{
			if (tmp->n > 127 || tmp->n < 0)
			{
				dprintf(STDERR_FILENO, "L%u: can't pstr, value out of range\n",
						line_number);
				free_cases(0);
				exit(EXIT_FAILURE);
			}
			if (tmp->n == 0)
				break;
			printf("%c", tmp->n);
			tmp = tmp->prev;
		}
		putchar('\n');
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pstr, stack empty\n", line_number);
		free_cases(0);
		exit(EXIT_FAILURE);
	}
}
