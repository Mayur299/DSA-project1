
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct newnum
{
	
	int num[3000];
    int l;

		


        bool operator >(const newnum &b)
        { 
            int f;
            if(l>b.l)
            f= 0;
		    if(l<b.l)
            f= 1;
            else
            {
            int i=l;
		    
            while(i>=1)
            {   
			    if(num[i]<b.num[i])
                {
                f= 1;
                break;
                }
			    if(num[i]>b.num[i])
                {
                    f=0;
                    break;
                }
                i--;
		    }
		    if(i==0)
            f=2;
            }
            if(f==0)
            return true;
            return false;
        }
	
	    bool operator <=(const newnum &b)
        {   
            int f;
            if(l>b.l)
            f= 0;
		    if(l<b.l)
            f=1;
            else
            {
            int i=l;
		    
            while(i>=1)
            {   
			    if(num[i]<b.num[i])
                {
                f=1;
                break;
                }
			    if(num[i]>b.num[i])
                {
                    f=0;
                    break;
                }
                i--;
		    }
		    if(i==0)
            f=2;
            }
            if(f==1 || f==2)
            return true;
            return false;
        }
	
	    bool operator >=(const newnum &b)
        {   
            int f;
            if(l>b.l)
            f=0;
		    if(l<b.l)
            f=1;
            else
            {
            int i=l;
		    
            while(i>=1)
            {   
			    if(num[i]<b.num[i])
                {
                f= 1;
                break;
                }
			    if(num[i]>b.num[i])
                {
                    f=0;
                    break;
                }
                i--;
		    }
		    if(i==0)
            f=2;
            }
            if(f==0 || f==2)
            return true;
            return false;
        }

        newnum operator=(const newnum &b)
        { 

            int i;
		    for(i=1;i<=b.l;++i)
            {
            num[i]=b.num[i];
            }
            for(i=b.l+1;i<=l;++i)
            {
            num[i]=0;
            }
		    l=b.l;
		    return *this;
	    }

		

        void inp()
        {
		string str;
		cin>>str;
		memset(num,0,sizeof(num));
        l=0;
		int x;
		for(x=str.length()-1;x>=0;x--)
        {
			l=l+1;
			num[l]=str[x]-'0';
		}
        }


        void op()
        {
	        int i=l;
            while(i>0)
            {
			 cout<<num[i];
             i--;
            }
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
            temp.num[1]=temp.num[1]+x;
		    for(i=1;i<=l&&temp.num[i]>=10;i++)
            {

                temp.num[i+1]=temp.num[i+1]+(temp.num[i]/10);
                temp.num[i]=temp.num[i]%10;
            }


            
            int k=temp.l;
            while(temp.num[k+1]!=0)
            {
                k++;
            }
		    temp.l=k;
		    return temp;
	    } 



      /*  newnum operator +(int x){
		newnum tmp; tmp=*this;
		tmp.num[1]+=x;
		for(int i=1;i<=l&&tmp.num[i]>=10;++i){tmp.num[i+1]+=tmp.num[i]/10;tmp.num[i]%=10;}
		while(tmp.num[tmp.l+1])tmp.l++;
		return tmp;  */
	


        newnum operator -(int x)
        {
		    newnum temp; 
            temp=*this;
		    temp.num[1]=temp.num[1]-x;
		    for(int i=1; i<=l&&temp.num[i]<0;i++)
            {
			    temp.num[i+1]+=(temp.num[i]+1)/10-1;
			    temp.num[i]=((temp.num[i]+1)%10)+10-1;
		    }
            int k=temp.l;
            while(k>1&&temp.num[k]==0)
            {
                k--;
            }

		    temp.l=k;
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
            int k=l;
            while(k>1&&temp.num[k]==0)
		    k--;
            temp.l=k;
		    return temp;
	    }


		newnum operator *(int x)
        {
		    int i;
		    newnum temp;
            temp.l=l;
		    for(i=1;i<=l;i++)
            {
                temp.num[i]=num[i]*x;
            }
		    for(i=1;i<=l;i++)
            {   

                temp.num[i+1]=temp.num[i+1]+(temp.num[i]/10);
                temp.num[i]=temp.num[i]%10;
			    if(i+1>temp.l&&temp.num[i+1])
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
		    int k=l;
		    while(temp.num[k]==0 && k>1)
            {
                k--;
            }
            temp.l=k;
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
		int k=n.l+l-1;
		while(temp.num[k+1]!=0)
        {
            k++;
        }
        temp.l=k;
		return temp;
	}

	

		newnum operator /(const newnum &n)
        {
		
		    
		    int x=num[l];
            int a=l-1;
            int b=n.l-1;
            
		
		    newnum q=*this; 
            newnum p=n;
            newnum temp;
		
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
	};




   

    newnum exp(newnum &a, int n)
	{
	newnum p=a;
	newnum t;
	t.num[1]=1;
	t.l=1;
	
	while(n>=1)
	{
	    if(n%2==1)
	    t=t*p;
	
	    p=p*p;
	    n=n/2;
	}
	
	return t;
	
	}




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

int main()
{
    newnum p;
    p.inp();
    newnum k=p/11;
    k.op();
    return 0;
}