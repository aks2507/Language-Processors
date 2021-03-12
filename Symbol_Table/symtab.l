%option noyywrap yylineno nodefault case-insensitive
%{
    struct ref
    {
        char* filename;
        int line;
        struct ref* next;
    };
    struct Symtab
    {
        char* word;
        struct ref* ptr;
        int num;
    };
    #define NHASH 211
    struct Symtab hashtab[NHASH];
    int hash(char* word);
    int insert(char* word);
    char* curr_file;
    void add_end(struct ref** ptr,char* filename,int line);
    void init();
    void show();
    int num_elements;
%}

%%

a |
an |
are |
is |
was |
were |
in |
the |
up |
at |
on |
am |
down |
there |
this |
that |
those |
these |
between |
near |
to                      ;
[a-z]+(\'(s|t))?        { insert(yytext);}
<<EOF>>                 { yyterminate();}
\n                      ;
.                       ;

%%

int hash(char* word)
{
	int n = strlen(word),h = 0;
	for(int i=0;i<n;i++)
	{
		h = (h*10+((int)(word[i])*(i+1))%NHASH)%NHASH;
	}
	return h;
}

void add_end(struct ref** ptr,char* filename,int line)
{
	if(*ptr==NULL)
	{
		*ptr = (struct ref*)malloc(sizeof(struct ref));
		(*ptr)->filename = NULL;
		(*ptr)->filename = (char*)malloc(sizeof(char));
		strcpy((*ptr)->filename,filename);
		(*ptr)->line = line;
		(*ptr)->next = NULL;
	}
	else
	{
		struct ref* q;
		q = *ptr;
		while(q->next!=NULL)
		{
			q = q->next;
		}
		q->next = (struct ref*)malloc(sizeof(struct ref));
		q->next->filename = NULL;
		q->next = (struct ref*)malloc(sizeof(struct ref));
		q->next->filename = (char*)malloc(sizeof(char));
		strcpy(q->next->filename,filename);
		q->next->line = line;
		q->next->next = NULL;
	}
}

int insert(char* word)
{
	if(num_elements==NHASH)
	{
		printf("No Space available\n");
		yyterminate();
	}
	int h = hash(word),f = 0;
	while(hashtab[h].ptr!=NULL)
	{
		if(hashtab[h].word!=NULL&&strcmp(hashtab[h].word,word)==0)
		{
			f = 1;
			break;
		}
		h = (h+1)%NHASH;
	}
	hashtab[h].num++;
	add_end(&hashtab[h].ptr,curr_file,yylineno);
	if(!f)
	{
		hashtab[h].word = NULL;
		hashtab[h].word = (char*)malloc(sizeof(char));
		strcpy(hashtab[h].word,word);
		num_elements++;
	}
	return 1;
}
void init()
{
	for(int i=0;i<NHASH;i++)
	{
		hashtab[i].word = NULL;
		hashtab[i].ptr = NULL;
		hashtab[i].num = 0;
	}
	num_elements = 0;
}
void show()
{
	for(int i=0;i<NHASH;i++)
	{
		if(hashtab[i].num!=0)
		{
			printf("%s : %d\n",hashtab[i].word,hashtab[i].num);
			struct ref* q = hashtab[i].ptr;
			while(q!=NULL)
			{
				printf("		%s : %d\n",q->filename,q->line);
				q = q->next;
			}
		}
	}
}
int main(int argc,char* argv[])
{
	init();
	curr_file = NULL;
	curr_file = (char*)malloc(sizeof(char));
	if(argc==1)
	{
		strcpy(curr_file,"STDIN");
		yylex();
	}
	else
	{
		for(int i=1;i<argc;i++)
		{
			yyin = fopen(argv[i],"r");
			if(yyin==NULL)
			{
				perror("File not opened");
			}
			else
			{
				strcpy(curr_file,argv[i]);
				yylex();
			}
		}
	}
	show();
	return 0;
}