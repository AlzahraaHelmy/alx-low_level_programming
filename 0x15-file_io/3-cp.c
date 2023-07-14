#include "main.h"
#include <stdio.h>

/**
 * error_file - checks if the file opens
 * @file: the name of frile
 * @file_to: file_to.
 * @av: arguments vector.
 * Return:  Always 0.
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (fi_f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (fi_t == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - check the code.
 * @argc: number .
 * @argv: arguments vector.
 * Return: no return
 */
int main(int argc, char **argv)
{
	int fi_f, fi_t;
	ssize_t  l_r = 1024, l_w, cl_fi;
	char content[1024];

	if (argc != 3)
	{ dprintf(STDERR_FILENO, "Usage: cp fi_f fi_t\n");
		exit(97); }
	fi_f = open(argv[1], O_RDONLY);
	if (fi_f == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
		exit(98); }
	fi_t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fi_t == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99); }
	while (l_r == 1024)
	{
		l_r = read(fi_f, content, 1024);
		if (l_r == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98); }
		l_w = write(fi_t, content, l_r);
		if (l_w == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99); }
	}
	close_file = close(fi_f);
	if (close_file == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", fi_f);
		exit(100); }
	close_file = close(fi_t);
	if (close_file == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", fi_t);
		exit(100); }
return (0);
}
