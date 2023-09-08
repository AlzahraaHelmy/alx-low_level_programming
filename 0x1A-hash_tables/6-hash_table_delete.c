#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @h_t: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *h_t)
{
	hash_table_t *head = h_t;
	hash_node_t *node, *tmp;
	unsigned long int y;

	for (y = 0; y < h_t->size; y++)
	{
		if (h_t->array[y] != NULL)
		{
			node = h_t->array[y];
			while (node != NULL)
			{
				tmp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
