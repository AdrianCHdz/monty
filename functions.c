#include "monty.h"
/**
 * push - Add a node of a double linked list at the beginning
 * @stack: A pointer to the begging of the list
 * @line_number: The line in which the command is in.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	int n = 0;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	n = atoi(token);
	if (isdigit(n))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	newnode->n = n;
	newnode->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
	}
	newnode->next = *stack;
	*stack = newnode;
}
/**
 * pall - Prints the doubly linked list.
 * @head: A pointer to the begging of the list
 * @line_number: The line in which the command is in.
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *h = *head;
	(void)line_number;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * pint - Prints the value in the top.
 * @stack: A pointer to the begging of the list
 * @line_number: The line in which the command is in.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - Removes the top of the stack.
 * @stack: A pointer to the begging of the list
 * @line_number: The line in which the command is in.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *delete = *stack;

	if (stack == NULL || delete == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(delete);
}
/**
 * swap - Swap the top two elements of the stack.
 * @stack: A pointer to the begging of the list
 * @line_number: The line in which the command is in.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first_node = *stack, *second_node = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next->next == NULL)
		first_node->next = NULL;
	else
	{
		first_node->next = second_node->next;
		second_node->next->prev = first_node;
	}
	second_node->next = first_node;
	first_node->prev = second_node;
	second_node->prev = NULL;
	*stack = second_node;
}
