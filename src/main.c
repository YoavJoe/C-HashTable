/*
*******************
file: main.c
*******************
*/

#include "../include/hashtable.h"

int main()
{
	node** table = init_table();
	insert(table, "K", 8);
	print(table);
	
	clear_table(table);

	return 0;
}

