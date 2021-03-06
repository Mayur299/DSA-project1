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
   string str;
   cin>>str;
   stc=NULL;
   string inm=pf(str);
   cout<<inm<<endl;
   stc=NULL;
   string calc=eval(inm);
   cout<<calc<<endl;
   return 0;

}

