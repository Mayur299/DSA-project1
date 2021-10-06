#include<iostream>

using namespace std;






template<class P, class Q>
class unorderedmap
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
   

     
     long long len=0;
    
  


    long long H(P k)
    {
        return k%97;
    }
    
  /*
    void insert(P k, Q v)
    {
       
        long long index=H(k);

         node* root=arr[index];
        //cout<<"hey";
        if(root==NULL)
        {     node* te=new node(k,v);
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
                
                node* p=new node(k,v);
                temp->next=p;
                len++;

                return;
            }
        }
    }

*/

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

 /*   void erase(P k)
    {
       // ostringstream os; 
       // os<<k; 
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

*/

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



  /*  bool find(P k)
    {
       // ostringstream os; 
       // os<<k; 
       // int index=hash(os.str());
       long long index=H(k);
        node* root=arr[index];
        if(root==NULL)
            return false;

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
    } */



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
   



 /*   Q &operator[](P k)
    {
       //ostringstream os; 
       // os<<k; 
       // int index=hash(os.str());
       long long index=H(k);
        node* root=arr[index];
        node* temp=root;
        node* p;
        while(temp!=NULL)
        {
            if(temp->key==k)
            {
                p=temp;
                break;
            }
            temp=temp->next;
        }
        return p->val;
    }

*/



 Q &operator[](P k)
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
   

   int arr[23]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21,21,22};
   int i;
   int k=3;
   for(i=0;i<k;i++)
   {
       if(m.find(arr[i])==false)
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

       if(m.find(arr[i])==false)
       m.insert(arr[i],1);
       else
       m[arr[i]]++;

       cout<<m.count()<<" ";
   }
cout<<endl;
   m.display();
  
/*
    m.insert(97,2);
   m.insert(0,3);
   m.insert(194,1);
   m.insert(64,0);
   m.insert(291,55);
    m.insert(1,3);
    m.erase(64);


m.display();
*/

   return 0;
}

