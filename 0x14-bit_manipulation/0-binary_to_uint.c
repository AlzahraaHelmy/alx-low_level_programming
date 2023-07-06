#include "main.h"
/**
 * binary_to_uint -converts a binary number to unsigned integer
 * @b: string containing the binary number
 *
 * Return: the converted number in decimal
 */
unsigned int binary_to_uint(const char *b)
{
	int inc;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	for (inc = 0; b[inc]; inc++)
	{
		if (b[inc] < '0' || b[inc] > '1')
			return (0);
		dec_val = 2 * dec_val + (b[inc] - '0');
	}

	return (dec_val);
}

