%option noyywrap
%x DECLARATION
%{
	#include "h1.h"
	#include "y.tab.h"
    #include<bits/stdc++.h>
	int type;
%}


%%

"main()" {return MAIN;}

"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}

"+" |
"-" |
"*" |
"/" |
"?" |
":" |
"%" |
"(" |
")" |
";" |
"{" |
"}" |
"," |
"@" {return yytext[0];}

"int" {BEGIN DECLARATION;type = 1;return INT;}
"float" {BEGIN DECLARATION;type = 2;return FLOAT;}

"==" {yylval.cmp = 1;return CMP;}
">" {yylval.cmp = 2;return CMP;}
"<" {yylval.cmp = 3;return CMP;}
">=" {yylval.cmp = 4;return CMP;}
"<=" {yylval.cmp = 5;return CMP;}
"!=" {yylval.cmp = 6;return CMP;}

"=" {yylval.assgn = 1;return ASSGN;}
"+=" {yylval.assgn = 2;return ASSGN;}
"-=" {yylval.assgn = 3;return ASSGN;}
"*=" {yylval.assgn = 4;return ASSGN;}
"/=" {yylval.assgn = 5;return ASSGN;}

"|" {yylval.bit = 1;return BIT;}
"&" {yylval.bit = 2;return BIT;}
"~" {yylval.bit = 3;return BIT;}

"&&" {yylval.log = 1;return LOG;}
"||" {yylval.log = 2;return LOG;}
"!" {yylval.log = 3;return LOG;}

[0-9]+ {yylval.d = atoi(yytext);return INTEGER;}
[0-9]*[\.][0-9]+ {yylval.f = atof(yytext);return REAL;}

<DECLARATION>[a-zA-Z]+ {yylval.s = insert(yytext);if(yylval.s!=NULL){printf("Name = %s\n",yylval.s->name);yylval.s->type = type;return ID;}else return ERR;}
<DECLARATION>"," {return ',';}
<DECLARATION>";" {BEGIN INITIAL;return ';';}
[a-zA-Z]+ {yylval.s = search(yytext);if(yylval.s!=NULL)return ID;else return ERR;}
[ \t\n]+ ;

%%