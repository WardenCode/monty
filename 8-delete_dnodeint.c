#include "monty.h"

/**
 * delete_dnodeint_at_index - Delete a node at the index.
 *
 * @head: Double pointer to the linked list.
 *
 * @index: Position of the node to eliminate.
 *
 * Return: 1 if success, 0 otherwise.
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp = NULL;

	if (!head || !(*head))
		return (-1);

	tmp = *head;

	if (index == 0)
	{
		*head = tmp->next;
		if (*head)
			(*head)->prev = NULL;
	}
	else
	{
		while (tmp && index != 0)
			tmp = tmp->next, index--;
		if (!tmp)
			return (-1);

		tmp->prev->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
	}

	free(tmp);
	return (1);
}
