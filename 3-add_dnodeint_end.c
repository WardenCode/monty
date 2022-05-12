#include "monty.h"

/**
 * add_dnodeint_end - Add a node at the end of the linked list.
 *
 * @head: Double pointer to the linked list.
 *
 * @n: Value of the new node.
 *
 * Return: Pointer to the new node, if fails return NULL.
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node = NULL, *temp_node = NULL;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);

	temp_node = *head;

	new_node->next = NULL;
	new_node->n = n;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		while (temp_node->next)
			temp_node = temp_node->next;
		temp_node->next = new_node;
		new_node->prev = temp_node;
	}

	return (new_node);
}
