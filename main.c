#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
* main - entry point for the Monty interpreter
* @argc: argument count
* @argv: argument vector (Monty bytecode file)
*
* Return: 0 on success, EXIT_FAILURE on failure
*/
int main(int argc, char **argv)
{
FILE *file;
char *line = NULL;
unsigned int line_number = 0;
char *opcode, *arg;
stack_t *head = NULL;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

while ((line = malloc(256)) && fgets(line, 256, file) != NULL)
{
line_number++;
opcode = strtok(line, " \n\t");
arg = strtok(NULL, " \n\t");

if (opcode && opcode[0] != '#')
execute_op(opcode, arg, line_number, &head);
}

free(line);
fclose(file);
return (0);
}

/**
* execute_op - finds and executes the corresponding opcode function
* @opcode: the opcode to be executed
* @arg: the argument (for push) or NULL for other opcodes
* @stack: Double pointer to the top of the stack.
* @line_number: the line number where the opcode is called
*/
void execute_op(char *opcode, char *arg, unsigned int
line_number, stack_t **stack)
{
if (strcmp(opcode, "push") == 0)
{
push(stack, line_number, arg);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(stack, line_number);
}
else if (strcmp(opcode, "pop") == 0)
{
pop(stack, line_number);
}
else if (strcmp(opcode, "swap") == 0)
{
swap(stack, line_number);
}
else if (strcmp(opcode, "pint") == 0)
{
pint(stack, line_number);
}
else if (strcmp(opcode, "add") == 0)
add(stack, line_number);
else if (strcmp(opcode, "nop") == 0)
{
nop(stack, line_number);
}
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
}
