#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

/* A non-terminal X is nullable if you can generate the empty word from it. */

/* A non-terminal X is generating, i.e., X =>* w, where w ϵ L(G) and w in Vt*,
   this means that the string leads to a string of terminal symbols. */

/* A non-terminal X is reachable If there is a derivation S =>* αXβ =>* w, w ϵ L(G),
   for same α and β, then X is said to be reachable. */

struct rules
{
	char var;
	vector<string> der;
	bool nullable,non_reachable,non_generating;
};
vector<rules> a;
map<char,int> m;
int n;

void insert(string s)
{
	int i;
	rules R;
	R.var = s[0];
	R.der.push_back(s.substr(1,s.length()-1));
	R.nullable = false;
	R.non_generating = true;
	R.non_reachable = true;
	if(m.find(s[0])!=m.end())
	{
		i = m[s[0]];
		if(R.der[0]=="#")
			a[i].nullable = true;
		a[i].der.push_back(R.der[0]);
	}
	else
	{
		if(R.der[0]=="#")
			R.nullable = true;
		a.push_back(R);
		m[R.var] = a.size()-1;
	}
}

void take_input()
{
	cout<<"How many productions?\n";
	cin>>n;
	string s="";
	cout<<"Enter the productions, Enter # for null\n";
	for(int i=0;i<n;i++)
	{
		cin>>s;
		insert(s);
	}
}


void filter_nullables()
{
	int itr = n;
	int f;
	while(itr--)
	{
		for(int i=0;i<a.size();i++)
		{
			if(!a[i].nullable)
			{
				for(int j=0;j<a[i].der.size();j++)
				{
					f = 0;
					for(int k=0;k<a[i].der[j].length() && !f;k++)
					{
						if(m.find(a[i].der[j][k])==m.end() && a[i].der[j][k]!='#')
							f = 1;
						else if(!a[m[a[i].der[j][k]]].nullable)
							f = 1;
					}
					if(!f)
					{
						a[i].nullable = true;
						break;
					}
				}
			}
		}
	}
}

void add_all(string s1,vector<string>& v,string s,int ind)
{
	if(ind==s1.length())
	{
		if(s=="")
			v.push_back("#");
		else
			v.push_back(s);
		return;
	}
	if(m.find(s1[ind])!=m.end())
	{
		int i = m[s1[ind]];
		if(a[i].nullable)
		{
			add_all(s1,v,s+s1[ind],ind+1);
			add_all(s1,v,s,ind+1);
		}
		else
			add_all(s1,v,s+s1[ind],ind+1);
	}
	else
		add_all(s1,v,s+s1[ind],ind+1);
}

void remove_duplicates(vector<string> &v)
{
	sort(v.begin(),v.end());
	int i = 0,j = 1,sz = v.size();
	while(j<sz)
	{
		while(j<sz&&v[j]==v[i])
			j++;
		if(j<sz)
		{
			swap(v[i+1],v[j]);
			i++;
		}
		j++;
	}
	while(v.size()!=i+1)
	{
		v.pop_back();
	}
}

void remove_null_productions()
{
	string s="";int org;
	for(int i=0;i<a.size();i++)
	{
		org = a[i].der.size();
		for(int j=0;j<org;j++)
		{
			if(a[i].der[j]!="#")
			{
				s = "";
				add_all(a[i].der[j],a[i].der,s,0);
			}
		}
		remove_duplicates(a[i].der);
	}
}

bool is_pure_terminal(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(m.find(s[i])!=m.end() || s[i]=='#')
			return false;
	}
	return true;
}

bool is_generating(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(m.find(s[i])!=m.end())
		{
			if(a[m[s[i]]].non_generating)
				return false;
		}
		else if(s[i]=='#')
			return false;
	}
	return true;
}

void filter_non_generating()
{
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<a[i].der.size();j++)
		{
			if(is_pure_terminal(a[i].der[j]))
			{
				a[i].non_generating = false;
				break;
			}
		}
	}
	int itr = n;
	while(itr--)
	{
		for(int i=0;i<a.size();i++)
		{
			for(int j=0;j<a[i].der.size();j++)
			{
				if(is_generating(a[i].der[j]))
				{
					a[i].non_generating = false;
					break;
				}
			}
		}
	}
}

bool contains_non_generating_symbol(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(m.find(s[i])!=m.end())
		{
			if(a[m[s[i]]].non_generating)
				return true;
		}
		else if(s[i]>='A'&& s[i]<='Z')
		{
			return true;
		}
		else if(s[i]=='#')
			return true;
	}
	return false;
}

void remove_non_generating_symbols()
{
	for(int i=0;i<a.size();i++)
	{
		if(!a[i].non_generating)
            for(vector<string>::iterator itr = a[i].der.begin();itr!=a[i].der.end();itr++)
            {
                if(contains_non_generating_symbol(*itr))
                {
                    itr = a[i].der.erase(itr);
                    itr--;
                }
            }
	}
}

bool contains_non_reachable_symbol(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(m.find(s[i])!=m.end())
		{
			if(a[m[s[i]]].non_reachable)
				return true;
		}
		else if(s[i]=='#')
			return true;
	}
	return false;
}


