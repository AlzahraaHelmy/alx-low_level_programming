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
	int fg, r, l = 0;

	if (!filename)
		return (-1);

	fg = open(filename, O_WRONLY | O_APPEND);
	if (fg < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[l])
			l++;
		l = write(fg, text_content, b);
		if (r != l)
			return (-1);
	}

	close(fg);

	return (1);
}
