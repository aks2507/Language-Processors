%option noyywrap nodefault case-insensitive

%{
	#define MAX 500
	#include <math.h>
	struct btnode
	{
		int type;
		void* ele;
		struct btnode* left,*right;
	};
	struct stack
	{
		int top;
		int type[MAX];
		void* elements[MAX];
	};
	struct stack s,s1;
	void push(struct stack* s,void* token,int t1);
	void* pop(struct stack* s);
	int precedance(char* op);
	void insert_operand(int token);
	void insert_operator(char* token);
	void handle_braces(char* token);
	void print_stack(struct stack* s);
	void create(char* op);
	int eval(struct btnode* t);
%}

%%

[0-9]+ 		        { printf("%s\n",yytext);insert_operand(atoi(yytext));print_stack(&s);}
[\+\-\*\/\@] |
um 		            { printf("%s\n",yytext);insert_operator(yytext);print_stack(&s);}
[\(\)] 	            { printf("%s\n",yytext);handle_braces(yytext);print_stack(&s);}
.                   ;
\n                  ;

%%

void push(struct stack* s,void* token,int t1)
{
	if(s->top==MAX-1)
	{
		printf("Stack overflow\n");
		exit(0);
	}
	else
	{
		s->top++;
		s->type[s->top] = t1;
		if(t1==1)
		{
			s->elements[s->top] = NULL;
			s->elements[s->top] = (void*)malloc(sizeof(char));
			strcpy((char*)s->elements[s->top],token);
		}
		else
		{
			s->elements[s->top] = NULL;
			s->elements[s->top] = (void*)token;
		}
	}
}

void* pop(struct stack* s)
{
	return s->elements[s->top--];
}

void print_stack(struct stack* s)
{
	printf("stack = ");
	for(int i=0;i<=s->top;i++)
	{
		printf("%s ",(char*)s->elements[i]);
	}
	printf("\n");
}

int precedance(char* op)
{
	if(!strcmp(op,"um"))
	    return 1;
	else if(!strcmp(op,"@"))
	    return 2;
	else if(!strcmp(op,"/"))
	    return 3;
	else if(!strcmp(op,"*"))
	    return 4;
	else if(!strcmp(op,"+"))
	    return 5;
	else if(!strcmp(op,"-"))
	    return 6;
	else
	    return 100;
}

void insert_operand(int token)
{
	struct btnode* t=NULL;
	t = (struct btnode*)malloc(sizeof(struct btnode));
	t->type = 1;
	t->left = NULL;
	t->right = NULL;
	t->ele = NULL;
	t->ele = (int*)malloc(sizeof(int));
	*(int*)(t->ele) = token;
	push(&s1,(void*)t,2);
}

void create(char* op)
{
	struct btnode* t1,*t2,*t;
	if(strcmp(op,"um")==0)
	{
		t1 = (struct btnode*)pop(&s1);
		t = NULL;
		t = (struct btnode*)malloc(sizeof(struct btnode));
		t->type = 2;
		t->left = t1;
		t->right = NULL;
		t->ele = NULL;
		t->ele = (char*)malloc(sizeof(char));
	}
	else
	{
		t1 = (struct btnode*)pop(&s1);
		t2 = (struct btnode*)pop(&s1);
		t = NULL;
		t = (struct btnode*)malloc(sizeof(struct btnode));
		t->type = 2;
		t->left = t2;
		t->right = t1;
		t->ele = NULL;
		t->ele = (char*)malloc(sizeof(char));
	}
	strcpy((char*)(t->ele),op);
	push(&s1,(void*)t,2);
}

void insert_operator(char* token)
{
	int p = precedance(token),p1,f;
	f = (int)(strcmp(token,"@")==0);
	while(s.top!=-1 && (p1 = precedance((char*)s.elements[s.top]))<=p)
	{
		if(f && p1==p)
		    break;
		create((char*)pop(&s));
		free(s.elements[s.top+1]);
	}
	push(&s,token,1);
}

void handle_braces(char* token)
{
	if(strcmp(token,"(")==0)
	{
		push(&s,token,1);
	}
	else
	{
		while(s.top!=-1 && strcmp((char*)s.elements[s.top],"(")!=0)
		{
			create((char*)pop(&s));
			free(s.elements[s.top+1]);
		}
		if(s.top==-1)
		{
			printf("Paranthesis mismatch\n");
			exit(0);
		}
		else
		{
			pop(&s);
		}
	}
}

void* column_wise_printing(struct btnode* t,int s)
{
	if(t!=NULL)
	{
		if(t->type==1)
		{
			for(int i=0;i<s;i++)
				printf(" ");
			printf("%d\n",(*(int*)(t->ele)));
		}
		else
		{
			for(int i=0;i<s;i++)
				printf(" ");
			printf("%s\n",(char*)(t->ele));
			column_wise_printing(t->left,s+5);
			column_wise_printing(t->right,s+7);
		}
	}
}

void postorder(struct btnode* t)
{
	if(t!=NULL)
	{
		if(t->type==1)
		{
			printf("%d ",(*(int*)(t->ele)));
		}
		else
		{
			postorder(t->left);
			postorder(t->right);
			printf("%s ",(char*)(t->ele));
		}
	}
}

int eval(struct btnode* t)
{
	if(t!=NULL)
	{
		if(t->type==1)
		{
			return *(int*)(t->ele);
		}
		else
		{
			int l = eval(t->left);
			int r = eval(t->right);
			if(!strcmp((char*)t->ele,"um"))
			    return --l;
			else if(!strcmp((char*)t->ele,"@"))
			    return (int)pow(l,r);
			else if(!strcmp((char*)t->ele,"/"))
			    return (l/r);
			else if(!strcmp((char*)t->ele,"*"))
			    return (l*r);
			else if(!strcmp((char*)t->ele,"+"))
			    return (l+r);
			else if(!strcmp((char*)t->ele,"-"))
			    return (l-r);
			else
			    return 0;
		}
	}
	return 0;
}


int main(int argc,char* argv[])
{
	s.top = s1.top = -1;
	if(argc>1)
	{
		yyin = fopen(argv[1],"r");
		if(yyin==NULL)
		{
			perror("File not opened");
			exit(0);
		}
	}
	yylex();
	while(s.top!=-1)
	{
		create(pop(&s));
	}
	struct btnode* t = (struct btnode*)pop(&s1);
	printf("The expression tree = \n");
	column_wise_printing(t,0);
	printf("The postfix expression = ");
	postorder(t);
	printf("\nValue of expression = %d\n",eval(t));
	return 0;
}