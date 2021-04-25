%{
	#include <iostream>
	#include <algorithm>
	#include <string>
	#include <stack>
	#include <fstream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <map>
	#include <vector>
	using namespace std;
	extern int yylineno;
	extern int yylex();
	extern FILE* yyin;

	void yyerror (const char *s) {
   		fprintf(stderr, "%s\n", s);
 	}	

	//The symbol table structure that stores the line number and type
 	struct sym_table_entry
	{
 		int lineno;
 		string type;
 	};
	
	//The structure that stores the 
 	struct place_of_var
	{
 		char place[10];
 	};

 	map<string, vector<sym_table_entry> > sym_table;       //The symbol table
 	int label_count = 0, temp_variable_count = 0;

	/*
	*
	*
	This function creates a new label
	We create a new character array, store the present counter of labels
	in it and increase the global label counter.
	Here, I typecast temp into a string and return a string depending on the counter
	globally at that point.
	*
	*/
 	string new_label()
	{
		char temp[10];
		sprintf(temp, "%d", label_count); 
		label_count++;
		string s(temp);
		return "L-" + s;  
	}

	/*
	*
	*
	This function creates a new temporary variable
	We create a new character array, store the present counter of temp variables
	in it and increase the global temporary variable counter.
	Here, I typecast temp into a string and return a string depending on the counter
	globally at that point.
	*
	*/
	string new_temp()
	{
		char temp[10];
		sprintf(temp, "%d", temp_variable_count); 
		temp_variable_count++;
		string s(temp);
		return "T-" + s;  
	}
 	ofstream file_output;
 	stack<string> s;
%}

%union
{
	int assop, i;
	struct place_of_var* place;
	char* id;
	char* relop;
}

%token MAIN IF ELSE WHILE DECIMAL SWITCH CASE DEFAULT
%token <id> ID
%token <id> INTEGER
%token <relop> RELOP
%nonassoc '(' ')' 				//no association
%nonassoc '{' '}' 				//no association
%nonassoc ';' 					//no association
%left OR 						//left associativity
%left AND 						//left associativity
%left NOT 						//left associativity
%left '+' '-' 					//left associativity
%left '*' '/' 					//left associativity
%type <place> EXPRESSION STATEMENT STATEMENTS PROGRAM BOOL BLOCK CASE_LIST DEFAULT_OPT SINGLE_CASE
%start PROGRAM

%%

PROGRAM: MAIN '{' STATEMENTS '}'
	{ 
		file_output << "halt" << endl; 
		printf("Code generation Completed!!\n"); 
	}
	;

STATEMENTS: STATEMENT ';'
	| BLOCK
	| STATEMENT ';' STATEMENTS 
	| BLOCK STATEMENTS
	;

STATEMENT: DECIMAL ID {
		sym_table_entry entry; 
		entry.lineno = yylineno; 
		entry.type = "int";
		string temp($2);
		sym_table[temp].push_back(entry);
	}
	| ID '=' EXPRESSION 
	{
		string temp($1);
		string place3($3->place);
		file_output << temp << " = " << place3 << endl;
	}
	;

EXPRESSION: EXPRESSION '+' EXPRESSION 
	{
		string s1($1->place), s2($3->place);
		string temp = new_temp();
		strcpy($$->place, temp.c_str());
		file_output << temp << " = " << s1 << " + " << s2 << endl;
	}
	| EXPRESSION '*' EXPRESSION 
	{
		string s1($1->place), s2($3->place);
		string temp = new_temp();
		strcpy($$->place, temp.c_str());
		file_output << temp << " = " << s1 << " * " << s2 << endl;
	}
	| '(' EXPRESSION ')' 
	{
		strcpy($$->place, $2->place);
	}
	| '-' EXPRESSION 
	{
		string s1($2->place);
		string temp = new_temp();
		strcpy($$->place, temp.c_str());
		file_output << temp << " = -" << s1 << endl;
	}
	| ID 
	{
		strcpy($$->place, $1);
	}
	| INTEGER 
	{
		strcpy($$->place, $1);
	}
	;

BLOCK: IF '(' BOOL ')' 
	{ 
		s.push(new_label()); 
		string temp($3->place);
		file_output << "IF " << temp << " == 0 GOTO " << s.top() << endl;  
	} '{' STATEMENTS '}' 
	{
		file_output << s.top() << ": "; 
		s.pop();
	} 
	
	| IF '(' BOOL ')' 
	{ 
		s.push(new_label()); 
		string temp($3->place);
		file_output << "IF " << temp << " == 0 GOTO " << s.top() << endl; 
	} '{' STATEMENTS '}' ELSE 
	{ 
		string temp = s.top(); 
		s.pop();
		s.push(new_label());
		file_output << "GOTO " << s.top() << endl;
		file_output << temp << ": "; 
	} '{' STATEMENTS '}' 
	{ 
		file_output << s.top() << ": "; 
		s.pop();
	}
	
	| WHILE 
	{
		s.push(new_label());
		file_output << s.top() << ": ";
	} '(' BOOL ')' 
	{
		s.push(new_label()); 
		string temp($4->place);
		file_output << "IF " << temp << " == 0 GOTO " << s.top() << endl;  
	} '{' STATEMENTS '}' 
	{
		string begin_label, end_label;
		end_label = s.top(); s.pop();
		begin_label = s.top(); s.pop();
		file_output << "GOTO " << begin_label << endl;
		file_output << end_label << ": ";
	}
	| SWITCH '(' EXPRESSION ')' '{' CASE_LIST DEFAULT_OPT CASE_LIST '}'
	{
		s.push(new_label());
		file_output << s.top() << ": ";
	}
	;
DEFAULT_OPT: DEFAULT '(' DECIMAL ')'':'STATEMENT
	;
CASE_LIST: SINGLE_CASE CASE_LIST
	;
SINGLE_CASE: CASE '(' DECIMAL ')'':' STATEMENT
	;

BOOL: BOOL AND BOOL 
	{
		string s1($1->place), s2($3->place);
		string temp = new_temp();
		strcpy($$->place, temp.c_str());
		file_output << temp << " = " << s1 << " AND " << s2 << endl;
	}
	| BOOL OR BOOL 
	{
		string s1($1->place), s2($3->place);
		string temp = new_temp();
		strcpy($$->place, temp.c_str());
		file_output << temp << " = " << s1 << " OR " << s2 << endl;
	}
	| NOT BOOL 
	{
		string s1($2->place);
		string temp = new_temp();
		strcpy($$->place, temp.c_str());
		file_output << temp << " = NOT" << s1 << endl;
	}
	| EXPRESSION RELOP EXPRESSION 
	{
		string temp($2);
		string false_label = new_label(), end_label = new_label();
		string temp1($1->place), temp2($3->place);
		string place0 = new_temp();
		strcpy($$->place, place0.c_str());
		file_output << "IF " << temp1 << " " << temp << " " << temp2 << " GOTO " << false_label << endl;
		file_output << place0 << " = 0" << endl;
		file_output << "GOTO " << end_label << endl;
		file_output << false_label << ": ";
		file_output << place0 << " = 1" << endl;
		file_output << end_label << ": ";
	}

%%

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("Usage: %s [filename]",argv[0]);
		exit(0);
	}
	yyin = fopen(argv[1],"r");
	if(yyin==NULL)
	{
		perror("Input file error");
		exit(1);
	}
	file_output.open("output.txt", ios::out);
	yyparse();
	file_output.close();
	return 0;
}