#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read .
 *
 * Return: number of the bytes read/printed .
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int filed;
	ssize_t nrd, nwr;
	char *buf;

	if (!filename)
		return (0);

	filed = open(filename, O_RDONLY);

	if (filed < 0)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nrd = read(filed, buf, letters);
	nwr = write(STDOUT_FILENO, buf, nrd);

	close(filed);

	free(buf);

	return (nwr);
}