void filter_non_reachables(char c) // reachable from which charcter? the starting symbol in this case
{
	vector<char> v;
	v.push_back(c);
    int ind,f;
	set<char> checked;
	for(int i=0;i<v.size();i++)
	{
		ind = m[v[i]];
		checked.insert(v[i]);
		for(int j=0;j<a[ind].der.size();j++)
		{
			for(int k=0;k<a[ind].der[j].length();k++)
			{
				if((m.find(a[ind].der[j][k])!=m.end()) && 
                   (checked.find(a[ind].der[j][k])==checked.end()))
				{
					v.push_back(a[ind].der[j][k]);
					checked.insert(a[ind].der[j][k]);
				}
			}
		}
	}
	for(int i=0;i<a.size();i++)
	{
		if(checked.find(a[i].var)!=checked.end())
		{
			a[i].non_reachable=false;
		}
	}
}

void remove_non_reachable_symbols()
{
	for(int i=0;i<a.size();i++)
	{
		if(!a[i].non_reachable)
		for(vector<string>::iterator itr = a[i].der.begin();itr!=a[i].der.end();itr++)
		{
			if(contains_non_reachable_symbol(*itr))
			{
				itr = a[i].der.erase(itr);itr--;
			}
		}
	}
}

void add_productions(vector<string> &v,vector<string> v1)
{
	for(int i=0;i<v1.size();i++)
	{
		v.push_back(v1[i]);
	}
}

void remove_unit_productions()
{
	map<char,vector<string> > tab1,tab2;
	for(int i=0;i<a.size();i++)
	{
		if(!a[i].non_generating && !a[i].non_reachable)
            for(int j=0;j<a[i].der.size();j++)
            {
                if(a[i].der[j].length()!=1)
                {
                    tab1[a[i].var].push_back(a[i].der[j]); //RHS size>1, no not unit prod
                }
                else
                {
                    if(m.find(a[i].der[j][0])==m.end())
                        tab1[a[i].var].push_back(a[i].der[j]); //Even if size is 1, it doesn't derive anything
                    else
                        tab2[a[i].var].push_back(a[i].der[j]); //RHS size = 1 and it derives something
                }
            }
	}
	set<char> derivables;
	for(int i=0;i<a.size();i++)
	{
		if(!a[i].non_generating && !a[i].non_reachable && tab2.find(a[i].var)!=tab2.end())
		{
			a[i].der.clear();
			add_productions(a[i].der,tab1[a[i].var]);
			derivables.insert(a[i].var);
			for(int j=0;j<tab2[a[i].var].size();j++)
			{
				if(derivables.find(tab2[a[i].var][j][0])==derivables.end())
				{
					add_productions(a[i].der,tab1[tab2[a[i].var][j][0]]);
					for(int k=0;k<tab2[tab2[a[i].var][j][0]].size();k++)
						tab2[a[i].var].push_back(tab2[tab2[a[i].var][j][0]][k]);
					derivables.insert(tab2[a[i].var][j][0]);
				}
			}
			sort(a[i].der.begin(),a[i].der.end());
			remove_duplicates(a[i].der);
			derivables.clear();
		}
	}
}

void remove_left_recursion()
{
	vector<string> with_left_recursion,without_left_recursion;
	int org = a.size();
	for(int i=0;i<org;i++)
	{
		with_left_recursion.clear();
		without_left_recursion.clear();
		for(int j=0;j<a[i].der.size();j++)
		{
			if(a[i].var==a[i].der[j][0])
			{
				with_left_recursion.push_back(a[i].der[j]);
			}
			else
			{
				without_left_recursion.push_back(a[i].der[j]);
			}
		}
		if(with_left_recursion.size()>0)
		{
			rules R;
			R.non_generating = R.non_reachable = R.nullable = false;
			R.var = a[i].var-'A'+'a';
			for(int j=0;j<with_left_recursion.size();j++)
			{
				R.der.push_back(with_left_recursion[j].substr(1,with_left_recursion[j].length()-1)+a[i].var+"\'");
			}
			for(int j=0;j<without_left_recursion.size();j++)
			{
				(without_left_recursion[j]+=a[i].var)+="\'";
			}
			R.der.push_back("#");
			a.push_back(R);
			a[i].der = without_left_recursion;
		}
	}
}

void show()
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i].non_reachable||a[i].non_generating)
			continue;
		if(a[i].var>='A'&&a[i].var<='Z')
		    cout<<a[i].var<<" :: ";
		else
		    cout<<(char)(a[i].var-'a'+'A')<<"\'"<<" :: ";
		for(int j=0;j<a[i].der.size();j++)
		{
			cout<<a[i].der[j]<<" | ";
		}
		cout<<endl;
		//cout<<" "<<a[i].nullable<<" "<<a[i].non_reachable<<" "<<a[i].non_generating<<endl;
	}
}

int main()
{
	
	take_input();
    /* to remove null productions */
	filter_nullables();
	remove_null_productions();

    /* To temove non-generating symbols */
	filter_non_generating();
	remove_non_generating_symbols();

    /* To remove non-reachable symbols */
	filter_non_reachables('S');
	remove_non_reachable_symbols();

    /* To remove unit productions */
	remove_unit_productions();

    /* To remove left recursion */
	remove_left_recursion();

	show();

	return 0;
}

/*
Sa
SaA
SB
AaBB
A#
BAa
Bb
*/