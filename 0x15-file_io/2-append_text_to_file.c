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
	int fld, wr, len = 0;

	if (!filename)
		return (-1);

	fld = open(filename, O_WRONLY | O_APPEND);
	if (fld < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;
		wr = write(fld, text_content, b);
		if (wr != len)
			return (-1);
	}

	close(fld);

	return (1);
}
