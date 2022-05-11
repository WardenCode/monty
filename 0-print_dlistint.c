#include "monty.h"

/**
 * print_dlistint - Print the element of a double linked list
 *
 * @h: The head of the linked list
 *
 * Return: Number of nodes
 */

size_t print_dlistint(const stack_t *h)
{
	if (h)
	{
		printf("%d\n", h->n);
		return (1 + print_dlistint(h->next));
	}

	return (0);
}
