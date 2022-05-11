#include "monty.h"

/**
 * str_concat - Concatenate two strings in a new pointer
 *
 * @s1: String one.
 *
 * @s2: String two.
 *
 * Return: If success return a pointer with the concat otherwise null.
 */

char *str_concat(char *s1, char *s2)
{
	char *final_str = NULL;
	int size1 = 0, size2 = 0, total_size = 0, i = 0;

	size1 = strlen(s1);
	size2 = strlen(s2);

	total_size = size1 + size2 + 1;
	final_str = malloc(total_size * sizeof(char));
	if (!final_str)
		return (NULL);

	for (i = 0; i < total_size; i++)
	{
		if (size1 && i < size1)
			final_str[i] = s1[i];
		if (i >= size1 && s2)
			final_str[i] = s2[i - size1];
	}

	return (final_str);
}
