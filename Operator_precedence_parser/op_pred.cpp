#include <bits/stdc++.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
    /*
    * ------------------------------------------------
    * ----------------------------------------
    * Taking grammar input from the user and storing it
    * ----------------------------------------
    * ------------------------------------------------
    */
	cout<<"How many rules?\n";
	cin>>n;
	vector<pair<char,string> > v; //Grammar rules
	set<char> st; //Set of all unique variables 

	map<char,int> reverse_dictionary;

	char c;string s;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the variable and derived string\n";
		cin>>c>>s;
		if(s.length()==1)
			reverse_dictionary[s[0]] = i;
		else
		    reverse_dictionary[s[1]] = i;
		v.push_back(make_pair(c,s));
		st.insert(c);
		for(int j=0;j<s.length();j++)
			st.insert(s[j]);
	}

	st.insert('$');

    /*
    * ------------------------------------------------
    * ----------------------------------------
    * Taking input from the user for Operator precedance
    * and creting the Operator Precedance table
    * ----------------------------------------
    * ------------------------------------------------
    */
	cout<<"Enter the operator precedance table"<<"\n";

	set<char>::iterator itr1,itr2;

	itr1 = st.begin();

	map<pair<char,char>,char> tab; //Operator precedance table

	while(itr1!=st.end())
	{
		itr2 = st.begin();
		while(itr2!=st.end())
		{
			cout<<"( "<<*itr1<<","<<*itr2<<" ) : ";
			cin>>tab[make_pair(*itr1,*itr2)];
			itr2++;
		}
		itr1++;
	}

	string dummy="",word="";

	cout<<"Enter a word to see the parsing action"<<"\n";
    /*
    * ------------------------------------------------
    * ----------------------------------------
    * Parsing of a word, done using the Operator Precedance table
    * ----------------------------------------
    * ------------------------------------------------
    */

	cin>>dummy;

	word+="$";

	for(int i=0;i<dummy.length();i++)
	{
		char cc = tab[make_pair(word.back(),dummy[i])];
		if(cc=='X')
		{
			cout<<"Invalid input\n";
            exit(1);
		}
		word+=cc;
		word+=dummy[i];
	}

	word+=tab[make_pair(word.back(),'$')];
	word+="$";

	cout<<"word = "<<word<<"\n";
	int curr = 0,curr1;
	while(1)
	{
		curr = 0;
		while(curr<word.length()&&word[curr]!='>')
			curr++;
		if(word[curr]=='>')
		{
			curr1 = curr-1;
			while(curr1>=0&&word[curr1]!='<')
				curr1--;
			string handle="",new_string= "";
			for(int i=curr1+1;i<curr;i++)
			{
				if(word[i]!='>'&&word[i]!='<'&&word[i]!='=')
				{
					handle+=word[i];
				}
			}
			cout<<"handle = "<<handle<<"\n";
			int rule = reverse_dictionary[handle[0]];
			cout<<v[rule].first<<" -> "<<v[rule].second<<"\n";
			for(int i=0;i<curr1;i++)
				new_string+=word[i];
			char add = tab[make_pair(new_string.back(),word[curr+1])];
			if(add!='X')
			new_string+=add;
			for(int i=curr+1;i<word.length();i++)
				new_string+=word[i];
			word = new_string;
			cout<<"word = "<<word<<"\n";
			if(word=="$$")
			{
				cout<<"Accepted\n";exit(0);
			}
			sleep(1);
		}

	}
	return 0;
}

/*
2
E
E+E
E
i
X
<
<
<
>
>
<
<
>
>
X
X
>
>
X
X
( $,$ ) : X
( $,+ ) : <
( $,E ) : <
( $,i ) : <
( +,$ ) : >
( +,+ ) : >
( +,E ) : =
( +,i ) : <
( E,$ ) : >
( E,+ ) : =
( E,E ) : X
( E,i ) : X
( i,$ ) : >
( i,+ ) : >
( i,E ) : X
( i,i ) : X

*/