#include "monty.h"
char *token;

void superhot(stack_t **head)
{
	stack_t *tmp;

	if (head == NULL)
		return;
	while ((*head) != NULL)
	{
		tmp = (*head);
		(*head) = (*head)->next;
		free(tmp);
	}
}

/**
 * main - Reads a monty file to be excecuted as intended
 * @argc: The number of arguments
 * @argv: The arguments needed to work with.
 * Return: Awlays 0
 */
int main(int argc, char **argv)
{
	FILE *fd;
	size_t line_size = 0;
	char *buffer = NULL;
	int line_number = 1;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	}
	while (getline(&buffer, &line_size, fd) != EOF)
	{
		compare(line_number, buffer, &head);
		line_number++;
	}
	superhot(&head);
	free(buffer);
	fclose(fd);
	return (0);
}
/**
 * compare - Compares whether the command given in the file monty exist
 *           and executes it acondingly with every command given inside.
 * @l_number: The number of the line.
 * @buffer: The memory in which the content of the file is
 * @head: A double pointer to the head of the doubly linked list.
 */
void compare(unsigned int l_number, char *buffer, stack_t **head)
{
	int n = 0;
	instruction_t commands[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", mydiv},
		{"mul", mul},
		{"mod", mod},
		{"#", nop},
		{"pchar", pchar},
		{NULL, NULL}
	};

	token = strtok(buffer, delim);
	while (commands[n].opcode != NULL)
	{
		if (strcmp(commands[n].opcode, token) == 0)
		{
			if (!strcmp(token, "push"))
			{
				token = strtok(NULL, delim);
			}
			commands[n].f(head, l_number);
		}
		n++;
	}
}
