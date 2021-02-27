%{
    #include <bits/stdc++.h>
    #include<string>
    using namespace std;

    stack<int> opd;
    stack<string> opr;
    unordered_map<string,int> preced;

    void set_preced();
    int str_to_decimal(string);
    int parse_whatever_remains_in_stack();
    void parse_operand(string);
    void parse_operator(string);
    int eval(int,int,string);
    
%}

%%
[0-9]+                                                           {string str(yytext); parse_operand(str);}
"+"|"-"|"*"|"/"|"|"|"&"|"\^"|"=="|">"|"<"|">="|"<="|"@"|"%"|"!=" {string str(yytext); parse_operator(str);}
.                                                                ;
%%

void set_preced() //mapping the precedance
{
    preced["|"]=preced["&"]=preced["^"]=2;
    preced["=="]=preced["!="]=0;
    preced["<="]=preced["<"]=preced[">"]=preced[">="]=1;
    preced["+"]=preced["-"]=3;
    preced["*"]=preced["/"]=preced["%"]=4;
    preced["@"]=6;
}

int str_to_decimal(string str)
{
    int num=0,n=str.length(),i=n-1;
    while(i>=0)
    {
        num+=(str[i]-'0')*pow(10,n-1-i);
        i--;
    }
    return num;
}

void parse_operand(string str) // put in stack
{
    cout<<"Putting "<<str<<" in operand stack\n";
    int num=str_to_decimal(str);
    opd.push(num);
}

void parse_operator(string str) //pop out two fron the stack and evaluate
{
    cout<<"Parsing new operator\n";
    while(!opr.empty())
    {
        string top=opr.top();
        if(preced[top]>=preced[str])
        {
            float op1=opd.top();
            opd.pop();
            float op2=opd.top();
            opd.pop();
            cout<<"poped: "<<op1<<" and "<<op2<<"\n";
            cout<<"Evaluating: "<<op2<<top<<op1<<"\n";
            opd.push(eval(op2,op1,top));
            cout<<"Pushed: "<<eval(op2,op1,top)<<" in operand stack\n";
            opr.pop();
            cout<<"Poped: "<<top<<" from operator stack\n";
        }
        else
            break;
    }
    cout<<"Pushed new operator: "<<str<<" in operator stack\n";
    opr.push(str);
}

int eval(int x,int y,string s) //evaluation of arithmetic operations
{
    if(s=="+")
        return x+y;
    else if(s=="-")
        return x-y;
    else if(s=="*")
        return x*y;
    else if(s=="/")
        return x/y;
    else if(s=="%")
        return x%y;
    else if(s=="|")
        return x|y;
    else if(s=="&")
        return x&y;
    else if(s=="^")
        return x^y;
    else if(s=="@")
        return pow(x,y);
    else if(s=="==")
        return (x==y);
    else if(s==">")
        return x>y;
    else if(s=="<")
        return x<y;
    else if(s==">=")
        return x>=y;
    else if(s=="<=")
        return x<=y;
    else if(s=="!=")
        return x!=y;
    else
        return INT_MAX;
}

int parse_whatever_remains_in_stack() //After expression ends, parse whatever is left in stack
{
    while(!opr.empty())
    {
        string top=opr.top();
        
        float op1=opd.top();
        opd.pop();
        float op2=opd.top();
        opd.pop();
        
        cout<<"poped: "<<op1<<" and "<<op2<<"\n";
        cout<<"Evaluating: "<<op2<<top<<op1<<"\n";

        opd.push(eval(op2,op1,top));
        cout<<"Pushed: "<<eval(op2,op1,top)<<" in operand stack\n";
        opr.pop();
        cout<<"Poped: "<<top<<" from operator stack\n";
    }
    return opd.top();
}

int main()
{
    yyin=fopen("input.txt","r");
    yyout=fopen("output.txt","w");
    
    set_preced();
    
    yylex();
    
    int ans=parse_whatever_remains_in_stack();
    
    fprintf(yyout,"%d",ans);
    
    cout<<"The final answer is = "<<ans<<"\n";
    
    close(fileno(yyin));
    close(fileno(yyout));
}
/*
24*34+4@3-12/4==1|6^7
*/