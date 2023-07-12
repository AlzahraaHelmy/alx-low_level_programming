#include "main.h"

/**
 * main - program file
 * @argc: number of arguments count
 * @argv:  arguments vector
 *
 * Return: 1 on success 0 on failure.
 */
int main(int argc, char *argv[])
{
	int fld_w, fld_r, rd, z, b;
	char buf[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fld_w = open(argv[1], O_RDONLY);
	if (fld_w < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fld_r = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((rd = read(fld_w, buf, BUFSIZ)) > 0)
	{
		if (fld_r < 0 || write(fld_r, buf, rd) != rd)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fld_w);
			exit(99);
		}
	}
	if (rd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	z = close(fld_w);
	b = close(fld_r);
	if (z < 0 || b < 0)
	{
		if (z < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fld_w);
		if (b < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fld_r);
		exit(100);
	}
	return (0);
}
