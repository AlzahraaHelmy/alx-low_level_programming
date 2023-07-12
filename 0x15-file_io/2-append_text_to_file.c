#include "main.h"

/**
 * append_text_to_file - Appends text to file.
 * @filename: name of the file.
 * @text_content: text to write
 *
 * Return: 1 on success -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
        int fg, wr, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
		wr = write(fg, text_content, b);
		if (wr != len)
			return (-1);
	}	

	close(fg);

	return (1);
}
