#include "hash_tables.h"

/**
 * hash_table_get - Recover the associated value with
 *                  Key in hash table.                  
 * @h_t: A pointer to the hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *hash_table_get(const hash_table_t *h_t, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (h_t == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, h_t->size);
	if (index >= h_t->size)
		return (NULL);

	node = h_t->array[index];
	while (node && strcmp(node->key, key) != 0)
		node = node->next;

	return ((node == NULL) ? NULL : node->value);
}
