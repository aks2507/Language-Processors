%{

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

%}

%%

auto|main|include|using|namespace|std|double|unsigned|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|continue|for|signed|void|do|if|static|while|default|goto|volatile|const|float|short     {ECHO; printf("\t\tKeyword\n");}
cin|cout|max|min|printf|scanf|sort|open|close {ECHO; printf("\t\tLibrary functions\n");} 						
iostream|stdio|stdlib|unistd|string|algorithm {ECHO; printf("\t\tHeader file\n");}
fork|execv|mkfifo|system|pipe|popen|socket|listen|bind|accept|send|receive|open|read|write|shmget {ECHO; printf("\t\tSystem Calls\n");}
[a-z|A-Z]+[0-9]*[a-z|A-Z]+[(][a-z]*[)]      {ECHO; printf("\t\tFunction call\n");}
\\n|\\t        {ECHO; printf("\t\tEscape Characters\n");}
["]([^"\n]|\\(.|\n))*["]  {ECHO; printf("\t\tString\n");}
[/]{1}[/]{1}[ a-zA-Z0-9]*                {ECHO; printf("\t\tSingle Line Comment\n");}
[/]{1}[*]{1}[ a-zA-Z0-9]*[*]{1}[/]{1}        {ECHO; printf("\t\tMultiLine Comment\n");}
[{};,()\[\]]   {ECHO; printf("\t\tSeperator\n");}						
(<|>|<=|>=|==|!=) {ECHO; printf("\t\tRelOP\n");}
[+-/=*%<>]       {ECHO; printf("\t\tOperator\n");}
[@$#]           {ECHO; printf("\t\tSpecial Character\n");}						
([a-zA-Z][0-9])+|[a-zA-Z]+ {ECHO; printf("\t\tIdentifier\n");}
[0-9]+e[0-9]+           {ECHO; printf("\t\tScientific number\n");}
[-+]?[0-9]*[.][0-9]+          {ECHO; printf("\t\tReal number\n");}
[0-9]+                 {ECHO; printf("\t\tPositive number\n");}
-[0-9]+                  {ECHO; printf("\t\tNegative number\n");}
'[a-zA-Z0-9]'       {ECHO; printf("\t\tCharacter\n");}
.|\n ; 

%%

int main()
{
    FILE* yyin;
    yyin = fopen("inp.txt","r");
    yylex();
    return 0;
}