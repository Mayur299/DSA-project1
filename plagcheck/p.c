#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
//using namespace std;

int main()
{
    int f;
    f=open("file.txt",O_RDWR);
    printf("%d",f);
       
    return 0;
}