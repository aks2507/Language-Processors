#include<bits/stdc++.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;
/*
Assumptions: grammar must not have any null productions, and must be free of left recusrion(otherwise computeFollow will enter in an infinite loop), Z should not be a variable in input grammar as it is treated as the input symbol of augmented grammar
*/
struct slrEntry
{
	map<char,vector<string> > action;
	map<char,int> go2;
};
vector<slrEntry> table;
vector<vector<string> > grammar(26);
map<vector<vector<pair<string,char> > >,pair<int,bool> > itsets; //lr 1 item sets
int cntitsets = 0;
vector<set<char> > first(26);


void printGr()
{
	for(int j = 0; j < 26; j++)
	{
		for(int i=0;i<grammar[j].size();i++)
			cout<<(char)(j+'A')<<" -> "<<grammar[j][i]<<"\n";
	}
	
}

void printItsets()
{
	for(map<vector<vector<pair<string,char> > >,pair<int,bool> >::iterator it=itsets.begin();it!=itsets.end();it++)
	{
		cout<<"Itemset "<<(it->second).first<<":\n";
		for(int i=0;i<26;i++)
		{
			for(int j = 0; j < (it->first)[i].size(); j++)
			{
				cout<<"["<<(char)(i+'A')<<" -> "<<(it->first)[i][j].first<<", "<<(it->first)[i][j].second<<"]\n";
			}
		}
		cout<<"\n";
	}
}
int findDot(string alp,string &befDot,string &aftDot)
{
	int pos = -1;
	for(int i=0;i<alp.size();i++)
	{
		if(alp[i] == '.')
		{
			pos = i;
			if(i+1<alp.size())
				befDot+=alp[i+1];
			i++;
			continue;
		}
		if(pos == -1)
		{
			befDot+=alp[i];
		}
		else
		{
			aftDot+=alp[i];
		}
		
	}
	return pos;
}
void addElems(set<char> &a,set<char> &b)
{	//add elements of b to a
	for(set<char>::iterator it = b.begin();it!=b.end();it++)
	{
		a.insert((*it));
	}
}
void computeFirst(int v)
{
	//cout<<"computing first of "<<(char)(v+'A')<<"\n";
	for(int i=0;i<grammar[v].size();i++)
	{
		if(isupper(grammar[v][i][0]))
		{ 
			//cout<<"case 1\n";
			if((grammar[v][i][0]-'A' == v))
			{
				//cout<<"immediate left recursion\n";
				continue;
			}
			if(first[grammar[v][i][0]-'A'].size()==0)
				computeFirst(grammar[v][i][0]-'A');
			addElems(first[v],first[grammar[v][i][0]-'A']);
		}
		else
		{
			//cout<<"case 2 terminal "<<grammar[v][i][0]<<"\n";
			first[v].insert(grammar[v][i][0]);
		}
	}
}
set<char> computeFirst(string s)
{
	if(isupper(s[0]))
		return first[s[0]-'A'];
	set<char> ret;
	ret.insert(s[0]);
	//cout<<s[0]<<" is first of beta "<<s<<"\n";
	return ret;
}
void closure(vector<vector<pair<string,char> > > &curr)
{
	bool f = 1;
	vector<set<char> > vis(26);//to indicate whether the current lr1 item has already been processed or not, int for lhs value of the production, char indicates the lookahead
	vector<vector<bool> > visset(26);
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<curr[i].size();j++)
		{
			visset[i].push_back(0);
		}
	}
	while(f)
	{
		f = 0;
		for(int i=0;i<26;i++)
		{
			if(curr[i].size()>0)
			{
				for(int j=0;j<curr[i].size();j++)
				{
					if(visset[i][j])
						continue;
					visset[i][j] = 1;
					string prod = curr[i][j].first,ad,bd;
					int pos = findDot(prod,bd,ad);//bd string contains the string before the dot and the single character after the dot
					if(pos+1<prod.size())
					{
						char x = prod[pos+1];
						if(isupper(x))
						{
							int nidx = x-'A';							
							string beta = ad;
							beta+=curr[i][j].second;
							set<char> bs = computeFirst(beta),bs2;
							for(set<char>::iterator it=bs.begin();it!=bs.end();it++)
							{
								if(vis[nidx].find((*it)) == vis[nidx].end())
								{
									bs2.insert((*it));
									vis[nidx].insert((*it));
								}
							}
							
							for(int k=0;k<grammar[nidx].size();k++)
							{
								for(set<char>::iterator it=bs2.begin();it!=bs2.end();it++)
								{
									curr[nidx].push_back(make_pair("."+grammar[nidx][k],(*it)));
									//cout<<(char)(nidx+'A')<<"->"<<prod<<" "<<(*it)<<" its closure being inserted\n";
									visset[nidx].push_back(0);
								}
							}
							//cout<<vis[nidx].size()<<" size of itset at "<<(char)(nidx + 'A')<<"\n";
							f = 1;
						}
					}
				}
			}
		}
		//sleep(2);
	}
}


