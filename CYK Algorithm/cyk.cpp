#include <bits/stdc++.h>
using namespace std;
int n;

void print_set(set<string> s)
{
    set<string>::iterator it;
    cout<<"( ";
    for(it=s.begin();it!=s.end();it++)
        cout<<*it<<",";
    cout<<" )   ";
}

int main()
{
    // Input the set of Rules.
    int no_of_rules; 
    cin>>no_of_rules;
    vector<pair<string , string>> rules(no_of_rules);
    // Input rules
    for(int i= 0;i<no_of_rules;i++)
    {
        cin>>rules[i].first>>rules[i].second;
    }

    // Input string.
    string str; 
    cin>>str;

    n  =  str.size();
    set<string> dp[n][n];
    
    for(int i = 0;i<n ; ++i){
        string s ;
        s += str[i];
        
        for(int j = 0;j<no_of_rules;++j){
            if(rules[j].second == s){
                dp[i][i].insert(rules[j].first);
            }
        }
    }

    
    for(int len = 2; len <= n ; len++)
    {
        for(int i = 0;i<n ; ++i)
        {
            int j = i + len - 1;
            if(j < n)
            {
                for(int k = i ; k <= j - 1; k++)
                {
                   for(int p = 0;p<no_of_rules;p++)
                   {
                        string right = rules[p].second;
                        string first_NT , second_NT;
                        if(right.size() > 1)
                        {
                            first_NT += right[0];
                            second_NT += right[1];
                            bool check1 = (dp[i][k].find(first_NT) != dp[i][k].end());
                            bool check2 = (dp[k+1][j].find(second_NT) != dp[k+1][j].end());
                            if(check1 && check2)
                            {
                                dp[i][j].insert(rules[p].first);
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            print_set(dp[i][j]);
        }
        cout<<"\n";
    }
    if(dp[0][n - 1].find("S") != dp[0][n - 1].end())
    {
        cout << "String is part of grammar\n";
    }
    else
    {
        cout << "String is not part of grammar\n";
    }

    cout<<"substrings that can be generated: \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        

            
            if(!dp[i][j].empty())
            {
                for(auto element=dp[i][j].begin();element!=dp[i][j].end();element++)
                {
                    if(*element=="S")
                    {
                        cout<<str.substr(i,j-i+1)<<"\n";
                    }
                }
            }
            
        }
    }
    return 0;
}

/*
input : 
8
S AB 
S BC 
A BA
A a
B CC
B b
C AB
C a
baaba
*/
