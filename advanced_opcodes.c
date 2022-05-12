#include "monty.h"

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: Double pointer to stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack && global.quantity >= 1)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->prev->n -= tmp->n;
		pop(stack, line_number);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		free_cases(0);
		exit(EXIT_FAILURE);
	}
}

/**
 * _div - divides the second top element of the stack by the top element.
 * @stack: Double pointer to stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack && global.quantity >= 1)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (tmp->n == 0)
		{
			dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
			free_cases(0);
			exit(EXIT_FAILURE);
		}
		else
		{
			tmp->prev->n /= tmp->n;
			pop(stack, line_number);
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line_number);
		free_cases(0);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul - function that multiplies the top 2 elements of the stack.
 * @stack: Double pointer to stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack && global.quantity >= 1)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->prev->n *= tmp->n;
		pop(stack, line_number);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		free_cases(0);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: Double pointer to stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: void
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack && global.quantity >= 1)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (tmp->n == 0)
		{
			dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
			free_cases(0);
			exit(EXIT_FAILURE);
		}
		else
		{
			tmp->prev->n %= tmp->n;
			pop(stack, line_number);
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
		free_cases(0);
		exit(EXIT_FAILURE);
	}
}

/**
 * pchar - function that prints the char at the top of the stack.
 * @stack: Double pointer to stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: void
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack && global.quantity >= 1)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->prev->n *= tmp->n;
		pop(stack, line_number);
	}
	if (tmp->n > 127 || tmp->n < 0)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n",
				line_number);
		free_cases(0);
		exit(EXIT_FAILURE);
	}
}
