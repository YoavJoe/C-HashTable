/*
*******************
file: main.c
*******************
*/

#include "../include/hashtable.h"

int main()
{
	insert("MAIN", 2);
	insert("LOOP", 3);
	insert("END", 5);
	insert("K", 5);
	insert("LIST", 6);
	insert("STR", 9);
	
	print();

	return 0;
}

