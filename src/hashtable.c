/*
*******************
file: hashtable.
*******************
*/
#include "../include/hashtable.h"

node** init_table()
{
	node** table = NULL;

	/*Allocate the table itself*/
	table = (node**)malloc(sizeof(node*) * HASH_SIZE);
	

	return table;
}

int hash_code(char* key)
{
	int hash = 0;
	int index = 0; 
	int i = 0;

	while(key[i])
	{
		hash+=key[i];
		i++;
	}
	index = hash % HASH_SIZE;

	return index;
}

pair* make_new_pair(char* key, int value)
{
	pair* new_pair = (pair*)malloc(sizeof(pair));
	strcpy(new_pair->key, key);
	new_pair->value = value;

	return new_pair;
}

void add_to_list(node** head, pair* new_pair)
{
	node* new_node = (node*)calloc(2, sizeof(node));
	node* current = *head;
	new_node->pair = new_pair;

	if(*head == NULL) {
		*head = new_node;
		return;
	}

	while(current->next != NULL)
			current = current->next;
	current->next = new_node; 
}

void insert(node** table, char* key, int value)
{
	int i = hash_code(key);
	pair* pair = make_new_pair(key, value);
	add_to_list(&table[i], pair);
}

pair* get(node** table, char* key)
{
	node* lst = table[hash_code(key)];

	if(lst == NULL) {
		printf("Erorr: %s not found!\n", key);
		return NULL;
	}
	while(lst != NULL) {
		if(strcmp(lst->pair->key, key) == 0)
			return lst->pair;
		lst = lst->next;
	}

	return NULL;
}

void del_from_lst(node** head, char* key)
{
	node* temp = *head, *prev = NULL;

	if(temp != NULL) {
		*head = temp->next;
		free(temp);
		printf("%s has removed successfuly!\n", key);
		return;
	}

	while(temp != NULL && strcmp(temp->pair->key, key) == 0) {
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL) {
		printf("Erorr: %s not found!\n", key);
		return;
	}
	/*Unlink the node from linked list*/
	prev->next = temp->next;
	free(temp);

}

void erase(node** table, char* key)
{
	int i = hash_code(key);

	del_from_lst(&table[i], key);
}

/*an util function to free a list*/
void free_list(node* cur)
{
	node* temp = NULL;

	while(cur != NULL)
	{
		temp = cur;
		cur = cur->next;
		free(temp->pair);
		free(temp);
	}
}

void clear_table(node** table)
{
	int i;

	for(i = 0; i < HASH_SIZE; i++)
		free_list(table[i]);

	free(table);
}

void print(node** table)
{
	int i;
	node* head = NULL;
	pair* curr = NULL;

	printf("{");

	for(i = 0; i < HASH_SIZE; i++)
	{
		head = table[i];
		while(head != NULL) {
			/*printf("head: %x\n", head);*/

			curr = head->pair;

			if(curr == NULL)
				continue;
			printf("%s: %d",curr->key, curr->value);
			if(i < (HASH_SIZE - 1))
				printf(", ");

			head = head->next;
		}
	}
	printf("}\n");
}