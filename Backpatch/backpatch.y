%{
	#include "h1.h"
	#include <bits/stdc++.h>
	#include <string>
	#include <fstream>
	using namespace std;
	extern FILE* yyin;
	int yyerror(string s);
	int temp_counter = 1,line_no = 0;
	extern int yylex();
	struct lnode
	{
		int lineno;
		struct lnode* next;
	};
	
	struct Expression
	{
		string temp_name;
		struct lnode *truelist,*falselist,*nextlist;
		int type;
	};
	
	struct sentinel
	{
		int q;
	};
	
	string new_temp();
	
	ofstream fout;
	
	void backpatch(struct lnode* l,int off);
	
	struct lnode* makelist();
	
	struct lnode* merge(struct lnode* l1,struct lnode* l2);
	
	makelist();
	struct symbol Symbol_table[NHASH];
%}

%union
{
	struct symbol* s;
	int d;
	float f;
	struct Expression* e;
	int cmp,log,bit,assgn;
	struct sentinel *M;
}


%left ';'
%left <assgn> ASSGN
%left <cmp> CMP 
%left <log> LOG 
%left <bit> BIT
%left '+' '-'
%left '*' '/'
%right '@'
%left '%'

%token IF ELSE WHILE FOR
%token <s> ID 
%token <d> INTEGER
%token <f> REAL
%token INT FLOAT MAIN ERR
%nonassoc '(' ')' '{' '}'
%type <e> exp stmt idlist next_sent
%type <M> sent
%start calclist


%%

