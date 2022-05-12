#include "monty.h"

/**
 * add_dnodeint - Add a node at the head of the linked list.
 *
 * @head: Double pointer to the linked list.
 *
 * @n: Value of the new node.
 *
 * Return: Pointer to the new node, if fails return NULL
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = NULL;

	/*
	 *if (!head)
	 * return (NULL);
	 */

	if (!head)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_cases(0);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_cases(0);
		exit(EXIT_FAILURE);
	}

	new_node->prev = NULL;
	new_node->n = n;

	if (*head)
	{
		new_node->next = *head;
		(*head)->prev = new_node;
	}

	*head = new_node;
	return (*head);
}
