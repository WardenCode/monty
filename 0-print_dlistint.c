#include "monty.h"

/**
 * print_dlistint - Print the element of a double linked list
 *
 * @h: The head of the linked list
 *
 * Return: Number of nodes
 */

size_t print_dlistint(stack_t *h)
{
	stack_t *tmp = h;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	printf("%d\n", tmp->n);
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		printf("%d\n", tmp->n);
	}
	return (0);
}
