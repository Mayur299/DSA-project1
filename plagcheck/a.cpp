#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    int* arr=new int[n];
    int* copy=new int[n];
    unordered_map<int,int> m;
    int i;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            copy[i]=arr[i];
            m[arr[i]]=i;
        }
    //unordered_map<int,int>m;
    sort(copy,copy+n);
    int c=0;
    
    for(i=0;i<n;i++)
    {
        if(arr[i]!=copy[i])
        {
            c++;
            int k=arr[i];
            arr[m[copy[i]]]=arr[i];
            m[k]=m[copy[i]];
            m[copy[i]]=i;
            arr[i]=copy[i];
            
        }
    }
    
    
    cout<<c;
    return 0;
}
