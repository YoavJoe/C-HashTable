/*
*******************
file: hashtable.
*******************
*/
#include "../include/hashtable.h"

static int curr_size;

void init_data()
{
	int i;
	for(i = 0; i < HASH_SIZE; i++)
	{
		hash_table[i]->p = (pair*)malloc(sizeof(pair));
		if(hash_table[i]->p == NULL)
			printf("Error: in index %d ", i);

		hash_table[i]->p->key = NULL;
		hash_table[i]->p->value = 0;
	}

	curr_size = 0;
}

int hashCode(char* key)
{
	int hash, index, i;
	hash = index = i = 0;

	while(key[i])
		hash+=key[i];
	index = hash % HASH_SIZE;

	return index;
}

/*Count no. of node in list*/
int getCount(char* key)
{
	int count = 0;
	node* cur = hash_table[hashCode(key)];

	while(cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

int contains(char* key)
{
	int i, size;
	node* vec = hash_table[hashCode(key)];
	size = getCount(key);

	for(i = 0; i < size; i++)
	{
		if(strcmp(vec->p->key, key))
			return TRUE;
		vec = vec-> next;
	}
	printf("Error: %s not found!\n", key);
	return FALSE;
}

void insert(char* key, int value)
{
	node* vec = NULL;
	if(contains(key))
	{
		printf("Error: key %s is already exists!\n", key);
		return;
	}
	
	vec = hash_table[hashCode(key)];
	strcpy(vec->p->key, key);
	vec->p->value = value;

	/*make next of vec as head */
	if(getCount(key) > 0)
		vec->next = hash_table[hashCode(key)];

	/*move the head to point to the new node*/
	hash_table[hashCode(key)] = vec;
}

node* get(char* key)
{
	int i, size;
	node* vec = hash_table[hashCode(key)];
	size = getCount(key);

	for(i = 0; i < size; i++)
	{
		if(strcmp(vec->p->key, key))
			return vec;
		vec = vec-> next;
	}
	printf("Error: %s not found!\n", key);
	return NULL;
}

/*python printing style*/
void print()
{
	int i, j, size;
	node* vec = NULL;

	if(curr_size == 0)
	{
		printf("{}\n");
		return;
	}

	printf("{");

	for(i = 0; i < HASH_SIZE; i++)
	{
		vec = hash_table[i];
		size = getCount(vec->p->key);	
		for(j = 0; j < size; j++)
		{
			printf("%s",vec->p->key);
			printf(":");
			printf("%d",vec->p->value);
			if(i < HASH_SIZE)
				printf(", ");
		}
	}

	printf("}\n");
}

