#include "monty.h"

/**
 * nop - function that doesn't do anything.
 * @stack: Double pointer to stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add - adds the top two elements of the stack.
 * @stack: Double pointer to stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack && global.quantity >= 1)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->prev->n += tmp->n;
		pop(stack, line_number);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		free_cases(0);
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: Double pointer to stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *before = NULL;
	int holder = 0;

	if (*stack && global.quantity >= 1)
	{
		tmp = *stack;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		before = tmp->prev;

		holder = before->n;
		before->n = tmp->n;
		tmp->n = holder;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		free_cases(0);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - removes the top element of the stack.
 * @stack: Double pointer to stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack)
	{
		delete_dnodeint_at_index(stack, global.quantity);
		global.quantity--;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		free_cases(0);
		exit(EXIT_FAILURE);
	}
}


/**
 * pint- Print the element at the top of the stack
 * @stack: Double pointer to stack.
 * @line_number: Number of line of the monty file.
 *
 * Return: Void.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack)
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		printf("%d\n", tmp->n);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		free_cases(0);
		exit(EXIT_FAILURE);
	}
}
