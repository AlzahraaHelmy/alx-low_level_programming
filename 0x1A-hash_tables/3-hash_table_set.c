#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table.
 * @h_t: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *h_t, const char *key, const char *value)
{
	hash_node_t *nw;
	char *value_copy;
	unsigned long int index, i;

	if (h_t == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, h_t->size);
	for (i = index; h_t->array[i]; i++)
	{
		if (strcmp(h_t->array[i]->key, key) == 0)
		{
			free(h_t->array[i]->value);
			h_t->array[i]->value = value_copy;
			return (1);
		}
	}

	nw = malloc(sizeof(hash_node_t));
	if (nw == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->key = strdup(key);
	if (nw->key == NULL)
	{
		free(nw);
		return (0);
	}
	nw->value = value_copy;
	nw->next = h_t->array[index];
	h_t->array[index] = nw;

	return (1);
}
