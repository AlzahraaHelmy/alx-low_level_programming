#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read .
 *
 * Return: number of the bytes read/printed .
 */
ssize_t read_textfile(const char *fname, size_t letters)
{
	int fd;
	ssize_t nrd, nwr;
	char *buf;

	if (!fname)
		return (0);

	fd = open(fname, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nrd = read(fd, buf, letters);
	nwr = write(STDOUT_FILENO, buf, nrd);

	close(fd);

	free(buf);

	return (nwr);
}