exp: {$$ = NULL;}
   |exp '+' exp {
   	$$ = new Expression;
   	$$->temp_name = new_temp();
   	fout<<line_no<<" : "<<$$->temp_name<<" = "<<$1->temp_name<<"+"<<$3->temp_name<<endl;
   	line_no++;
   	$$->truelist = $$->falselist = NULL;
   }
   |exp '-' exp {
   	$$ = new Expression;
   	$$->temp_name = new_temp();
   	fout<<line_no<<" : "<<$$->temp_name<<" = "<<$1->temp_name<<"-"<<$3->temp_name<<endl;
   	line_no++;
   	$$->truelist = $$->falselist = NULL;
   }
   |exp '/' exp {
   	$$ = new Expression;
   	$$->temp_name = new_temp();
   	fout<<line_no<<" : "<<$$->temp_name<<" = "<<$1->temp_name<<"/"<<$3->temp_name<<endl;
   	line_no++;
   	$$->truelist = $$->falselist = NULL;
   }
   |exp '*' exp {
   	$$ = new Expression;
   	$$->temp_name = new_temp();
   	fout<<line_no<<" : "<<$$->temp_name<<" = "<<$1->temp_name<<"*"<<$3->temp_name<<endl;
   	line_no++;
   	$$->truelist = $$->falselist = NULL;
   }
   |exp '@' exp {
   	$$ = new Expression;
   	$$->temp_name = new_temp();
   	fout<<line_no<<" : "<<$$->temp_name<<" = "<<$1->temp_name<<"@"<<$3->temp_name<<endl;
   	line_no++;
   	$$->truelist = $$->falselist = NULL;
   }
   |exp '%' exp {
   	$$ = new Expression;
   	$$->temp_name = new_temp();
   	fout<<line_no<<" : "<<$$->temp_name<<" = "<<$1->temp_name<<"%"<<$3->temp_name<<endl;
   	line_no++;
   	$$->truelist = $$->falselist = NULL;
   }
   |INT idlist {$2->type = 1;$$ = $2;}
   |FLOAT idlist {$2->type = 2;$$ = $2;}
   |ID {$$ = new Expression;$$->temp_name=$1->name;$$->type = $1->type;}
   |ID ASSGN exp {$$ = new Expression;string t;
   switch($2)
   {
	
   	case 1:
   	fout<<line_no<<" : "<<$1->name<<" = "<<$3->temp_name<<endl;
   	break;
   	case 2:
   	fout<<line_no<<" : "<<(t = new_temp())<<" = "<<$1->name<<"+"<<$3->temp_name<<endl;
   	break;
   	case 3:
   	fout<<line_no<<" : "<<(t = new_temp())<<" = "<<$1->name<<"-"<<$3->temp_name<<endl;
   	break;
   	case 4:
   	fout<<line_no<<" : "<<(t = new_temp())<<" = "<<$1->name<<"*"<<$3->temp_name<<endl;
   	break;
   	case 5:
   	fout<<line_no<<" : "<<(t = new_temp())<<" = "<<$1->name<<"/"<<$3->temp_name<<endl;
   	break;
   	
   }line_no++;if($2!=1){ fout<<line_no<<" : "<<$1->name<<" = "<<t<<endl;line_no++;}
   }
   |exp CMP exp {
   	string ch;
   	switch($2)
   	{
   		case 1:
   		ch = "==";
   		break;
   		case 2:
   		ch = ">";
   		break;
   		case 3:
   		ch = "<";
   		break;
   		case 4:
   		ch = ">=";
   		break;
   		case 5:
   		ch = "<=";
   		break;
   		case 6:
   		ch = "!=";
   		break;
   		
   	}
   	$$ = new Expression();
   	fout<<line_no<<" : "<<"if ("<<$1->temp_name<<ch<<$3->temp_name<<") goto";
   	$$->truelist = makelist();line_no++;
   	fout<<"    \n";
   	fout<<line_no<<" : "<<"goto";
   	$$->falselist = makelist();fout<<"   \n";
   	line_no++;
   }
   |exp BIT exp {
   	string ch;
   	switch($2)
   	{
   		case 1:
   		ch = "|";
   		break;
   		case 2:
   		ch = "&";
   		break;
   		case 3:
   		ch = "~";
   		break;
   		
   	}
   	$$ = new Expression;
   	$$->temp_name = new_temp();
   	fout<<line_no<<" : ";
   	if($1!=NULL)
   	fout<<$1->temp_name;
   	fout<<ch<<$3->temp_name<<endl;line_no++;
   }
   |exp LOG sent exp {
   	string ch;
   	$$ = new Expression;
   	switch($2)
   	{
   		case 1:
   		backpatch($1->truelist,$3->q);
   		$$->truelist = $4->truelist;
   		$$->falselist = merge($1->falselist,$4->falselist);
   		break;
   		case 2:
   		backpatch($1->falselist,$3->q);
   		$$->falselist = $4->falselist;
   		$$->truelist = merge($1->truelist,$4->truelist);
   		break;
   		case 3:
   		$$->truelist = $4->falselist;
   		$$->falselist = $4->truelist;
   		break;
   	}
   }
   |INTEGER {$$ = new Expression;$$->temp_name = to_string($1);
   $$->type = 1;cout<<"Number is ==***************"<<$1<<endl;}
   |REAL {$$ = new Expression;$$->temp_name = to_string($1);
   $$->type = 1;}
   |'(' exp ')' {$$ = $2;}
   ;
   
stmt: stmt ';' sent stmt {$$ = new Expression;if($4==NULL)
    {$$->nextlist = $1->nextlist;backpatch($$->nextlist,$3->q);}else {backpatch($1->nextlist,$3->q);
    $$->nextlist = $4->nextlist;
    }
    }
   /* |stmt sent stmt {$$ = new Expression;if($3==NULL)
    {$$->nextlist = $1->nextlist;backpatch($$->nextlist,$2->q);}else {backpatch($1->nextlist,$2->q);
    $$->nextlist = $3->nextlist;
    }}*/
    | IF '(' exp ')' sent '{' stmt '}' ELSE next_sent sent '{' stmt '}' {
    	$$ = new Expression;
    	backpatch($3->truelist,$5->q);
    	backpatch($3->falselist,$11->q);
    	$$->nextlist = merge($7->nextlist,$10->nextlist);
    	$$->nextlist = merge($$->nextlist,$13->nextlist);
    }
    | IF '(' exp ')' sent '{' stmt '}'
    {
    	$$ = new Expression;
    	backpatch($3->truelist,$5->q);
    	$$->nextlist = merge($3->falselist,$7->nextlist);
    }
    | WHILE sent '(' exp ')' sent '{' stmt '}'
    {
    	$$ = new Expression;
    	backpatch($4->truelist,$6->q);
    	backpatch($8->nextlist,$2->q);
    	$$->nextlist = $4->falselist;
    	fout<<line_no<<" : "<<"goto "<<$2->q<<endl;line_no++;
    }
    |exp {$$ = $1;if($1!=NULL)$$->nextlist = NULL;}
    ;
