#include<bits/stdc++.h>
struct symbol
{
	int type;
	char* name;
	float val;
};

#define NHASH 9997


extern struct symbol Symbol_table[NHASH];

struct ID_List
{
	int type;
	struct symbol* s;
	struct ID_List* next;
};

int Hash(char* s);
extern struct symbol* search(char* s);
extern struct symbol* insert(char* s);