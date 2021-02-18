%option noyywrap nodefault case-insensitive

%{
	#define MAX 500
	struct stack
	{
		int top;
		char* elements[MAX];
	};
	struct stack s;
	void push(struct stack* s,char* token);
	char* pop(struct stack* s);
	struct queue
	{
		int f,r;
		char* elements[MAX];
	};
	struct queue q;
	int precedance(char* op);
	void enqueue(struct queue* q,char* token);
	void insert_operand(char* token);
	void insert_operator(char* token);
	void handle_braces(char* token);
	void print(struct queue* q);
	void print_stack(struct stack* s);
%}

%%

[0-9]+ 		        { printf("%s\n",yytext);insert_operand(yytext);print_stack(&s);print(&q);}
[\+\-\*\/\@] |
um 		            { printf("%s\n",yytext);insert_operator(yytext);print_stack(&s);print(&q);}
[\(\)] 	            { printf("%s\n",yytext);handle_braces(yytext);print_stack(&s);print(&q);}
.                   ;
\n                  ;

%%

void push(struct stack* s,char* token)
{
	if(s->top==MAX-1)
	{
		printf("Stack overflow\n");
		exit(0);
	}
	else
	{
		s->top++;
		s->elements[s->top] = NULL;
		s->elements[s->top] = (char*)malloc(sizeof(char));
		strcpy(s->elements[s->top],token);
	}
}

char* pop(struct stack* s)
{
	return s->elements[s->top--];
}

void enqueue(struct queue* q,char* token)
{
	if((q->r+1)%MAX==q->f)
	{
		printf("Queue full\n");
		exit(0);
	}
	q->r = (q->r+1)%MAX;
	if(q->f==-1)
	q->f = 0;
	q->elements[q->r] = NULL;
	q->elements[q->r] = (char*)malloc(sizeof(char));
	strcpy(q->elements[q->r],token);
}
void print_stack(struct stack* s)
{
	printf("stack = ");
	for(int i=0;i<=s->top;i++)
	{
		printf("%s ",s->elements[i]);
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

void insert_operand(char* token)
{
	enqueue(&q,token);
}

void insert_operator(char* token)
{
	int p = precedance(token);
	while(s.top!=-1 && precedance(s.elements[s.top])<p)
	{
		enqueue(&q,pop(&s));
		free(s.elements[s.top+1]);
	}
	push(&s,token);
}

void handle_braces(char* token)
{
	if(strcmp(token,"(")==0)
	{
		push(&s,token);
	}
	else
	{
		while(s.top!=-1 && strcmp(s.elements[s.top],"(")!=0)
		{
			enqueue(&q,pop(&s));
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

void print(struct queue* q)
{
	printf("queue = ");
	
    if(q->f==-1&&q->r==-1)
	{
		printf("\n");
	    return;
    }
	
    for(int i=q->f;i!=q->r;i=(i+1)%MAX)
	{
		fprintf(yyout,"%s ",q->elements[i]);
	}
	
    fprintf(yyout,"%s ",q->elements[q->r]);
	
    printf("\n");
}

int main(int argc,char* argv[])
{
	s.top = q.f = q.r = -1;
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
		enqueue(&q,pop(&s));
	}
	printf("Final Output:\n");
	print(&q);
	return 0;
}
/*
12+32/4
12*10+23
(12+32)/4
*/