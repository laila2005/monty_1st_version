#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
* push - pushes an element onto the stack
* @stack: pointer to the top of the stack
* @line_number: the line number where the opcode is being called
* @arg: the value to be pushed onto the stack (as a string)
*
* Description: Converts the argument to an integer and pushes a new node
* with that integer value onto the top of the stack. If the argument is
* not a valid integer, or if no argument is provided, it prints an error
* message and exits with failure.
*/

void push(stack_t **stack, unsigned int line_number, char *arg)
{
int value;
stack_t *new_node;

if (arg == NULL || (!isdigit(arg[0]) && arg[0] != '-' && !isdigit(arg[1])))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

value = atoi(arg);

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}

/**
* pall - prints all the values on the stack, starting from the top
* @stack: pointer to the top of the stack
* @line_number: the line number where the opcode is being called (unused)
*
* Description: Prints all the values from the top of the stack to the
* bottom. Each value is printed on a new line. If the stack is empty,
* nothing is printed.
*/
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
stack_t *current = *stack;

if (current == NULL)
return;
while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
* pint - prints the value at the top of the stack
* @stack: pointer to the top of the stack
* @line_number: the line number where the opcode is being called
*
* Description: Prints the value at the top of the stack. If the stack is
* empty, prints an error message and exits with failure.
*/
void pint(stack_t **stack, unsigned int line_number)
{
if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}
