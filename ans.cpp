#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int>s;
    int n;
    cin>>n;
    vector<int>v(n);
    int i;
    for(i=0;i<n;i++)
    {
        int t;
        cin>>t;
        if(t!=0)
        s.push(t);
        
    }
    i=0;
    while(!s.empty())
    {
       v[i]=s.front();
       i++;
       s.pop();
    }

    for(i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}