void genNewItset(vector<vector<pair<string,char> > > &curr,char x,vector<vector<pair<string,char> > > &nitset)
{
	for(int i=0;i<26;i++)
	{
		if(curr[i].size()>0)
		{
			for(int j=0;j<curr[i].size();j++)
			{
				string prod = curr[i][j].first,bd,ad;
				int pos = findDot(prod,bd,ad);
				if(pos == prod.size()-1)//in case of completely traversed rhs
					continue;
				if(prod[pos+1] == x)
				{
					string nextrhs = bd+"."+ad;
					//cout<<"nextrhs "<<nextrhs<<"\n";
					nitset[i].push_back(make_pair(nextrhs,curr[i][j].second));
				}
			}
		}
	}
}


void read(vector<vector<pair<string,char> > > &curr,bool &end,int tableindex)
{
	set<char> vis; //set of processed characters
	for(int i=0;i<26;i++)
	{
		if(curr[i].size()>0)
		{
			for(int j=0;j<curr[i].size();j++)
			{
				string prod = curr[i][j].first,bd,ad;
				char b = curr[i][j].second;
				int pos = findDot(prod,bd,ad);
				if(pos == prod.size()-1)
				{//in this case, action part of itemset must be filled with reduce
				
					//for the lookahead element, we add reduce with this production in the table
					if(b == '$' && i==25)
					{
						table[tableindex].action[b].push_back("acc");
					}
					else
					{
						string ent = "R ";
						ent+=((char)(i+'A'));
						ent+="->";
						ent+=bd;
						//cout<<"Reduce entry of itemset "<<tableindex<<": "<<ent<<"\n";
						table[tableindex].action[b].push_back(ent);
					}
					continue;
				}
				char x = prod[pos+1];
				if(vis.find(x) == vis.end())
				{
					vector<vector<pair<string,char> > > nit(26);
					genNewItset(curr,x,nit);//initializes this new itemset with all rhs's with x just next to the .
					vis.insert(x);
					closure(nit);
					map<vector<vector<pair<string,char> > >,pair<int,bool> >::iterator it = itsets.find(nit);
					int transitset;
					if(itsets.find(nit) == itsets.end())
					{
						//cout<<cntitsets<<" th itset added\n";
						transitset = cntitsets;
						itsets.insert(make_pair(nit,make_pair(cntitsets++,0)));
						slrEntry e;
						table.push_back(e);
						end = 1;
						
						//printItsets();
					}
					else
						transitset = (it->second).first;
					if(isupper(x))
					{ 
						//i.e. if x is a variable, then goto of table must be filled
						table[tableindex].go2.insert(make_pair(x,transitset));
					}
					else
					{
						//i.e. it is a terminal and action part must be filled
						string tmp="S";
						tmp+=to_string(transitset);
						table[tableindex].action[x].push_back(tmp);
						//cout<<"Shift entry of itemset "<<tableindex<<": "<<tmp<<"\n";
					}
				}
			}
		}
	}
	//cout<<"GOTO performed\n";
	//sleep(3);
}
void printFirst()
{
	for(int i=0;i<26;i++)
	{
		if(first[i].size()>0)
		{
			cout<<"First("<<(char)(i+'A')<<") = ";
			for(set<char>::iterator it = first[i].begin();it!=first[i].end();it++)
				cout<<(*it)<<" ";
			cout<<"\n";
		}
	}
}
void printTable()
{
	for(int i=0;i<table.size();i++)
	{
		cout<<"State "<<i<<"\n";
		cout<<"action:\n";
		for(map<char,vector<string> >::iterator it=table[i].action.begin();it!=table[i].action.end();it++)
		{
			cout<<"("<<it->first<<", ";
			for(int j=0;j<(it->second).size();j++)
				cout<<(it->second)[j]<<" ";
			cout<<")\n";
		}
		cout<<"goto:\n";
		for(map<char,int>::iterator it=table[i].go2.begin();it!=table[i].go2.end();it++)
		{
			cout<<"("<<it->first<<","<<(it->second)<<")\n";
		}
		cout<<"\n";
	}
}

