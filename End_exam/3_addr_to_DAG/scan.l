%{
	#include<bits/stdc++.h>
	using namespace std;
	#include "y.tab.h"
%}

%%
"true"												yylval.str=strdup(yytext);return TRUE;
"false"												yylval.str=strdup(yytext);return FALSE;
"if"												yylval.str=strdup(yytext);return IF;
"else"												yylval.str=strdup(yytext);return ELSE;
"while"												yylval.str=strdup(yytext);return WHILE;
"int"|"float"|"char"								yylval.str=strdup(yytext);return TYPE;
[a-zA-Z_][a-zA-Z0-9_]* 								yylval.str=strdup(yytext);return ID;
([0-9]*\.?[0-9]*)|(\".*?\")|(\'.\')					yylval.str=strdup(yytext);return VAL;
"&&"												yylval.str=strdup(yytext);return AND;
"||"												yylval.str=strdup(yytext);return OR;
"!"													yylval.str=strdup(yytext);return NOT;
"<"													yylval.str=strdup(yytext);return LT;
">"													yylval.str=strdup(yytext);return GT;
"=="												yylval.str=strdup(yytext);return EQQ;
"<="												yylval.str=strdup(yytext);return LTE;
">="												yylval.str=strdup(yytext);return GTE;
"+"													yylval.str=strdup(yytext);return PL;
"-"													yylval.str=strdup(yytext);return MI;
"*"													yylval.str=strdup(yytext);return MUL;
"/"													yylval.str=strdup(yytext);return DIV;
"("													yylval.str=strdup(yytext);return OP;
")"													yylval.str=strdup(yytext);return CL;
"{"													yylval.str=strdup(yytext);return OCB;
"!="												yylval.str=strdup(yytext);return NTE;
"}"													yylval.str=strdup(yytext);return CCB;
"["													yylval.str=strdup(yytext);return OSB;
"]"													yylval.str=strdup(yytext);return CSB;
"="													yylval.str=strdup(yytext);return EQ;
","													yylval.str=strdup(yytext);return COMMA;
";"													yylval.str=strdup(yytext);return SEMICOLON;
[\n \t]+											;
%%