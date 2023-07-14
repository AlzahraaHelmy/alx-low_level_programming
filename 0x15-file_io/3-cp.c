#include "main.h"
#include <stdio.h>

/**
 * error_file - checks if the file opened.
 * @file_from: from file.
 * @file_to: to file
 * @argv: arguments vector.
 * Return: no return.
 */
void error_file(int file_from, int file_to, char *av[])
{
	if (file_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		exit(99);
	}
}

/**
 * main - check the code for Holberton School students.
 * @argc: the number argument.
 * @argv: the vector.
 * Return: no return.
 */
int main(int ac, char *av[])
{
	int file_from, file_to, erro_close;
	ssize_t nchars, nu;
	char buf[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(av[1], O_RDONLY);
	file_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_from, file_to, av);

	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(file_from, buf, 1024);
		if (nchars == -1)
			error_file(-1, 0, av);
		nu = write(file_to, buf, nchars);
		if (nu == -1)
			error_file(0, -1, argv);
	}

	erro_close = close(file_from);
	if (erro_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	erro_close = close(file_to);
	if (erro_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
