#include<bits/stdc++.h>
using namespace std;


string sum(string a,string b){
    
	string res="";
    
    int c=0; 
    
    
    
    int l1=a.length()-1;
	int l2=b.length()-1; 

    while((l1>=0)&&(l2>=0))
	{     
        int x=(a[l1]-'0')+(b[l2]-'0')+c; 
        res.push_back(x%10 +'0');  
        c=x/10;                
        l1--;                        
        l2--;
    }
    
    
    while(l1>=0)
	{          
        int x=(a[l1]-'0')+c;  
        res.push_back(x%10+'0');
        c=x/10;          
        l1--;
	}
    
    while(l2>=0)
	{       
        int x = (b[l2]-'0')+c; 
		res.push_back(x%10 + '0');
        c=x/10;         
        l2--;
    }
    
    
    while(c)
	{   
        res.push_back(c%10+'0'); 
        c/=10;     
    }
    
    int n=res.length();
    string ans="";
    for(int p=n-1;p>=0;p--)
      ans.push_back(res[p]);

	  return ans;
}

string diff(string a,string b){
	    
     string res = "";
 
    
    int len1=a.length();
	int len2=b.length();
     string s1="";
     string s2="";
	 int c=0;

	 for(int p=len1-1;p>=0;p--)
      s1.push_back(a[p]);
	 for(int p=len2-1;p>=0;p--)
      s2.push_back(b[p]);
    for (int i=0; i<len2; i++)
    {
        int ans=((s1[i]-'0')-(s2[i]-'0')-c);
        if (ans < 0)
        {
            ans+=10;
            c=1;
        }
        else
            c=0;
 
        res.push_back(ans+'0');
    }

    for (int i=len2; i<len1; i++)
    {
        int ans=((s1[i]-'0')-c);
        c=0;
        res.push_back(ans+'0');
    }
 

    string fin="";
	for(int p=res.length()-1;p>=0;p--)
      fin.push_back(res[p]);

	fin.erase(0, min(fin.find_first_not_of('0'), fin.size()-1));


	 return fin;
}




string mult(string a, string b) {
        if (a=="0"||b=="0") {
            return "0";
        }
		int l1=a.length();
		int l2=b.length();

        string res(l1+l2, 0);

		int i,j;
        for(i=l1-1;i>=0;i--) 
		{
            for(j=l2-1;j>=0;j--) 
			{
                int ans=(a[i]-'0')*(b[j]-'0')+res[i+j+1];
                res[i+j+1]=ans%10;
                res[i+j]+=ans/10;
            }
        }
        for(i=0;i<res.length();i++) 
		{
            res[i]+='0';
        }
        if (res[0]=='0') 
		{
            return res.substr(1);
        }
        return res;
    }





string fact(int num) {
	int result[3000];
	int resultsize=1;
	int cr;  
	int i;
    result[0]=1;
	string ans="";
    while(num)
	{
        
    int temp;
	int p;
    for(p=0; p<resultsize;p++)
	{
        temp=(result[p]*num)+cr;
        result[p]=temp%10;
        cr=temp/10;
    }
    while(cr){
        result[resultsize]=cr%10;
        cr/=10;
        resultsize++;
    }

        num=num-1;
    }
    for(int i=resultsize-1; i>=0; i--)
        ans.push_back(result[i]+'0');

	return ans;
    
}








struct Node
{
    string s;
    Node* next;
};
 struct Node* stc=NULL;
 
void push(string data)
{
    struct Node* temp;
    temp=new Node();
    temp->s=data;
      temp->next=stc;
    stc=temp;
}
int isempty()
{
    return stc==NULL;
}
 
string top()
{
    if (!isempty())
        return stc->s;
    else
        return "";
}
 
void pop()
{
    struct Node* temp;
    if (stc == NULL)
    {
        return ;
    }
    else
    {
         
        temp=stc;
        stc=stc->next;
        temp->next=NULL;
        free(temp);
    }
}

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

int precedence(char operate) {
	if (operate == '+' || operate == '-')
		return 1;
	else if (operate == 'x')
		return 2;
    else;
	return 0;
}


bool isOperand(char x)
{
	if (x == '+' || x == '-' || x == 'x')
		return false;
	return true;
}


string pf(string s) {
    int l=s.length();
    int i;
    string infy="";
    for(i=0;i<l;i++)
    {
        if(isOperand(s[i]))
        infy.push_back(s[i]);

        else
        {
            infy.push_back('#');
            while((!isempty())&&(precedence(top()[0])>=precedence(s[i])))
            {
                string temp=top();
                pop();
                char c=temp[0];
                infy.push_back(c);
                infy.push_back('#');

            }
            string t2="";
            t2.push_back(s[i]);
            push(t2);
        }
    }
    infy.push_back('#');
    while(!isempty())
    {
        string x=top();
        pop();
        infy.push_back(x[0]);
        infy.push_back('#');
    }

    return infy;

}

string eval(string s)
{
    int l=s.length();
    int i=0;
    while(i<l)
    {
        if((s[i]!='#')&&(isOperand(s[i])) )
        {
            string str="";
            while(s[i]!='#')
            {
                str.push_back(s[i]);
                i++;
            }
            push(str);
            i++;
        }

        else if(s[i]=='#')
        i++;

        else if(s[i]=='+')
        {
            string s1=top();
            pop();
            string s2=top();
            pop();
            string s3=sum(s2,s1);
            push(s3);

            i++;

        }

        else if(s[i]=='-')
        {
            string s1=top();
            pop();
            string s2=top();
            pop();
            string s3=diff(s2,s1);
            push(s3);

            i++;

        }

        else 
        {
            string s1=top();
            pop();
            string s2=top();
            pop();
            string s3=mult(s2,s1);
            push(s3);

            i++;

        }


    }
    

    string ans=top();
    return ans;
}









int main()
{
	int op;
    cin>>op;
    if(op==1)
    {
        newnum e;
        e.inp();
        int p;
        cin>>p;
        exp(e,p).op();
        

    }

   else if(op==2)
    {
        
        newnum a1;
        newnum a2;
        a1.inp();
        a2.inp();
        hcf(a1,a2).op();

    }

    else if(op==3)
    {
        int s1;
        cin>>s1;
        
        cout<<fact(s1)<<endl;
        

    }

    else if(op==4)
    {
        string s1;
        cin>>s1;
        stc=NULL;
        string inm=pf(s1);
        //cout<<inm<<endl;
        stc=NULL;
        string calc=eval(inm);
        cout<<calc<<endl;
        

    }

}