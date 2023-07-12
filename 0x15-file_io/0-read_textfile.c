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
	int openedfile;
	ssize_t nrd, nwr;
	char *buf;

	if (filename==NULL)
		return (0);

	openedfile = open(filename, O_RDONLY);

	if (openedfile <0)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (buf==0)
		return (0);

	nrd = read(openedfile, buf, letters);
	nwr = write(STDOUT_FILENO, buf, nrd);

	close(openedfile);

	free(buf);

	return (nwr);
}
