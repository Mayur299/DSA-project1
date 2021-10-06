#include<iostream>
using namespace std;



    

template <typename T>
   T** input()
   {
    T **arr;
    T **sparse;
    int  r;
    int  c;
    cin>>r>>c;
    arr=new T*[r];
    int i,j;
    for(i=0;i<r;i++)
    {
        arr[i]=new T[c];
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }

    int count=0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
                count++;
            }
        }
    }
    sparse=new T*[count+1];
    for(i=0;i<=count;i++)
    sparse[i]=new T[3];
    sparse[0][0]=r;
    sparse[0][1]=c;
    sparse[0][2]=count;

    int k=1;


    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
               sparse[k][0]=i;
               sparse[k][1]=j;
               sparse[k][2]=arr[i][j];
               k++;
            }
        }
    }
    return sparse;

    

   }

template <typename T>
   void output(T** sparse)
   {
       int r=sparse[0][0];
       int c=sparse[0][1];
       int count=sparse[0][2];
       T **arr;
        int i,j;
        arr=new T*[r];
    
        for(i=0;i<r;i++)
        {
        arr[i]=new T[c];
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                arr[i][j]=0;
            }
        }
       for(int i=1;i<=count;i++)
       {
           arr[int(sparse[i][0])][int(sparse[i][1])]=sparse[i][2];
       }

       for(i=1;i<=count;i++)
       {
           for(j=0;j<3;j++)
           {
               cout<<sparse[i][j]<<" ";
           }
           cout<<endl;
       }


      /* for(i=0;i<r;i++)
       {
           for(j=0;j<c;j++)
           {
               cout<<arr[i][j]<<" ";
           }
           cout<<endl;
       } */

   }

   template <typename T>
   T** transpose(T** s)
   {
        int* cc= new int[int(s[0][1])];
        int i;
        for(i=0;i<s[0][1];i++)
        {
             cc[i]=0;
        }
        for(i=1;i<=s[0][2];i++)
        {
             cc[int(s[i][1])]++;
        }
        int* ind=new int[int(s[0][1])+1];
        ind[0]=1;
        for(i=1;i<=int(s[0][1]);i++)
        ind[i]=ind[i-1]+cc[i-1];

        T** sparse=new T*[int(s[0][2])+1];
        for(i=0;i<=int(s[0][2]);i++)
        sparse[i]=new T[3];
        sparse[0][0]=s[0][1];
        sparse[0][1]=s[0][0];
        sparse[0][2]=s[0][2];

        for(i=1;i<=int(s[0][2]);i++)
        {  int k=s[i][1];
           sparse[ind[k]][1]=s[i][0];
           sparse[ind[k]][2]=s[i][2];
           sparse[ind[k]][0]=k;

           ind[k]+=1;
        }

        return sparse;

   }

   template <typename T>
   T** add(T** p,T** q)

   {
        T** s=new T*[int(p[0][2])+int(q[0][2])+1];
        int i,j,k;
        for(i=0;i<=(int(p[0][2])+int(q[0][2]));i++)
        {
            s[i]=new T[3];
        }
        s[0][0]=p[0][0];
        s[0][1]=p[0][1];
        i=1;
        j=1;
        k=1;
        while(i<=int(p[0][2])&&j<=int(q[0][2]))
        {
            if(int(p[i][0])<int(q[j][0]))
            {
                s[k][0]=p[i][0];
                s[k][1]=p[i][1];
                s[k][2]=p[i][2];
                i+=1;
                k+=1;
            }

            else if(int(p[i][0])>int(q[j][0]))
            {
                s[k][0]=q[j][0];
                s[k][1]=q[j][1];
                s[k][2]=q[j][2];
                j+=1;
                k+=1;
            }

            else
            {
                if(int(p[i][1])<int(q[j][1]))
                {
                    s[k][0]=p[i][0];
                    s[k][1]=p[i][1];
                    s[k][2]=p[i][2];
                    i+=1;
                    k+=1;
                }

                else if(int(p[i][1])>int(q[j][1]))
                {
                    s[k][0]=q[j][0];
                    s[k][1]=q[j][1];
                    s[k][2]=q[j][2];
                    j+=1;
                    k+=1;
                }

                else
                {   if((p[i][2]+q[j][2])!=0)                                               

                    {
                    s[k][0]=p[i][0];
                    s[k][1]=p[i][1];
                    s[k][2]=p[i][2]+q[j][2];
                    k++;
                    }
                    i++;
                    j++;
                
                    
                }

            }
        }

        if(i<=int(p[0][2]))
        {
            while(i<=int(p[0][2]))
            {
                    s[k][0]=p[i][0];
                    s[k][1]=p[i][1];
                    s[k][2]=p[i][2];
                    i+=1;
                    k+=1;
            }
        }

        if(j<=int(q[0][2]))
        {
            while(j<=int(q[0][2]))
            {
                s[k][0]=q[j][0];
                s[k][1]=q[j][1];
                s[k][2]=q[j][2];
                j+=1;
                k+=1;
            }
        }

        k=k-1;
        s[0][2]=k;


       /* cout<<p[0][0]<<endl;
        cout<<p[0][1]<<endl;
        cout<<p[0][2]<<endl;
        cout<<q[0][0]<<endl;
        cout<<q[0][1]<<endl;
        cout<<q[0][2]<<endl;
        cout<<s[0][0]<<endl;
        cout<<s[0][1]<<endl;
        cout<<s[0][2]<<endl;  */

        return s;
   }





   template <typename T>
   T** mul(T** p,T** q)
   {
       //T**q=transpose(q1);
       T** s=new T*[int(p[0][0])*int(q[0][0])+1];
        int i;
        for(i=0;i<=(int(p[0][0])*int(q[0][0]));i++)
        {
            s[i]=new T[3];
        }
        s[0][0]=p[0][0];
        s[0][1]=q[0][0];

        /*cout<<p[0][0]<<endl;
        cout<<p[0][1]<<endl;
        cout<<q[0][0]<<endl;
        cout<<q[0][1]<<endl;
        cout<<s[0][0]<<endl;
        cout<<s[0][1]<<endl;*/

        i=1;
        int j=1;
        int k=1;
        while(i<=int(p[0][2]))
        {   int x=int(p[i][0]);
             j=1;
            while(j<=int(q[0][2]))
            {
                T res=0;
                int pi=i;
                int qj=j;
                int y=int(q[j][0]);
                while(pi<=int(p[0][2])&&qj<=int(q[0][2])&&int(p[pi][0])==x&&int(q[qj][0])==y)
                {
                    if(int(p[pi][1])<int(q[qj][1]))
                    pi++;
                    else if(int(p[pi][1])>int(q[qj][1]))
                    qj++;
                    else
                    {
                    res+=p[pi][2]*q[qj][2];
                    pi++;
                    qj++;
                    }

                }
                if(res!=0)
                {
                s[k][0]=p[i][0];
                s[k][1]=q[j][0];
                s[k][2]=res;
                k++;
                }
                while(j<=int(q[0][2])&&int(q[j][0])==y)
                j++;


            }

            while(i<=int(p[0][2])&&int(p[i][0])==x)
                i++;


        }

        k--;
        s[0][2]=k;
        return s;
   }

   




    





int main()
{   
     //output<int>(transpose(input<int>()));                   //uncomment this part for transpose
     


     /*
     float**a=input<float>();
     float**b=input<float>();
     float**tb=transpose<float>(b);                         // uncomment this part for multiplication 
     float**ans=mul<float>(a,tb);
     output<float>(ans);           
*/



      /*
     float**a=input<float>();
     float**b=input<float>();
     float**ans=add<float>(a,b);                             //uncomment this part for addtion
     output<float>(ans);    
     */        


     return 0;



    
}