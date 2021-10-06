#include<iostream>

using namespace std;






template<class T, class X>
class UnorderedMap
{
    public:
    struct node{
        T key;
        X val;
        node* next;
    };
    
    struct node* hashmap[97]={NULL};
    int prime=1543;

     
     long long len=0;
    
  //  UnorderedMap()
  //  {
     //   for(int i=0;i<bucket;i++)
     //   {
     //       hashmap[i]=NULL;
      //  }
       // len;
  //  }
   /* int hash(string data)
    {
        //used universal hashing for strings
        //and had referred `bernstein` hash function for h val and a val;
        //string s=string(data+"");
        int h=5381;
        int a=33;
        int n=data.length();
        for (int i=0;i<n;i++)
        {
            h=((h*a)+data[i]) mod prime;
        }
        return h;
    } */


    long long H(T k)
    {
        return k%97;
    }
    
    node* createnode(T data, X val)
    {
        node* temp=(struct node*)malloc(sizeof(node));
        temp->key=data;
        temp->val=val;
        temp->next=NULL;
        //cout<<"inside create";
        return temp;
    }
    
    void insert(T data, X val)
    {
        //string s=string(data+"");
       // ostringstream os; 
       // os<<data; 
       // int index=hash(os.str());
        //cout<<index<<endl;
        long long index=H(data);
        struct node* root=hashmap[index];
        //cout<<"hey";
        if(root==NULL)
        {
            root=createnode(data,val);
            //cout<<"hello";
            hashmap[index]=root;
            len++;
            return;
        }
        else if(root!=NULL)
        {
            //yadi ek node hi hai to usko hi check kr lo
            //cout<<"Bye";
            if(root->next==NULL)
            {
                if(root->key==data)
                    return;
                node* p=createnode(data,val);
                root->next=p;
                len++;
                return;
            }
            else
            {
                //pehle se present hai ki nhi dekh lo chain me
                node* temp=root;
                while(temp->next!=NULL)
                {
                    if(temp->key==data)
                        return;
                    else
                        temp=temp->next;
                }

                // yaha aa gaya mltb pehle se present nhi hai chain me to insert krwa do
                node* p=createnode(data,val);
                temp->next=p;
                len++;

                return;
            }
        }
    }



    void erase(T data)
    {
       // ostringstream os; 
       // os<<data; 
       // int index=hash(os.str());
        //cout<<index<<" ";
        long long index=H(data);
        node* root=hashmap[index];

        if(root==NULL)
            return; 
        
        else if(root!=NULL)
        {
            //yadi single node hai to usko check kro 
            if(root->next==NULL)
            {
                if(root->key==data)
                {
                    //root=NULL;
                    hashmap[index]=NULL;
                    free(root);
                    len--;
                }
                else return;
            }

            //yadi chain hai to
            else
            {
                node* temp=root;
                node* prev;
                node* p;
                if(temp->key==data)
                {
                    root=temp->next;
                    free(temp);
                    len--;
                    return;
                }
                while(temp!=NULL)
                {
                    if(temp->key==data)
                    {
                        p=temp;
                        break;
                    }
                    prev=temp;
                    temp=temp->next;
                }
                prev->next=p->next;
                free(p);
                len--;
            }
        }
    }


    int find(T data)
    {
       // ostringstream os; 
       // os<<data; 
       // int index=hash(os.str());
       long long index=H(data);
        node* root=hashmap[index];
        if(root==NULL)
            return 0;

        else
        {
            if(root->next==NULL)
            {
                if(root->key==data)
                    return 1;
                
                else return 0;
            }
            node* temp=root;
            while(temp!=NULL)
            {
                if(temp->key==data)
                {
                    return 1;
                }
                temp=temp->next;
            }
        }
        return 0;
    }


    X &operator[](T data)
    {
       //ostringstream os; 
       // os<<data; 
       // int index=hash(os.str());
       long long index=H(data);
        node* root=hashmap[index];
        node* temp=root;
        node* p;
        while(temp!=NULL)
        {
            if(temp->key==data)
            {
                p=temp;
                break;
            }
            temp=temp->next;
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
        if(hashmap[i]!=NULL)
        {   cout<<i<<endl;
            node* root=hashmap[i];
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
     UnorderedMap<int,int>m;
   

   int arr[23]={0,0,0,0,1,0,1,0,0,1,0,5,3,2,0,5,9,10,0,0,0,0,0};
   int i;
   int k=3;
   for(i=0;i<k;i++)
   {
       if(m.find(arr[i])==0)
       m.insert(arr[i],1);
       else
       m[arr[i]]++;

       //cout<<m.size()<<" ";
   }
   cout<<m.count()<<" ";
   for(i=k;i<23;i++)
   {   if(m[arr[i-k]]==1)
       m.erase(arr[i-k]);
       else
       m[arr[i-k]]--;

       if(m.find(arr[i])==0)
       m.insert(arr[i],1);
       else
       m[arr[i]]++;

       cout<<m.count()<<" ";
   }
  
/*
    m.insert(97,2);
   m.insert(0,3);
   m.insert(194,1);
   m.insert(64,0);
   m.insert(291,55);
    m.insert(1,3);
    m.erase(64);

*/
m.display();

   return 0;
}