#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<iostream>
using namespace std;

int main()
{
    int f;
    f=open("file.txt",O_RDWR);
    cout<<f<<endl;
       
    return 0;
}