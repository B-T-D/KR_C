#define HASHSIZE 101

unsigned
hash(char *s)
/* hash: return hash value for string s */
{
	unsigned hashval;
	
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}
