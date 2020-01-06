#include "monty.h"
/**
 * add -  Adds the top two elements of the stack.
 * @stack: A pointer to the begging of the list
 * @line_number: The line in which the command is in.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *num1 = *stack, *num2 = (*stack)->next;

	if (stack == NULL || num1 == NULL || num2 == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num2->n = (num1->n + num2->n);
	*stack = num1->next;
	free(num1);
}
/**
 * nop -  Does nothing.
 * @stack: A pointer to the begging of the list
 * @line_number: The line in which the command is in.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub -  substract the top 2 elements of the stack.
 * @stack: A pointer to the begging of the list
 * @line_number: The line in which the command is in.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *num1 = *stack, *num2 = (*stack)->next;

	if (stack == NULL || num1 == NULL || num2 == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num2->n = (num2->n - num1->n);
	*stack = num2;
	free(num1);
}
/**
 * mydiv - divides the second top element of the stack by the top element.
 * @stack: A pointer to the begging of the list
 * @line_number: The line in which the command is in.
 */
void mydiv(stack_t **stack, unsigned int line_number)
{
	stack_t *num1 = *stack, *num2 = (*stack)->next;

	if (stack == NULL || num1 == NULL || num2 == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	num2->n = (num2->n / num1->n);
	*stack = num2;
	free(num1);
}
/**
 * mul - multiplies the second top element of the stack by the top element.
 * @stack: A pointer to the begging of the list
 * @line_number: The line in which the command is in.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *num1 = *stack, *num2 = (*stack)->next;

	if (stack == NULL || num1 == NULL || num2 == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num2->n = (num2->n * num1->n);
	*stack = num2;
	free(num1);
}
