%option noyywrap
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"

%}



%%
"main()" { return MAIN; }
"if" { return IF; }
"else" { return ELSE; }
"while" { return WHILE; }
"int" { return DECIMAL; }
"switch" {return SWITCH;}
"case" {return CASE;}
"default" {return DEFAULT;}

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

[0-9]+ { yylval.id = (char*)malloc(10*sizeof(char)); strcpy(yylval.id, yytext); return INTEGER; }
[a-zA-Z][a-z0-9A-Z\_]* { yylval.id = (char*)malloc(10*sizeof(char)); strcpy(yylval.id, yytext); return ID; }
[ \t\n]* ; 
%%
