#include "main.h"

/**
 * create_file - creates a file
 * @filename: filename.
 * @text_content: content writed in the file.
 *
 * Return: 1 if it success. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fid;
	int nl;
	int rwr;

	if (!filename)
		return (-1);

	fid = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fid < 0)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nl = 0; text_content[nl]; nl++)
		;

	rwr = write(fid, text_content, nl);

	if (rwr < 0)
		return (-1);

	close(fid);

	return (1);
}
