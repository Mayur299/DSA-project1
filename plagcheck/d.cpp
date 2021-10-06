#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int* arr=new int[n];
    int i;
    //int a=0;
    long long sum=0;
    int maxx=INT_MIN;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        maxx=max(maxx,arr[i]);
    }
    int k;
    cin>>k;
    long long l,r,m;
    l=maxx;
    r=sum;
    while(l<r)
    {
        m=(l+r)/2;
        int s=0;
        int part=0;
        i=0;
        while(i<n)
        {
            if(s+arr[i]<=m)
                s+=arr[i];
            else
            {
                s=arr[i];
                part++;
            }
            i++;
                
        }
       part>k-1?l=m+1:r=m;          
    }
    cout<<l;
    
    
    return 0;
}
