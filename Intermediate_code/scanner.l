%option noyywrap
%{
	#include <bits/stdc++.h>
	#include "y.tab.h"
	using namespace std;
%}

digit [0-9]
ws [ \t\n]

%%
"main()" { return MAIN; }
"if" { return IF; }
"else" { return ELSE; }
"while" { return WHILE; }
"int" { return DEC; }

"+" |
"-" |
"*" |
"/" |
"@" |
"(" |
")" |
"?" |
":" |
"%" { return yytext[0]; }

"{" |
"}" { return yytext[0]; }

";" { return yytext[0]; }


"="  { return yytext[0]; }

">" |
"<" |
">=" |
"<=" |
"==" |
"!=" { yylval.relop = (char*)malloc(10*sizeof(char)); strcpy(yylval.relop, yytext); return RELOP; } 

"||" { return OR; }
"&&" { return AND; }
"!" { return NOT; } 

{digit}+ { yylval.id = (char*)malloc(10*sizeof(char)); strcpy(yylval.id, yytext); return INTEGER; }
[a-zA-Z][a-z0-9A-Z\_]* { yylval.id = (char*)malloc(10*sizeof(char)); strcpy(yylval.id, yytext); return ID; }
{ws}* {/*ignore it*/}
%%