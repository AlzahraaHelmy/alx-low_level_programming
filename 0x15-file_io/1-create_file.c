#include "main.h"

/**
 * _strlen - returns length of a string
 * @l: check the string
 *
 * Return: integer length of string
 */
int _strlen(char *l)
{
	int i = 0;
	if (l == NULL)
		return (0);
        for (*l++)
                i++;
	return (i);
}

/**
 * create_file - creates a new file.
 * @filename: name of file.
 * @text_content: text to write to the new file.
 *
 * Return: Always 1 on success -1 on failure
 */
int create_file(const char *filename, char *text_content);
{
	int fg;
        ssize_t bytes = 0, len = _strlen(text_content);

	if (filename == NULL)
    	        return (-1);

        fg = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
        if (fg < 0)
		return (-1);	
        if (len)
	        bytes = write(fg, text_content, len);
	close(fg);
	return (1);
}
