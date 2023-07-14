#include "main.h"
#include <stdio.h>

/**
 * error_file - checks if files opened.
 * @file_from:from file
 * @file_to: to file.
 * @argv:the arguments vector.
 * Return: no return.
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - check  code for Holberton
 * @argc: number arguments.
 * @argv: arguments vector.
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, ero_close;
	ssize_t nc, nu;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_from, file_to, argv);

	nc = 1024;
	while (nc == 1024)
	{
		nc = read(file_from, buf, 1024);
		if (nc == -1)
			error_file(-1, 0, argv);
		nu = write(file_to, buf, nc);
		if (nu == -1)
			error_file(0, -1, argv);
	}

	ero_close = close(file_from);
	if (ero_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	ero_close = close(file_to);
	if (ero_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
