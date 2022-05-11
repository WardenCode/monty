#include "monty.h"

/**
 * pall - Print a stack.
 *
 * @stack: Double pointer to the stack.
 *
 * @line_number: Number of line of the monty file.
 *
 * Return: Void.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (stack && *stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}

/**
 * push - Add a node at the head of the linked list.
 *
 * @stack: Double pointer to the stack.
 *
 * @line_number: Number of line of the monty file.
 *
 * Return: Void.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;

/*	if (!(*stack))
		return (NULL);*/

	new_node = malloc(sizeof(stack_t));
	/*if (!new_node)
		return (NULL);*/

	new_node->prev = NULL;
	new_node->n = 5;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * choose_option - Find if the flag match with an existence and
 * give the correct function.
 *
 * @s: Character to pass
 *
 * Return: A print_operation struct with a flag (0 or 1
 * and a function pointer or NULL.
 */

instruction_t choose_option(char **tokens) {
	instruction_t result = {"", NULL};
	instruction_t options[] = {
		{"push", push},
		{"pall", pall},
		/*{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},*/
		{"", NULL}
	};
	int i = 0;

	while (options[i].opcode)
	{
		if (strcmp(options[i].opcode, tokens[0]) == 0)
		{
			result.opcode = tokens[0];
			result.f = options->f;
			return (result);
		}
		i++;
	}
	return (result);
}

/**
 * main - Function that calls opcodes
 *
 * @ac: Arguments Count
 * @av: Arguments Vector
 * Return: int
 */

int main(int ac, char **av)
{
	stack_t **stack = NULL;
	unsigned int line_number = 1;
	FILE *fd_monty = 0;
	size_t len = 0;
	char *command = NULL;
	char **tokens = NULL;
	instruction_t option = {};

	if (ac != 2) /* if too many or more than one argument, then exit fail*/
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd_monty = fopen(av[1], "r");
	if (fd_monty->_fileno == -1)  /*If file can't open then exit fail*/
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&command, &len, fd_monty) != EOF)
	{
		tokens = tokenizer(command);
		// print_tokens(tokens);
		option = choose_option(tokens);
		if (strcmp(option.opcode, "") != 0)
			option.f(stack, line_number);
		else
			printf("error");
		free_tokens(tokens);
		free(command);
		len = 0;
		line_number++;
	}
	free(command);
	fclose(fd_monty);
	return (0);
}
