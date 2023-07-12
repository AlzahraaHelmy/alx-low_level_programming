#include "main.h"

/**
 * append_text_to_file - Appends text to file.
 * @filename: name of the file.
 * @text_content: text.
 *
 * Return: 1 on success -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fg;
	int wr;
	int len = 0;

	if (!filename)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fg = open(filename, O_WRONLY | O_APPEND);
	wr = write(o, text_content, len);

	if (fg == -1 || wr == -1)
		return (-1);

	close(fg);

	return (1);
}
