#include<bits/stdc++.h>
using namespace std;

struct newnum
{
	
	int num[3000];
    int l;

		int comp (const newnum &x,const newnum &y)
        {
		    if(x.l>y.l)
            return 0;
		    if(y.l>x.l)
            return 1;
            int i;
		    for(i=x.l;i>=1;--i)
            {   
			    if(x.num[i]<y.num[i])
                return 1;
			    if(y.num[i]<x.num[i])
                return 0;
		    }
		    return 2;
	    }


        bool operator >(const newnum &b)
        { 
            int f=comp(*this,b);
            return(f==0);
        }
	
	    bool operator <=(const newnum &b)
        {   
            int f=comp(*this,b);
            return(f==1 || f==2);
        }
	
	    bool operator >=(const newnum &b)
        {   
            int f=comp(*this,b);
            return(f==0 || f==2);
        }

        newnum operator=(const newnum &b)
        { 

            int i;
		    for(i=b.l+1;i<=l;++i)
            {
            num[i]=0;
            }
		    for(i=1;i<=b.l;++i)
            {
            num[i]=b.num[i];
            }
		    l=b.l;
		    return *this;
	    }

		void erase()
        {
           int i;
		   for(i=l;i>=1;--i)
           {
           num[i]=0;
           }
		   l=0;
	    }

        void inp()
        {
		string str;
		cin>>str;
		(*this).erase();
		int x;
		for(x=str.length()-1;x>=0;x--)
        {
			
			num[++l]=str[x]-'0';
		}
        }


        void op()
        {
	        int i;
		    for(int i=l;i>0;i--)
			 cout<<num[i];
	    }


        newnum ()
        {
            l=0;
            
            memset(num,0,sizeof(num));
	
	    }


		newnum operator +(int x)
        {
            newnum temp=*this;
            int i;
		    temp.num[1]+=x;
		    for(i=1;i<=l&&temp.num[i]>=10;i++)
            {
                temp.num[i+1]+=temp.num[i]/10;
                temp.num[i]%=10;
            }
		    while(temp.num[temp.l+1])
            {
                temp.l++;
            }
		    return temp;
	    }


        newnum operator -(int x)
        {
		    newnum temp; 
            temp=*this;
		    temp.num[1]=temp.num[1]-x;
		    for(int i=1; i<=l&&temp.num[i]<0;i++)
            {
			    temp.num[i+1]+=(temp.num[i]+1)/10-1;
			    temp.num[i]=(temp.num[i]+1)%10+10-1;
		    }
		    while(!temp.num[temp.l]&&temp.l>1)
            {
                temp.l=temp.l-1;
            }
		    return temp;
	}

	
		newnum operator /(int x)
        {
		    newnum temp;
		    int n=0;
            int i;
		    for(i=l;i>=1;--i)
            {
			    n=n*10+num[i];
			    temp.num[i]=n/x;
			    n=n%x;
		    }
		    temp.l=l;
		    while(temp.num[temp.l]==0&&temp.l>1)
            {
                temp.l--;
            }
		    return temp;
	    }


		newnum operator *(int x)
        {
		    int i;
		    newnum temp;
		    for(i=1;i<=l;++i)
            {
                temp.num[i]=num[i]*x;
            }
		    temp.l=l;
		    for(i=1;i<=l;++i)
            {
			    temp.num[i+1]=temp.num[i+1]+(temp.num[i]/10);
			    temp.num[i]=temp.num[i]%10;
			    if(temp.num[i+1]&&i+1>temp.l)
                {
                    temp.l=temp.l+1;
                }
		    }
		    return temp;
	    }


	
		newnum operator -(const newnum &n)
        {
		    int i;
		    newnum temp;
		    for(i=1;i<=l;++i)
            {
                temp.num[i]=num[i]-n.num[i];
            }
		    for(i=1;i<=l;++i)
            {
			    if(temp.num[i]<0)
                {
                    temp.num[i]=temp.num[i]+10;
                    temp.num[i+1]=temp.num[i+1]-1;
                }
		    }
		    temp.l=l;
		    while(temp.num[temp.l]==0 && temp.l>1)
            {
                temp.l--;
            }
		    return temp;
	}
	
	newnum operator *(const newnum &n)
    {
		
		newnum temp;
        int i;
        int j;
		for(i=1;i<=l;++i)
        {
            if(num[i]!=0)
            {
			    for(j=1;j<=n.l;++j)
                {
                    if(n.num[j]!=0)
                    {
				        temp.num[i+j-1]=temp.num[i+j-1]+(num[i]*n.num[j]);
				        temp.num[i+j]=temp.num[i+j]+(temp.num[i+j-1]/10);
				        temp.num[i+j-1]=temp.num[i+j-1]%10;
			        }
                }
            }
        }
		temp.l=l+n.l-1;
		while(temp.num[temp.l+1])
        {
            temp.l=temp.l+1;
        }
		return temp;
	}

	

		newnum operator /(const newnum &n)
        {
		
		    
		    int x=num[l];
            int a=l-1;
            int b=n.l-1;
            
		
		    newnum temp,p,q;
		    q=*this; 
            p=n;
		
            int i;

		    for(i=1;i<=(a-b);++i)
            {
                p=p*10;
            }
		    for(i=a-b;i>=0;--i)
            {
			    x=0;
			    while(q>=p)
			    {
			        q=q-p;
                    x++;
			    }
			    temp.num[i+1]=temp.num[i+1]*10+x;
			    p=p/10;
		    }
		    temp.l=(a-b)+1;
		    while(temp.l>=1&&!temp.num[temp.l])
            {
                temp.l--;
            }
		    return temp;
	    }

		newnum operator %(const newnum &n)
        {
		
		    int x=num[l];
            int a=(l-1);
            int b=(n.l-1);
		
		    newnum q=*this;
		    newnum p=n;

		
            int i;
		    for(i=1;i<=(a-b);++i)
            {
                p=p*10;
            }
		    for(i=a-b;i>=0;--i)
		    {
			    while(q>=p)
                {
			        q=q-p;
                }
			
		        p=p/10;
		    }
		    return q;
	    }
	}a,b;




    newnum hcf(newnum &a, newnum &b)
    {
	 newnum p=a;
	 newnum q=b;
	 newnum t;
	
	 while(!(q.l==1 && q.num[1]==0))
     {
	    t=p%q;
	    p=q;
	    q=t;
	 
	 
	 }
	 return p;



	}

    newnum exp(newnum &a, int n)
	{
	newnum p=a;
	newnum t;
	t.num[1]=1;
	t.l=1;
	
	while(n>0)
	{
	    if(n%2==1)
	    t=t*p;
	
	    p=p*p;
	    n=n/2;
	}
	
	return t;
	
	}


    int main()
    {
        a.inp();
        //b.inp();
		//newnum c=a%b;
        //c.op();
        //big
		exp(a,7).op();
        return 0;
    }