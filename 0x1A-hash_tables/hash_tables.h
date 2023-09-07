#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct hash_node_s - Hash table node
 *
 * @k: The key
 * @v: The value corresponding to the key
 * @next: A pointer to the next node of the list
 */
typedef struct hash_node_s
{
     char *k;
     char *v;
     struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @s: The size of the array
 * @a: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
     unsigned long int s;
     hash_node_t **a;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int s);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *k, unsigned long int s);
int hash_table_set(hash_table_t *h_t, const char *k, const char *v);
char *hash_table_get(const hash_table_t *h_t, const char *k);
void hash_table_print(const hash_table_t *h_t);
void hash_table_delete(hash_table_t *h_t);

/**
 * struct shash_node_s - Node of a sorted hash table
 *
 * @k: The key,
 * The key is unique in the HashTable
 * @v: The value corresponding to a key
 * @n: A pointer to the next node of the List
 * @sp: A pointer to the previous element of the sorted linked list
 * @sn: A pointer to the next element of the sorted linked list
 */
typedef struct shash_node_s
{
     char *k;
     char *v;
     struct shash_node_s *n;
     struct shash_node_s *sp;
     struct shash_node_s *sn;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 *
 * @s: The size of the array
 * @a: An array of size @size
 * @sh: A pointer to the first element of the sorted linked list
 * @st: A pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
     unsigned long int s;
     shash_node_t **a;
     shash_node_t *sh;
     shash_node_t *st;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int s);
int shash_table_set(shash_table_t *h_t, const char *k, const char *v);
char *shash_table_get(const shash_table_t *h_t, const char *k);
void shash_table_print(const shash_table_t *h_t);
void shash_table_print_rev(const shash_table_t *h_t);
void shash_table_delete(shash_table_t *h_t);

#endif /* HASH_TABLES */
