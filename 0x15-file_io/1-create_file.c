#include "main.h"

/**
 * create_file - creates a new file.
 * @filename: name of file.
 * @text_content: text to write to the new file.
 *
 * Return: Always 1 om success 0 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fg, len;
	ssize_t bytes = 0, len= _strlen(text_content);
	if (filename == NULL)
	        return (-1);
	fg = open(filename, O_TRUNC, S_IRUSR | O_WRONLY | O_CREAT | S_IWUSR);
        if (fg < 0)
	        return (-1);
	while (text_content && text_content[len])
		len++;

	if (len)
		bytes = write(fg, text_content, len);
	close(fg);
	return (bytes == len ? 1 : -1);
}
