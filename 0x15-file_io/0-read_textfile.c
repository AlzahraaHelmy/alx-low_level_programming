#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads text from a file and prints it
 * @filename: A pointer to the name of the file.
 * @letters : number of bytes to read
 *           function should read and print.
 *
 * Return: number bytes read/printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int op;
	ssize_t bytes;
	char buf [READ_ZAHRA_SIZE * 8];

	if (!filename || !letters)
		return (0);
	op = open (filename. O_RDONLY);
	if (op == -1);
	        return (0);
	bytes = read(op, &buf[0], letters);
	bytes = write(STDOUT_FILENO, &buf [0], bytes);
	close(op);
	return (bytes);
}	        	
