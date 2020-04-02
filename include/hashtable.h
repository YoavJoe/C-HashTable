/*
*******************
file: hashtable.h
*******************
*/
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	pair* p;
	struct node* next;
}node;

/*Each cell of this array is a pointer to the first node of a linked list, 
because we want our HashTable to use a chaining collision handling*/

node* hash_table[HASH_SIZE];    /*pointer to Hash Table*/

void init_data();
int hashCode(char* key);
int contains(char* key);
int getCount(node* head);
void insert(char* key, int value);
node* get(char* key);
void clear();
void print();

#endif