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

/**
 * print_tokens - Print the tokens of a double pointer
 *
 * @tokens: Double pointer to the tokens
 *
 * Return: Void
 */

void print_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i])
		printf("%s ", tokens[i]), i++;

	printf("\n");
}

/**
 * _isdigit - parameter is a num or not.
 * Return: 1 if c is num, 0 otherwhise
 * @c: parameter
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/**
 * is_a_num - function that verifies if the variable is a number
 * @n: is a character
 *
 * Return: 1 if success or 0 if not
 */

int is_a_num(char *n)
{
	int i = 0;

	if (n[i] == '-')
	{
		i++;
		if (n[i] == '\0')
			return (0);
	}
	for (; n[i]; i++)
	{
		if (_isdigit(n[i]) == 0)
			return (0);
	}
	return (1);
}

/**
 * all_spaces - Validate if the command of input is composed by spaces.
 *
 * @command: Command to go through
 *
 * @size: The size of the command (input)
 *
 * Return: Flag with the value of the search, 1 if only found spaces, \n and \t
 * 0 otherwise.
 */

int all_spaces(char *command, ssize_t size)
{
	ssize_t i = 0, flag = 1;

	while (command[i] == ' ' || command[i] == '\t' ||
	       command[i] == '\n')
		i++;

	if (i != size)
		flag = 0;

	return (flag);
}