idlist: ID {cout<<"Here"<<endl;if($1!=NULL){cout<<"yes\n";}cout<<"Name = "<<$1->name<<endl;$$ = new Expression;cout<<"Upto\n";fout<<line_no<<" : "<<$1->name<<" = 0\n";line_no++;}
      | ID','idlist {$$ = new Expression;fout<<line_no<<" : "<<$1->name<<" = 0\n";line_no++;}
      ;
sent:  {$$ = new sentinel;
	$$->q = line_no;
	}
    ;
next_sent: { $$ = new Expression;
		fout<<line_no<<" : "<<"goto";
		$$->nextlist = makelist();fout<<"    \n";line_no++;}
calclist:  
	| MAIN '{' stmt '}' {cout<<"Parsing Complete!!!!"<<endl;};
	;

%%


int Hash(char* s)
{
	int n = strlen(s);
	int h = 0;
	for(int i=0;i<n;i++)
	{
		h = (h+(int)s[i]*(i+1))%NHASH;
	}
	return h;
}

struct symbol* insert(char* s)
{
	int h = Hash(s);
	int t = NHASH;
	struct symbol *q;
	while(t>0)
	{
		if(Symbol_table[h].name==NULL)
		{
			printf("Found at: %d\n",h);
			Symbol_table[h].name = (char*)malloc(sizeof(char)*20);
			strcpy(Symbol_table[h].name,s);
			q = &Symbol_table[h];
			return q;
		}
		h = (h+1)%NHASH;
		t--;
	}
	return NULL;
}

struct symbol* search(char* s)
{
	int h = Hash(s);
	int t = NHASH;
	struct symbol *q;
	while(t>0)
	{
		if(Symbol_table[h].name==NULL)
		{
			return NULL;
		}
		else if(strcmp(Symbol_table[h].name,s)==0)
		{
			printf("Found at: %d\n",h);
			q = &Symbol_table[h];
			return q;
		}
		h = (h+1)%NHASH;
		t--;
	}
}


string new_temp()
{
	string s = "t";
	s+=to_string(temp_counter);
	temp_counter++;
	return s;
}

struct lnode* makelist()
{
	int off = fout.tellp();
	struct lnode* t;
	t = new lnode;
	t->next = NULL;
	t->lineno = off;
	return t;
}

struct lnode* merge(struct lnode* l1,struct lnode* l2)
{
	struct lnode *head = NULL,*tail = NULL,*q;
	q = l1;
	while(q!=NULL)
	{
		if(head==NULL)
		{
			head = new lnode;
			head->next = NULL;
			head->lineno = q->lineno;
			tail = head;
		}
		else
		{
			tail->next = new lnode;
			tail->next->next = NULL;
			tail->next->lineno = q->lineno;
			tail = tail->next;
		}
		q = q->next;
	}
	q = l2;
	while(q!=NULL)
	{
		if(head==NULL)
		{
			head = new lnode;
			head->next = NULL;
			head->lineno = q->lineno;
			tail = head;
		}
		else
		{
			tail->next = new lnode;
			tail->next->next = NULL;
			tail->next->lineno = q->lineno;
			tail = tail->next;
		}
		q = q->next;
	}
	return head;
}

void backpatch(struct lnode* l,int off)
{
	struct lnode* q;
	q = l;
	int sto = fout.tellp();
	while(q!=NULL)
	{
		fout.seekp(q->lineno+1,ios::beg);
		fout<<off;
		q = q->next;
	}
	fout.seekp(0,ios::end);
	cout<<"Returning"<<endl;
}

int main(int argc,char* argv[])
{
	for(int i=0;i<NHASH;i++)
	{
		Symbol_table[i].name = NULL;	
	}
	yyin = fopen(argv[1],"r");
	if(yyin==NULL)
	{
		perror("Could not open");
		exit(0);
	}
	fout.open("output.txt",ios::out);
	yyparse();
	return 0;
}

int yyerror(string s)
{
	cout<<s;
	return 0;
}