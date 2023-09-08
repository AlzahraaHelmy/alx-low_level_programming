#include "hash_tables.h"

/**
 * key_index - returns the index
 * @key: key of index
 * @size: size of the array
 * Return: Index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index = hash_djb2(key) % size;

	return (index);
}
