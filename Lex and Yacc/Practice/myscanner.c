#include <stdio.h>
#include <stdlib.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *name[]={NULL,"db_type","db_name","db_table_prefix","db_port"};

int main(void)
{
    int ntoken,vtoken;
    ntoken=yylex();
    while(ntoken)
    {
        printf("%d\n",ntoken);
        if(yylex()!=COLON)
        {
            printf("syntax error in line %d, expected a ':' but found %s\n",yylineno,yytext);
            return 1;
        }
        vtoken=yylex();
        switch(ntoken)
        {
            case TYPE:
            case NAME:
            case TABLE_PREFIX:
                if(vtoken!=IDENTIFIER)
                {
                    printf("syntax error in line %d, expected an identifier but found %s\n",yylineno,yytext);
                    return 1;
                }
                printf("%s is set to %s\n",name[ntoken],yytext);
                break;
            case PORT:
                if(vtoken!=INTEGER)
                {
                    printf("syntax error in line %d, expected an integer but found %s\n",yylineno,yytext);
                    return 1;
                }
                printf("%s is set to %s\n",name[ntoken],yytext);
                break;
            default:
                printf("Syntax error in line %d\n",yylineno);
        }
        ntoken=yylex();
    }
    return 0;
}