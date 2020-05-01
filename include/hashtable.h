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

#define HASH_SIZE 10
#define TRUE 1
#define FALSE 0

#define MAX_KEY 30

/* std::array<std::vector<std::pair<K, V>>, MAP_SIZE> data;*/
/* array of list: node with value of struct pair and next*/
/* pair: struct of char*, occ**/
/* occ* struct: all label stuff, and next*/

typedef struct pair
{
	char key[MAX_KEY]; /*Defined arbitrarily max chars in the key*/
	int value;
}pair;

typedef struct node
{
	pair* pair;
	struct node* next;
}node;

/*Each cell of this array is a pointer to the first node of a linked list, 
because we want our HashTable to use a chaining collision handling*/

node** init_table();
int hash_code(char* key);
void insert(node** table, char* key, int value);
pair* get(node** table, char* key);
void erase(node** table, char* key);
void print(node** table);
void clear_table(node** table);

/*Util functions*/
pair* make_new_pair(char* key, int value);
void add_to_list(node** head, pair* new_pair);
void free_list(node* cur);
void del_from_lst(node** head, char* key);

#endif