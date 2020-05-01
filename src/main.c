/*
*******************
file: main.c
*******************
*/

#include "../include/hashtable.h"

int main()
{
	node** table = init_table();
	pair* temp = NULL;

	erase(table, "MAIN");

	insert(table, "MAIN", 100);
	temp = get(table, "MAIN");

	printf("%s: %d\n",temp->key, temp->value);

	insert(table, "LOOP", 103);

	insert(table, "END", 124);

	insert(table, "STR", 125);
	insert(table, "LIST", 130);
	insert(table, "K", 133);

	print(table);

	erase(table, "MAIN");

	print(table);
	
	clear_table(table);

	return 0;
}