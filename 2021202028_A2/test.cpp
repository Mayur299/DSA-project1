#include<iostream>

using namespace std;






template<class P, class Q>
class UnorderedMap
{
    public:
    class node{
        public:
        P key;
        Q val;
        node* next;
        node(P k,Q v)
        {
            key=k;
            val=v;
            next=NULL;
        }
    };
    
    node* arr[97]={NULL};
    int prime=1543;

     
     long long len=0;
    
  //  UnorderedMap()
  //  {
     //   for(int i=0;i<bucket;i++)
     //   {
     //       arr[i]=NULL;
      //  }
       // len;
  //  }
   /* int hash(string key)
    {
        //used universal hashing for strings
        //and had referred `bernstein` hash function for h val and a val;
        //string s=string(key+"");
        int h=5381;
        int a=33;
        int n=key.length();
        for (int i=0;i<n;i++)
        {
            h=((h*a)+key[i]) mod prime;
        }
        return h;
    } */


    long long H(P k)
    {
        return k%97;
    }
    
   /* node* createnode(T key, X val)
    {
        node* temp=(struct node*)malloc(sizeof(node));
        temp->key=key;
        temp->val=val;
        temp->next=NULL;
        //cout<<"inside create";
        return temp;
    } */
    
    void insert(P k, Q v)
    {
        //string s=string(key+"");
       // ostringstream os; 
       // os<<key; 
       // int index=hash(os.str());
        //cout<<index<<endl;
        long long index=H(k);
         node* root=arr[index];
        //cout<<"hey";
        if(root==NULL)
        {
            node* te=new node(k,v);
            root=te;
            //cout<<"hello";
            arr[index]=root;
            len++;
            return;
        }
        else if(root!=NULL)
        {
            //yadi ek node hi hai to usko hi check kr lo
            //cout<<"Bye";
            if(root->next==NULL)
            {
                if(root->key==k)
                    return;
                    node* te=new node(k,v);
                
                root->next=te;
                len++;
                return;
            }
            else
            {
                //pehle se present hai ki nhi dekh lo chain me
                node* temp=root;
                while(temp->next!=NULL)
                {
                    if(temp->key==k)
                        return;
                    else
                        temp=temp->next;
                }

                // yaha aa gaya mltb pehle se present nhi hai chain me to insert krwa do
                
                node* pq=new node(k,v);
                temp->next=pq;
                len++;

                return;
            }
        }
    }



    void erase(P k)
    {
       // ostringstream os; 
       // os<<key; 
       // int index=hash(os.str());
        //cout<<index<<" ";
        long long index=H(k);
        node* root=arr[index];

        if(root==NULL)
            return; 
        
        else if(root!=NULL)
        {
            //yadi single node hai to usko check kro 
            if(root->next==NULL)
            {
                if(root->key==k)
                {
                    //root=NULL;
                    arr[index]=NULL;
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
                if(temp->key==k)
                {
                    root=temp->next;
                    free(temp);
                    len--;
                    return;
                }
                while(temp!=NULL)
                {
                    if(temp->key==k)
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


    bool find(P k)
    {
       // ostringstream os; 
       // os<<key; 
       // int index=hash(os.str());
       long long index=H(k);
        node* root=arr[index];
        if(root==NULL)
            return true;

        else
        {
            if(root->next==NULL)
            {
                if(root->key==k)
                    return true;
                
                else return false;
            }
            node* temp=root;
            while(temp!=NULL)
            {
                if(temp->key==k)
                {
                    return true;
                }
                temp=temp->next;
            }
        }
        return false;
    }


    Q &operator[](P k)
    {
       //ostringstream os; 
       // os<<key; 
       // int index=hash(os.str());
       long long index=H(k);
        node* root=arr[index];
        node* temp=root;
        node* pq;
        while(temp!=NULL)
        {
            if(temp->key==k)
            {
                pq=temp;
                break;
            }
            temp=temp->next;
        }
        return pq->val;
    }




/*Q &operator[](P k)
    {
        long long pos=H(k);
     //   if(arr[pos]==NULL)
      //  {   Q v;
       //   insert(k,v);
       //   }
        node* it=arr[pos];
        node* p;
       
            

             while(it!=NULL)
        {
            if(it->key==k)
            {
                p=it;
                break;
            }
            //return it->val;
            it=it->next;
        }

        return p->val;

        
        
       
       
    }  */






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
     UnorderedMap<int,int>m;
   

   int a[23]={0,0,0,0,1,0,1,0,0,1,0,5,3,2,0,5,9,10,0,0,0,0,0};
   int i;
   int kv=3;
   for(i=0;i<kv;i++)
   {
       if(m.find(a[i])==false)
       m.insert(a[i],1);
       else
       {
           int z=m[a[i]];
           m.insert(a[i],z+1);
       }

       //cout<<m.size()<<" ";
   }
   cout<<m.count()<<" ";
   for(i=kv;i<23;i++)
   {   if(m[a[i-kv]]==true)
       m.erase(a[i-kv]);
       else
       {
           int z=m[a[i-kv]];
           m.insert(a[i-kv],z-1);
       }
      // m[a[i-k]]--;

       if(m.find(a[i])==false)
       m.insert(a[i],1);
       else
       {
           int z=m[a[i-kv]];
           m.insert(a[i-kv],z+1);
       //m[a[i]]++;
       }

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