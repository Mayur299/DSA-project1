#include<string.h>
#include<iostream>
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
    
    
    while(c!=0)
	{   
        res.push_back(c%10+'0'); 
        c=c/10;   
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
        ans>=0?res.push_back(ans+'0'):res.push_back(ans+10+'0');
        ans>=0?c=0:c=1;
    }

    for (int i=len2;i<len1;i++)
    {
        int ans=((s1[i]-'0')-c);
        ans>=0?res.push_back(ans+'0'):res.push_back(ans+10+'0');
        ans>=0?c=0:c=1;
        
    }
 

    string fin="";
	for(int p=res.length()-1;p>=0;p--)
      fin.push_back(res[p]);

	fin.erase(0, min(fin.find_first_not_of('0'), fin.size()-1));


	 return fin;
}




string mult(string a, string b) {
        if (a.length()==0||b.length()==0||a=="0"||b=="0") 
        {
            string ans="0";
            return ans;
        }
		int l1=a.length();
		int l2=b.length();

        string res(l1+l2, '0');

		int i=l1-1;
         while(i>=0)
		{
                int j=l2-1;
                while(j>=0)
			{
                int ans=(res[i+j+1]-'0')+((a[i]-'0')*(b[j]-'0'));
                res[i+j+1]=(ans%10)+'0';
                
                res[i+j]=(res[i+j]-'0')+((ans/10)+'0');
                j--;
            }
            i--;
        }
        string fin="";
        if(res[0]=='0')
        fin.append(res,1);
        else
        fin=res;

        return fin;

    }









string fact(int num) 
{
	int result[3000];
	int s=1;
	int cr; 
	int i;
    result[0]=1;
	string ans="";
    
    for(i=num;i>=2;i--)
	{
    int temp;
	int p=0;
    while(p<s)
	{

        int t=i*result[p];
        temp=cr+t;
        cr=temp/10;
        result[p]=temp%10;
        p++;
    }
    while(cr!=0)
    {
        result[s]=cr%10;
        cr/=10;
        s++;
    }
    }
     int k=s-1;
    while(k>=0)
    {
        ans.push_back(result[k]+'0');
        k--;
    }

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
	
	int num[3001];
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
            
            int i;
            for(i=0;i<3001;i++)
            num[i]=0;
	
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
            int a=l;
            int b=n.l;
            
		
		    newnum q=*this; 
            newnum p=n;
            newnum temp;
		
            int i;

		    for(i=1;i<a-b+1;++i)
            {
                p=p*10;
            }
            i=a-b;
            while(i>=0)
            {
			    x=0;
			    while(q>=p)
			    {
			        q=q-p;
                    x++;
			    }
			    temp.num[i+1]=temp.num[i+1]*10+x;
			    p=p/10;
                i--;
		    }
		    int k=(a-b)+1;
		    while(k>=1&&!temp.num[k])
            {
                k--;
            }
            temp.l=k;
		    return temp;
	    }

		newnum operator %(const newnum &n)
        {
		
		    int x=num[l];
            int a=l;
            int b=n.l;
		
		    newnum q=*this;
		    newnum p=n;

		
            int i=1;
            while(i<a-b+1)
            {
                p=p*10;
                i++;
            }
            i=a-b;
            while(i>=0)
		    {
			    while(q>=p)
                {
			        q=q-p;
                }
			
		        p=p/10;
                i--;
		    }
		    return q;
	    }
	};




   

    

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
	    n=n>>1;
	}
	
	return t;
	
	}




    newnum hcf(newnum &a, newnum &b)
    {
	 newnum p=a;
	 newnum q=b;
	 newnum t;
	
	 while(q.l!=1 || q.num[1]!=0)
     {
	    t=p%q;
	    p=q;
	    q=t;
	 
	 
	 }
	 return p;
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
