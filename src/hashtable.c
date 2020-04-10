/*
*******************
file: hashtable.
*******************
*/
#include "../include/hashtable.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

pnode init_data() /*value range of size: 0 to 255*/
{
	int i;
	pnode table = NULL;

	/*Allocate the table itself*/
	if((table = (pnode)malloc(sizeof(node))) == NULL)
		return NULL;

	for (i = 0; i < HASH_SIZE; i++)
	{
		if((table[i] = (node*)malloc(sizeof(node))) == NULL)
			return NULL;

		table[i]->pair = (pair*)calloc(2, sizeof(pair));
		table[i]->next = NULL;
	}

	return table;
}

int hashCode(char* key)
{
	int hash, index, i;
	hash = index = i = 0;

	while(key[i])
	{
		hash+=key[i];
		i++;
	}
	index = hash % HASH_SIZE;

	return index;
}

/*Count no. of node in list*/
int getCount(pnode table, char* key)
{
	int count = 0;
	node* cur = table[hashCode(key)];

	while(cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

int contains(pnode table, char* key)
{

	int i, size;
	node* vec = table[hashCode(key)];
	size = getCount(table, key);

	for(i = 0; i < size; i++)
	{
		if(vec->pair->key[0] != '\0')
			if(strcmp(vec->pair->key, key) == 0)
				return TRUE;

		vec = vec-> next;
	}
	printf("%s not found!\n", key);
	return FALSE;
}

void insert(pnode table, char* key, int value)
{
	int i;
	node* vec = NULL;
	if(contains(table, key))
	{
		printf("Error: key %s is already exists!\n", key);
		return;
	}
	i = hashCode(key);
	vec = table[i];
	vec->pair->key = key;
	vec->pair->value = value;

	/*make next of vec as head */
	if(getCount(table, key) > 1)
		vec->next = table[i];

	/*move the head to point to the new node*/
	table[i] = vec;
}

node* get(pnode table, char* key)
{
	int i, size;
	node* vec = table[hashCode(key)];
	size = getCount(table, key);

	for(i = 0; i < size; i++)
	{
		if(strcmp(vec->pair->key, key))
			return vec;
		vec = vec-> next;
	}
	printf("Error: %s not found!\n", key);
	return NULL;
}

/*python printing style*/
void print(pnode table)
{
	int i, j, size;
	node* vec = NULL;

	printf("{");

	for(i = 0; i < HASH_SIZE; i++)
	{
		vec = table[i];
		size = getCount(table, vec->pair->key);	
		for(j = 0; j < size; j++)
		{
			printf("%s",vec->pair->key);
			printf(":");
			printf("%d",vec->pair->value);
			if(i < HASH_SIZE)
				printf(", ");
		}
	}

	printf("}\n");
}

