#include "monty.h"
/**
 * mod - computed the rest of the division from
 * the division of the second top by the first top element of the stack
 * @stack: A pointer to the beginning of the list.
 * @line_number: The line in which the monnad is in.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *num1 = *stack, *num2 = (*stack)->next;

	if (!stack || !num1 || !num2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	num2->n = (num2->n % num1->n);
	*stack = num2;
	free(num1);
}
/**
 * pchar - Prints the ascii value of the number given.
 * @stack: A pointer to the beginning of the list.
 * @line_number: The line in which the monnad is in.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->n > 128)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
	else if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
