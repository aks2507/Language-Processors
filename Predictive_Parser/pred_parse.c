#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Rules
{
	char var;
	char der[10];
};

struct Rules* a;
int terminals[255] = {0},variables[26] = {0},n,n_var = 0,n_term = 0;

int first[26][255] = {{0}},follow[26][255] = {{0}};

int nullables[26] = {0};

int** table;

int is_nullable(char* s)
{
	char* p;
	p = s;
	while(*p!='\0')
	{
		if(*p<'A'||*p>'Z'||!nullables[*p-'A'])
			return 0;
		p++;
	}
	return 1;
}


int main(int argc, char const *argv[])
{
	if(argc<2)
	{
		printf("Usage: %s [STARTING_SYMBOL]\n",argv[0]);exit(0);
	}
	printf("Enter the no of rules\n");
	scanf("%d",&n);
	while(getchar()!='\n');
	a = (struct Rules*)malloc(sizeof(struct Rules)*n);
	for(int i=0;i<n;i++)
	{
		printf("Enter the variable\n");
		scanf("%c",&a[i].var);
		if(variables[a[i].var-'A'] != 1)
		{
			//printf("%d\n",a[i].var-'A');
			variables[a[i].var-'A'] = 1;n_var++;
		}
		while(getchar()!='\n');
		printf("Enter the derivation\n");
		scanf("%s",a[i].der);
		for(int j=0;j<strlen(a[i].der);j++)
		{
			if(a[i].der[j]!='@'&&(a[i].der[j]<'A'||a[i].der[j]>'Z')&&terminals[a[i].der[j]] != 1)
			{
				terminals[a[i].der[j]] = 1;n_term++;
			}
		}
		while(getchar()!='\n');
	}

	int no_change = 0;
	// calculating the nullables;
	do
	{
		no_change = 0;
		for(int i=0;i<n;i++)
		{
			if(a[i].der[0]=='@')
			{
				if(!nullables[a[i].var-'A'])
				{
					nullables[a[i].var-'A'] = 1;
					no_change = 1;
				}
			}
			else if(is_nullable(a[i].der))
			{
				if(!nullables[a[i].var-'A'])
				{
					nullables[a[i].var-'A'] = 1;
					no_change = 1;
				}
			}
		}

	}while(no_change);


	// calculating the firsts

	do
	{
		no_change = 0;
		for(int i=0;i<n;i++)
		{
			if(a[i].der[0]!='@')
			{
				int len = strlen(a[i].der);
				for(int j=0;j<len;j++)
				{
					if(a[i].der[j]>='A'&&a[i].der[j]<='Z')
					{
						char sto = a[i].der[j];
						a[i].der[j] = '\0';
						if(is_nullable(a[i].der))
						{
							a[i].der[j] = sto;
							for(int k=0;k<255;k++)
							{
								if(first[a[i].der[j]-'A'][k]&&!first[a[i].var-'A'][k])
								{
									first[a[i].var-'A'][k] = 1;
									no_change = 1;
								}
							}
						}
						else
						{
							a[i].der[j] = sto;break;
						}
					}
					else if(!first[a[i].var-'A'][a[i].der[j]])
					{
						first[a[i].var-'A'][a[i].der[j]] = 1;no_change = 1;break;
					}
				}
			}
		}
	}while(no_change);

	// counting the follows

	follow[argv[1][0]-'A']['$'] = 1;

	terminals['$'] = 1;

	do
	{
		no_change = 0;

		for(int i=0;i<n;i++)
		{
			if(a[i].der[0]!='@')
			{
				for(int j=strlen(a[i].der)-1;j>=0;j--)
				{
					// if the suffix is nullable

					if(a[i].der[j]>='A'&&a[i].der[j]<='Z'&&is_nullable(a[i].der+j+1))
					{
						//printf("%c : %s\n",a[i].var,a[i].der);
						for(int k=0;k<255;k++)
						{
							if(follow[a[i].var-'A'][k]&&!follow[a[i].der[j]-'A'][k])
							{
								//printf("k = %c",(char)k);
								no_change = 1;
								follow[a[i].der[j]-'A'][k] = 1;
							}
						}
					}
					if(a[i].der[j]>='A'&&a[i].der[j]<='Z')
					for(int k=j+1;k<strlen(a[i].der);k++)
					{
						char sto = a[i].der[k];
						a[i].der[k] = '\0';

						if(is_nullable(a[i].der+j+1))
						{
							a[i].der[k] = sto;
							if(sto>='A'&&sto<='Z')
							{
								for(int l=0;l<255;l++)
								{
									if(first[sto-'A'][l]&&!follow[a[i].der[j]-'A'][l])
									{
										//printf("l = %c",(char)l);
										no_change = 1;
										follow[a[i].der[j]-'A'][l] = 1;
									}
								}
							}
							else
							{
								if(!follow[a[i].der[j]-'A'][sto])
								{
									//printf("sto = %c\n",sto);
									no_change = 1;
									follow[a[i].der[j]-'A'][sto] = 1;
									break;
								}
							}
						}
						else
						{
							a[i].der[k] = sto;break;
						}
					}
				}
			}
		}
		//printf("*\n");
	}while(no_change);


	printf("\nFirsts: \n");

	for(int i=0;i<26;i++)
	{
		if(variables[i])
		{
			printf("%c : ",i+'A');
			for(int j=0;j<255;j++)
			{
				if(first[i][j])
					printf("%c,",j);
			}
			printf("\n");
		}
	}

	printf("\nFollows: \n");

	for(int i=0;i<26;i++)
	{
		if(variables[i])
		{
			printf("%c : ",i+'A');
			for(int j=0;j<255;j++)
			{
				if(follow[i][j])
					printf("%c,",j);
			}
			printf("\n");
		}
	}

	table = (int**)malloc(sizeof(int*)*26);
	for(int i=0;i<26;i++)
	{
		table[i] = (int*)malloc(sizeof(int)*255);
		for(int j=0;j<255;j++)
		{
			table[i][j] = -1;
		}
	}

	for(int i=0;i<n;i++)
	{		
		if(a[i].der[0]!='@')
		{
			int len = strlen(a[i].der);
			for(int j=0;j<len;j++)
			{
				if(a[i].der[j]>='A'&&a[i].der[j]<='Z')
				{
					char sto = a[i].der[j];
					a[i].der[j] = '\0';
					if(is_nullable(a[i].der))
					{
						a[i].der[j] = sto;
						for(int k=0;k<255;k++)
						{
							if(first[sto-'A'][k]&&table[a[i].var-'A'][k]==-1)
							{
								table[a[i].var-'A'][k] = i;
							}
							else if(first[sto-'A'][k]&&table[a[i].var-'A'][k]!=-1)
							{
								printf("Conflict while filling the predictive parsing table!\nGrammar is not LL(1)\n");
								printf("For variable %c and terminal %c tried to fill %d but found %d\n",a[i].var,k,i,table[a[i].var-'A'][k]);
							//	exit(0);
							}
						}
					}
					else
					{
						a[i].der[j] = sto;break;
					}
				}
				else
				{
					if(table[a[i].var-'A'][a[i].der[j]]==-1)
						table[a[i].var-'A'][a[i].der[j]] = i;
					else
					{
						printf("Conflict while filling the predictive parsing table!\nGrammar is not LL(1)\n");
						printf("For variable %c and terminal %c tried to fill %d but found %d\n",a[i].var,a[i].der[j],i,table[a[i].var-'A'][a[i].der[j]]);
						//exit(0);
					}
				}
			}
			if(is_nullable(a[i].der))
			{
				for(int k=0;k<255;k++)
				{
					if(follow[a[i].var-'A'][k]&&table[a[i].var-'A'][k]==-1)
						table[a[i].var-'A'][k] = i;
					else if(follow[a[i].var-'A'][k]&&table[a[i].var-'A'][k]!=-1)
					{
						printf("Conflict while filling the predictive parsing table!\nGrammar is not LL(1)\n");
						printf("For variable %c and terminal %c tried to fill %d but found %d\n",a[i].var,k,i,table[a[i].var-'A'][k]);
					//	exit(0);
					}
				}
			}
		}
		else
		{
			for(int k=0;k<255;k++)
			{
				if(follow[a[i].var-'A'][k]&&table[a[i].var-'A'][k]==-1)
					table[a[i].var-'A'][k] = i;
				else if(follow[a[i].var-'A'][k]&&table[a[i].var-'A'][k]!=-1)
				{
					printf("Conflict while filling the predictive parsing table!\nGrammar is not LL(1)\n");
					printf("For variable %c and terminal %c tried to fill %d but found %d\n",a[i].var,k,i,table[a[i].var-'A'][k]);
					//exit(0);
				}
			}
		}
		
	}

	//printing the table

	for(int i=0;i<255;i++)
	{
		if(terminals[i])
			printf("%8c",(char)i);
	}
	printf("\n");

	for(int i=0;i<26;i++)
	{
		if(variables[i])
		{
			printf("%c :: |",i+'A');
			for(int j=0;j<255;j++)
			{
				if(table[i][j]!=-1)
				{
					printf("%3c->%s |",a[table[i][j]].var,a[table[i][j]].der);
				}
				else if(terminals[j])
					printf("      |");
			}
			printf("\n");
		}
	}


	// now the parsing action!!!


	char word[100];

	printf("\nEnter a string to see the parsing action\n");

	scanf("%s",word);

	while(getchar()!='\n');
	int l = strlen(word);

	word[l] = '$';

	word[l+1] = '\0';

	char stack[500];int top = 0,curr = 0,c = 0;

	char sentencial[100];

	sentencial[0] = argv[1][0];sentencial[1] = '\0';

	printf("%s --> ",sentencial);

	stack[0] = '$';
	stack[1] = argv[1][0]; //starting symbol

	top = 2;

	while(1)
	{
		if(stack[top-1]=='$')
		{
			if(word[curr]=='$')
			{
			//	printf("%s \n",word);
				printf("parsing completed\n");exit(0);
			}
			else
			{
				printf("Error while parsing\n");exit(0);
			}
		}
		if(stack[top-1]>='A'&&stack[top-1]<='Z')
		{
			if(table[stack[top-1]-'A'][word[curr]]==-1)
			{
				printf("Error while parsing: no rule found for %c and %c\n",stack[top-1],word[curr]);exit(0);
			}
			else
			{
				char dummy[100];
				for(int i=0;i<c;i++)
				{
					dummy[i] = sentencial[i];
				}
				int len = strlen(a[table[stack[top-1]-'A'][word[curr]]].der);int f = 0;
				for(int i=0;i<len;i++)
				{
					if(a[table[stack[top-1]-'A'][word[curr]]].der[i]=='@')
					{
						//printf(" *** ");
						f = 1;
						//c++;
						break;
					}
					dummy[c+i] = a[table[stack[top-1]-'A'][word[curr]]].der[i];
				}
				if(f)
					len--;
				for(int i=c+1;i<=strlen(sentencial);i++)
				{
					dummy[len+i-1] = sentencial[i];
				}
				strcpy(sentencial,dummy);
				printf("%s --> ",sentencial);
				char sto = stack[top-1];top--;
				for(int i=len-1;i>=0;i--)
				{
					if(a[table[sto-'A'][word[curr]]].der[i]!='@')
					{
						stack[top] = a[table[sto-'A'][word[curr]]].der[i];
						top++;
					}
				}
			}
		}
		else
		{
			if(stack[top-1]!=word[curr])
			{
				printf("Error while parsing: for %c and %c\n",stack[top-1],word[curr]);exit(0);
			}
			else
			{
				top--;
				curr++;
				c++;
			}
		}
	}

	printf("\n");

	return 0;
}

/*
8
E
TA
A
+TA
A
@
T
FR
R
*FR
R
@
F
(E)
F
i
*/