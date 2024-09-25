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
