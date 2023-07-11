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
	int fg, len = 0;

	if (filename == NULL)
    	        return (-1);
        if (text_content != NULL)
	{
	while (text_content && text_content[len])
		len++;
        }    

        fg = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	bytes = write(fg, text_content, len);
	
        if (fg == -1 || len == -1)
	        return (-1);
	
	close(fg);

	return (1);
}
