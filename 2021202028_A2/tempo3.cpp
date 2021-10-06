#include<iostream>
using namespace std;



template<class P,class Q>
class unorderedmap
{
    public:
    class node
    {  public:
        P key;
        Q val;
        node* next;

        node(P a,Q b)
        {
            key=a;
            val=b;
            next=NULL;
        }

    };
    
    node* arr[97]={NULL};
    
    long long len=0;
   
    long long H(P k)
    {
        return k%97;
    }

    void insert(P k,Q v)
    {
        long long pos=H(k);
        if (arr[pos]==NULL)
        {
            node* temp=new node(k,v);
            arr[pos]=temp;
            len++;
            return;
        }
        else if(arr[pos]!=NULL)
        {
            node* it=arr[pos];
            node* prev=arr[pos];
            while(it!=NULL)
            {
                if(it->key==k)
                {
                    it->val=v;
                    return;
                }
                prev=it;
                it=it->next;
            }
            node* temp=new node(k,v);
            len++;
            prev->next=temp;
             return;
        }

    }


    bool find(P k)
    {
        long long pos=H(k);
        node* head=arr[pos];
        if(head==NULL)
        {
            return false;
        }
        else
        {
            node *it=arr[pos];
            while(it!=NULL)
            {
                if(it->key==k)
                return true;

                it=it->next;
            }
            return false;
        }
        return false;
    }

  

   void erase(P k)
    {
        long long pos=H(k);
        if(arr[pos]==NULL)
        return;
        else
        {   node* it =arr[pos];
            if(it->next==NULL)
            {
                if(it->key==k)
                {
                   arr[pos]=NULL;
                   free(it);
                   len--;
                   return;
                }
            }
            else
            {
                node* prev;
                while(it!=NULL)
                {
                    if(it->key==k)
                    {
                        prev->next=it->next;
                        free(it);
                        len--;
                        return;
                    }
                    prev=it;
                    it=it->next;
                }
            }
        }
    }

    Q &operator[](P k)
    {
        long long pos=H(k);
     
        node* it=arr[pos];
        node* p;
       
            

             while(it!=NULL)
        {
            if(it->key==k)
            {
                p=it;
                break;
            }
            
            it=it->next;
        }

        return p->val;

        
        
       
       
    }

long long  count()
{
    return len;
}



void display()
{
    int i;
    for(i=0;i<97;i++)
    {
        if(arr[i]!=NULL)
        {   cout<<i<<endl;
            node* root=arr[i];
            while(root!=NULL)
            {
                cout<<root->key<<"->"<<root->val<<" ";
                root=root->next;
            }
            cout<<endl;
        }
    }
}


};

int main()
{
     unorderedmap<int,int>m;
   

   int arr[23]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1};
   int i;
   int k=3;
   for(i=0;i<k;i++)
   {
       if(m.find(arr[i])==false)
       m.insert(arr[i],1);
       else
       m[arr[i]]++;

      
   }
   cout<<m.count()<<endl;
   m.display();
   cout<<endl<<endl;
   for(i=k;i<23;i++)
   {   if(m[arr[i-k]]==1)
       m.erase(arr[i-k]);
       else
       m[arr[i-k]]--;

       if(m.find(arr[i])==false)
       m.insert(arr[i],1);
       else
       m[arr[i]]++;

       cout<<m.count()<<endl;
       m.display();
       cout<<endl<<endl;
   }
  

  

   return 0;
}