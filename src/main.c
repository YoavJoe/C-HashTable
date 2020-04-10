/*
*******************
file: main.c
*******************
*/

#include "../include/hashtable.h"

int main()
{
	pnode table;
	table = init_data();
	
	insert(table, "MAIN", 2);
	insert(table, "LOOP", 3);
	insert(table, "END", 5);
	insert(table, "K", 5);
	insert(table, "LIST", 6);
	insert(table, "STR", 9);
	
	print(table);

	return 0;
}

