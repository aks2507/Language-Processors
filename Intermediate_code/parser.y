%{
	#include <bits/stdc++.h>
	using namespace std;
	extern int yylineno;
	extern int yylex();
	extern FILE* yyin;

	void yyerror (const char *s) {
   		fprintf (stderr, "%s\n", s);
 	}	

 	struct symbol_t{
 		int lineno;
 		string type;
 	};
 	struct place_t{
 		char place[10];
 	};

 	map<string, vector<symbol_t> > sym_table;
 	int labelctr = 0, tempctr = 0;

 	string new_label(){
		char tmp[10];
		sprintf(tmp, "%d", labelctr); labelctr++;
		string s(tmp);
		return "_l" + s;  
	}

	string new_temp(){
		char tmp[10];
		sprintf(tmp, "%d", tempctr); tempctr++;
		string s(tmp);
		return "_t" + s;  
	}
 	ofstream fout;
 	stack<string> s;
%}

%union{
	int assop, i;
	struct place_t* place;
	char* id;
	char* relop;
}

%token MAIN IF ELSE WHILE DEC
%token <id> ID
%token <id> INTEGER
%token <relop> RELOP
%nonassoc '(' ')'
%nonassoc '{' '}'
%nonassoc ';'
%left OR
%left AND
%left NOT
%left '+' '-'
%left '*' '/'
%type <place> EXPR STMT STMTS PROGRAM BOOL BLOCK
%start PROGRAM

%%

PROGRAM: MAIN '{' STMTS '}' { fout << "halt" << endl; printf("Ended code generation!\n"); }
	;

STMTS: STMT ';'
	| BLOCK
	| STMT ';' STMTS 
	| BLOCK STMTS
	;

STMT: DEC ID {
		symbol_t entry; entry.lineno = yylineno; entry.type = "int";
		string tmp($2);
		sym_table[tmp].push_back(entry);
	}
	| ID '=' EXPR {
		string tmp($1);
		string place3($3->place);
		fout << tmp << " = " << place3 << endl;
	}
	;

EXPR: EXPR '+' EXPR {
		string s1($1->place), s2($3->place);
		string tmp = new_temp();
		strcpy($$->place, tmp.c_str());
		fout << tmp << " = " << s1 << " + " << s2 << endl;
	}
	| EXPR '*' EXPR {
		string s1($1->place), s2($3->place);
		string tmp = new_temp();
		strcpy($$->place, tmp.c_str());
		fout << tmp << " = " << s1 << " * " << s2 << endl;
	}
	| '(' EXPR ')' {
		strcpy($$->place, $2->place);
	}
	| '-' EXPR {
		string s1($2->place);
		string tmp = new_temp();
		strcpy($$->place, tmp.c_str());
		fout << tmp << " = -" << s1 << endl;
	}
	| ID {
		strcpy($$->place, $1);
	}
	| INTEGER {
		strcpy($$->place, $1);
	}
	;

BLOCK: IF '(' BOOL ')' { 
		s.push(new_label()); 
		string tmp($3->place);
		fout << "if " << tmp << " == 0 goto " << s.top() << endl;  
	} '{' STMTS '}' {
		fout << s.top() << ": "; s.pop();
	} 
	
	| IF '(' BOOL ')' { 
		s.push(new_label()); 
		string tmp($3->place);
		fout << "if " << tmp << " == 0 goto " << s.top() << endl; 
	} '{' STMTS '}' ELSE { 
		string tmp = s.top(); s.pop();
		s.push(new_label());
		fout << "goto " << s.top() << endl;
		fout << tmp << ": "; 
	} '{' STMTS '}' { 
		fout << s.top() << ": "; s.pop();
	}
	
	| WHILE {
		s.push(new_label());
		fout << s.top() << ": ";
	} '(' BOOL ')' {
		s.push(new_label()); 
		string tmp($4->place);
		fout << "if " << tmp << " == 0 goto " << s.top() << endl;  
	} '{' STMTS '}' {
		string begin_label, end_label;
		end_label = s.top(); s.pop();
		begin_label = s.top(); s.pop();
		fout << "goto " << begin_label << endl;
		fout << end_label << ": ";
	}
	;

BOOL: BOOL AND BOOL {
		string s1($1->place), s2($3->place);
		string tmp = new_temp();
		strcpy($$->place, tmp.c_str());
		fout << tmp << " = " << s1 << " and " << s2 << endl;
	}
	| BOOL OR BOOL {
		string s1($1->place), s2($3->place);
		string tmp = new_temp();
		strcpy($$->place, tmp.c_str());
		fout << tmp << " = " << s1 << " or " << s2 << endl;
	}
	| NOT BOOL {
		string s1($2->place);
		string tmp = new_temp();
		strcpy($$->place, tmp.c_str());
		fout << tmp << " = not" << s1 << endl;
	}
	| EXPR RELOP EXPR {
		string tmp($2);
		string false_label = new_label(), end_label = new_label();
		string tmp1($1->place), tmp2($3->place);
		string place0 = new_temp();
		strcpy($$->place, place0.c_str());
		fout << "if " << tmp1 << " " << tmp << " " << tmp2 << " goto " << false_label << endl;
		fout << place0 << " = 0" << endl;
		fout << "goto " << end_label << endl;
		fout << false_label << ": ";
		fout << place0 << " = 1" << endl;
		fout << end_label << ": ";
	}

%%

int main(int argc,char *argv[]){
	if(argc!=2){
		printf("Number of input files not proper");
		exit(0);
	}
	yyin = fopen(argv[1],"r");
	if(yyin==NULL){
		perror("Input file not opened");
		exit(0);
	}
	fout.open("output.txt", ios::out);
	yyparse();
	fout.close();
	return 0;
}