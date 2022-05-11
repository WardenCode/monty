#include "monty.h"

/**
 * main - Function that calls opcodes
 *
 * @ac: Arguments Count
 * @av: Arguments Vector
 * Return: int
 */

int main(int ac, char **av)
{
	FILE *fd_monty = 0;
	size_t len = 0;
	char *command = NULL;
	char **tokens = NULL;

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
		print_tokens(tokens);
		free_tokens(tokens);
		free(command);
		len = 0;
	}
	free(command);
	fclose(fd_monty);
	return (0);
}
