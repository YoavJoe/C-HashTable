/*
*******************
file: hashtable.h
*******************
*/
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#define HASH_SIZE 128
#define TRUE 1
#define FALSE 0

/* std::array<std::vector<std::pair<K, V>>, MAP_SIZE> data;*/
/* array of list: node with value of struct pair and next*/
/* pair: struct of char*, occ**/
/* occ* struct: all label stuff, and next*/

typedef struct pair
{
	char* key;
	int value;
}pair;

typedef struct node
{
	pair* pair;
	struct node* next;
}node, **pnode;

/*Each cell of this array is a pointer to the first node of a linked list, 
because we want our HashTable to use a chaining collision handling*/

pnode init_data();
int hashCode(char* key);
int contains(pnode table, char* key);
int getCount(pnode table, char* key);
void insert(pnode table, char* key, int value);
node* get(pnode table, char* key);
void clear(pnode table);
void print(pnode table);

#endif