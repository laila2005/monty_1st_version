#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
* pop - removes the top element of the stack
* @stack: pointer to the top of the stack
* @line_number: the line number where the opcode is being called
*
* Description: Removes the top element of the stack. If the stack is
* empty, prints an error message and exits with failure.
*/
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

temp = *stack;
*stack = (*stack)->next;

if (*stack != NULL)
(*stack)->prev = NULL;

free(temp);
}

#include <stdio.h>
#include <stdlib.h>

/**
* swap - swaps the top two elements of the stack
* @stack: pointer to the top of the stack
* @line_number: the line number where the opcode is being called
*
* Description: Swaps the top two elements of the stack. If the stack
* contains less than two elements, prints an error message and exits
* with failure.
*/
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *first, *second;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

first = *stack;
second = (*stack)->next;

first->next = second->next;
if (second->next != NULL)
second->next->prev = first;

second->prev = NULL;
second->next = first;
first->prev = second;
*stack = second;
}

/**
* add - Adds the top two elements of the stack.
* @stack: A double pointer to the stack.
* @line_number: The current line number in the bytecode file.
*/
void add(stack_t **stack, unsigned int line_number)
{
stack_t *top_node, *next_node;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
top_node = *stack;
next_node = top_node->next;
next_node->n += top_node->n;
*stack = next_node;
free(top_node);
next_node->prev = NULL;
}

/**
 * nop - does nothing
 * @stack: pointer to the stack
 * @line_number: current line number in the bytecode file
 *
 * Description: This opcode does not perform any operation.
 */
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
