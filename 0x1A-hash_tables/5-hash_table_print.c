#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @h_t: hash table to print
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *h_t)
{
	unsigned long int y;
	hash_node_t *tmp;
	char flag = 0; /* 0 while no data has been printed yet */

	if (h_t == NULL || h_t->array == NULL)
		return;
	printf("{");
	for (y = 0; y < h_t->size; y++)
	{
		tmp = h_t->array[y];
		while (tmp != NULL)
		{
			if (flag == 1)
				printf(", ");
			printf("'%s': '%s'", tmp->key, tmp->value);
			flag = 1;
			tmp = tmp->next;
		}
	}
	printf("}\n");
}
