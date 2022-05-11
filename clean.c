#include "monty.h"

/**
 * get_cmd - Get the cmd without params
 *
 * @command: Input of the file (command).
 *
 * Return: Final command
 */

char *get_cmd(char *command)
{
	int i = 0, counter = 0, flag = 1, j = 0;
	char *cmd = NULL;

	while (command[i])
	{
		if (command[i] == ' ' && flag)
		{
			i++;
			continue;
		}
		flag = 0;
		if (command[i] == ' ' || command[i] == '\n')
			break;
		counter++;
		i++;
	}

	cmd = malloc((counter + 1) * sizeof(char));
	if (!cmd)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cmd[counter] = '\0';
	while (counter != 0)
	{
		cmd[j] = command[i - counter];
		j++;
		counter--;
	}
	return (cmd);
}

/**
 * get_cmd_params - Get the cmd params object
 *
 * @command: Input of the file (pre_command).
 *
 * Return: Final command
 */

char *get_cmd_params(char *command)
{
	int i = 0, counter = 0, flag = 1, j = 0;
	char *cmd = NULL, *number = NULL, *final = NULL;

	while (command[i])
	{
		if (command[i] == ' ' && flag)
		{
			i++;
			continue;
		}
		flag = 0;
		if (command[i] == ' ' || command[i] == '\n')
			break;
		counter++;
		i++;
	}

	cmd = malloc((counter + 1) * sizeof(char));
	if (!cmd)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cmd[counter] = '\0';
	while (counter != 0)
	{
		cmd[j] = command[i - counter];
		j++;
		counter--;
	}

	number = get_cmd(&command[i]);
	final = str_concat(cmd, number);
	free(cmd);
	free(number);
	return (final);
}
