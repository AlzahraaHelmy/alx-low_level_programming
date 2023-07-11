#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 * Return: number  bytes read/printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fg;
	ssize_t bytes;
	char buf[READ_ZA_SIZE *8];

	if (filename == NULL)
		return (0);
	if (letters == NULL)
		return (0);
	fg = open(filename, O_RDONLY);
	if (fg == -1)
		return (0);
        bytes = read(fg, &buf[0], letters);  
        bytes = write(STDOUT_FILENO, &buf[0], bytes);
	close(fg);
	return (bytes);
}	        	
