#include "monty.h"

/**
 * open_file - function that opens a file
 * @file_name: the file namepath
 * Return: void
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - function that reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (line_number = 1; getline(&buffer, &length, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parse_line - function that Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *op, *val;
	const char *del = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, del);
	if (op == NULL)
		return (format);
	val = strtok(NULL, del);

	if (strcmp(op, "stack") == 0)
		return (0);
	if (strcmp(op, "queue") == 0)
		return (1);

	find_func(op, val, line_number, format);
	return (format);
}
