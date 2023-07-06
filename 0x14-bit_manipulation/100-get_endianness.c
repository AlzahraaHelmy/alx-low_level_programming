#include "main.h"

/**
 * get_endianness - checks if a cpu is little or big endian
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *index = (char *) &i;

	return (*index);
}
