#include "main.h"
/**
 * print_binary - prints equivalent of a decimal number in binary
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int inc, count = 0;
	unsigned long int current;

	for (inc = 63; inc >= 0; inc--)
	{
		current = n >> inc;

		if (current & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
