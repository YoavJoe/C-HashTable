/*
*******************
file: hashtable.
*******************
*/
#include "../include/hashtable.h"

extern node* hash_table[HASH_SIZE];

int curr_size;

void init_data()
{
	int i;
	for(i = 0; i < HASH_SIZE; i++)
	{
		hash_table[i]->p = (pair*)malloc(sizeof(pair));
		hash_table[i]->p->key = NULL;
		hash_table[i]->p->value = 0;
	}

	curr_size = HASH_SIZE;
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
int getCount(node* head)
{
	int count = 0;
	node* cur = head;

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
	size = getCount(vec);

	for(i = 0; i < size; i++)
	{
		if(strcmp(vec->p->key, key))
			return TRUE;
		vec = vec-> next;
	}
	printf("Error: %s not found!\n", key);
	return FALSE;
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
		size = getCount(vec);	
		for(j = 0; j < size; j++)
		{
			printf("%s",vec->p->key);
			printf(":");
			printf("%d"vec->p->value);
			if(i < HASH_SIZE)
				printf(", ");
		}
	}

	printf("}\n");
}

