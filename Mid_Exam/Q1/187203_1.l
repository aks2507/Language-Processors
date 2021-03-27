%{

#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void cases(string text);

%}

%%

[0-9]*00                 {printf("Case-1: String ending in 00 accepted --> %s\n",yytext);}
[0-9]*[222]{3}[0-9]*     {printf("Case-2: String with 3 consecutive 222's accepted --> %s\n",yytext);}
[0-9]*1[0-9]{9}          {printf("Case-5: String having 10th symbol from th1 right as 1 accepted --> %s\n",yytext);}
[0-9]*                   {cases(yytext);}
.                        {printf("Unrecognized\n");}

%%

bool sum_cond(string s)
{
    if((s[0]-'0')+(s[1]-'0')+(s[2]-'0')+(s[3]-'0')==9)
        return true;
    return false;
}
bool ascending_cond(string s)
{
    return (s[0]<=s[1] && s[1]<=s[2] && s[2]<=s[3]);
}
void cases(string text)
{
    string s=text;
    if(s[0]=='1' && s[1] == s[2])
    {
        cout<<"Case-4: String starting with 1 and has 2 consecutive same symbols accepted --> "<<s<<"\n";
    }
    else
    {
        if(s.length()==4)
        {
            if(sum_cond(s))
                cout<<"Case-6: 4 digit string with sum of digits = 9 accepted --> "<<s<<"\n";
            else if(ascending_cond(s))
                cout<<"Case-7: 4 digit string with ascending digits from left to right accepted --> "<<s<<"\n";
        }
        else
        {
            int flag=0;
            for(int i=0;i<=s.length()-5;i++)
            {
                string str=s.substr(i,5);
                int count=0;
                for(auto x:str)
                {
                    if(x=='5')
                        count++;
                }
                if(count<2)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<"Case-3: String with every block of 5 consecutive symbols containing at least 2 5's accepted --> "<<s<<"\n";
            }
        }
    }
}

int main()
{
    FILE *yyin;
	yyin = fopen("inp.txt","r");
	yylex();
    return 0;
}