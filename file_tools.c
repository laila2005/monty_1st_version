#include "monty.h"


/**
* open_file - opens a file
* @file_name: the file name/path
* Return: void
*/
void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	read_file(fd);
	fclose(fd);
}

/**
* read_file - reads a file line by line
* @fd: pointer to file descriptor
* Return: void
*/
void read_file(FILE *fd)
{
	int line_number = 0;
	char *buffer = NULL;
	size_t len = 0;
	stack_t *stack = NULL;

for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
{
parse_line(buffer, line_number, &stack);
}
free(buffer);
}
/**
* parse_line - Separates each line into tokens to determine
* which function to call
* @buffer: line from the file
* @line_number: line number
* @stack: double pointer to the stack to pass to functions
* Return: void
*/
void parse_line(char *buffer, int line_number, stack_t **stack)
{
	char *opcode, *arg;
	const char *delim = "\n \t";

	opcode = strtok(buffer, delim); /* Extract opcode */
	if (opcode == NULL || opcode[0] == '#') /* Skip comments */
		return;

	arg = strtok(NULL, delim); /* Extract argument */
	execute_op(opcode, arg, line_number, stack); /* Execute the operation */
}

/**
* execute_op - Executes the appropriate opcode function
* @opcode: opcode to execute
* @arg: argument for the opcode
* @line_number: line number in the file
* @stack: pointer to the stack
* Return: void
*/
void execute_op(char *opcode, char *arg,
unsigned int line_number, stack_t **stack)
{
	if (strcmp(opcode, "push") == 0)
		push(stack, line_number, arg);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

