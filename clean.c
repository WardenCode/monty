#include "monty.h"

/**
 * total_malloc - Calculate the spaces and tabs to calculate
 * the malloc's quantity to use.
 *
 * @command: Command to analyze.
 *
 * Return: The malloc's quantity to use.
 */

int total_malloc(char *command)
{
	int i = 0, counter = 0, flag = 0;

	while (command[i] != '\0')
	{
		if (command[i] != ' ' && command[i] != '\t')
			flag = 1;

		if ((command[i] == ' ' || command[i] == '\t') && flag == 1)
			counter++;
		i++;
	}
	return (counter + 2);
}

/**
 * free_tokens - Free a double pointer that contains tokens of a command.
 *
 * @tokens: Double pointer with the information of the command.
 *
 * Return: Void
 */

void free_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/**
 * tokenizer - Takes the input and tokenize command and arguments.
 *
 * @input: Input of the getline (with a command and parameters).
 *
 * Return: A structure with the tokens and a holder to free later.
 */

char **tokenizer(char *input)
{
	char **tokens = NULL, *token = NULL;
	int spaces = total_malloc(input), i = 0;

	tokens = malloc(sizeof(char *) * (spaces));
	if (!tokens)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free(global.command);
		free_dlistint(global.stack);
		fclose(global.fd_monty);
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " \n\t");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, " \n\t");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * free_cases - Multiple options to free in Monty.
 *
 * @flag: Flag to choose what free use.
 *
 * Return: Void.
 */

void free_cases(int flag)
{
	if (flag == 1)
	{
		free(global.command);
		free_dlistint(global.stack);
		fclose(global.fd_monty);
	}
	else if (flag == 2)
	{
		free_tokens(global.tokens);
		free(global.command);
	}
	else
	{
		free(global.command);
		free_tokens(global.tokens);
		free_dlistint(global.stack);
		fclose(global.fd_monty);
	}
}

/**
 * is_comment - Validate if the input is a comment.
 *
 * @str: String to analyse.
 *
 * Return: 1 if is a comment, 0 otherwise.
 */

int is_comment(char *str)
{
	size_t i = 0;

	while (str[i] && str[i] != '#')
		i++;

	if (i == strlen(str))
		return (0);

	return (1);
}
