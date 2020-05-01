/*
*******************
file: main.c
*******************
*/

#include "../include/hashtable.h"

int main()
{
	node** table = init_table();

	insert(table, "MAIN", 100);

	insert(table, "LOOP", 103);

	insert(table, "END", 124);

	insert(table, "STR", 125);
	insert(table, "LIST", 130);
	insert(table, "K", 133);
	print(table);
	
	clear_table(table);

	return 0;
}