int findOp(string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i] == '+' || s[i] == '*')
			return i;
	}
	return -1;
}
//assoc = 1, implies right ; prec = 1, implies + > *
void resolveAmbiguity(bool assoc,bool prec)
{
	for(int i=0;i<table.size();i++)
	{
		for(map<char,vector<string> >::iterator it=table[i].action.begin();it!=table[i].action.end();it++){
			if((it->second).size()==2){
				int r,s;
				if((it->second)[0][0] == 'R')
				{
					r = 0;
					s = 1;
				}
				else
				{
					r = 1;
					s = 0;
				}
				int opPos = findOp((it->second)[r]);
				if((it->first) == (it->second)[r][opPos])
				{//in this case, since operators are same, we have to resolve the associativity
					if(assoc)
					{
						(it->second).erase((it->second).begin()+r);
					}
					else
					{
						(it->second).erase((it->second).begin()+s);
					}
				}
				else
				{//operators are not the same, so we have to resolve precedence
					if(prec)
					{
						if((it->first == '+') && (it->second)[r][opPos]=='*')
						{
							(it->second).erase((it->second).begin()+r);
						}
						if((it->first == '*') && (it->second)[r][opPos]=='+')
						{
							(it->second).erase((it->second).begin()+s);
						}
					}
					else
					{
						if((it->first == '+') && (it->second)[r][opPos]=='*')
						{
							(it->second).erase((it->second).begin()+s);
						}
						if((it->first == '*') && (it->second)[r][opPos]=='+')
						{
							(it->second).erase((it->second).begin()+r);
						}
					}
				}
			}
		}
	}
}
int main(int argc, char *argv[])
{
	int infd = open(argv[1],O_RDONLY);
	dup2(infd,0);
	//cout<<"Enter number of productions: ";
	int n;
	cin>>n;
	//cout<<"Enter productions:\n";
	char start='.';
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		
		if(start == '.')
		{
			start = s[0];
		}
		string prod;
		bool f = 0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i] == '-' && s[i+1] == '>')
			{
				f = 1;
				i++;
				continue;
			}
			if(f)
				prod+=s[i];
		}
		int idx = s[0]-'A';
		grammar[idx].push_back(prod);
	}
	cout<<"Augmented Grammar\n";
	fflush(stdout);
	string rhs;
	rhs+=start;
	grammar[25].push_back(rhs);
	printGr();
	//computing first of all variables
	for(int i=0;i<26;i++)
	{
		if(grammar[i].size()>0 && first[i].size()==0)
		{
			computeFirst(i);
		}
	}
	printFirst();
	vector<vector<pair<string,char> > > is0(26);
	//Taking Z to be E', start symbol of augmented grammar
	is0[25].push_back(make_pair("."+rhs,'$'));
	closure(is0);
	itsets.insert(make_pair(is0,make_pair(cntitsets++,0)));
	slrEntry e0;
	table.push_back(e0);
	
	
	//printItsets();
	bool f = 1;
	while(f)
	{
		f = 0;
		for(map<vector<vector<pair<string,char> > >,pair<int,bool> >::iterator it=itsets.begin();it!=itsets.end();it++)
		{
			//cout<<"On itemset "<<(it->second).first<<"\n";
			//sleep(2);
			if((it->second).second == 0)
			{
				vector<vector<pair<string,char> > > is = it->first;
				int idx = (it->second).first;
				read(is,f,idx);
				(it->second).second = 1;
			}
		}
		//sleep(5);
	}
	cout<<"Itemsets are\n";
	printItsets();
	resolveAmbiguity(1,1);
	cout<<"***************** Canonical LR Parsing Table ***********************\n";
	
	printTable();
	return 0;
}