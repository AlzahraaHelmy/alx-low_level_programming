/**
 * hash_djb2 - implementation of the djb2
 * @str: string used to generate
 *
 * Return: Hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int x;

	hash = 5381;
	while ((x = *str++))
	{
		hash = ((hash << 5) + hash) + x; /* hash * 33 + x */
	}
	return (hash);
}
