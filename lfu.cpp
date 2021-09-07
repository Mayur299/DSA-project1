#include<bits/stdc++.h>
using namespace std;

class lfu
{   
    public:

   class node
   {   public:
       int k;
       int v;
       int f;
       node* next;
       node* prev;
       node() {}
       node(int k1,int v1)
       {
           k=k1;
           v=v1;
           f=1;
           next=NULL;
           prev=NULL;

       }
   };

   class dll{
       

      public:
       node* head;
       node* last;

       dll()
       {    
           
           last=new node(-3,-3);
           head=new node(-1,-1);
    
           head->next=last;
           last->prev=head;


       }

       void add(node* n)
       {
           node* temp=head->next;
           head->next=n;
           n->prev=head;
           n->next=temp;
           temp->prev=n;
       }

       node* dele(node *n)
       {
         node* pre=n->prev;
         node *nex=n->next;
         pre->next=nex;
         nex->prev=pre;
         n->next=NULL;
         n->prev=NULL;
         return n;

       }

   };



    int cap;
    int freqmin;
    map<int,node*>m1;
    map<int,dll*>m2;

    lfu(int c)
    {
       cap=c;
       freqmin=0;

    }

    void up(node* n)
    {
      dll* temp=m2[n->f];
      temp->dele(n);
      if(n->f==freqmin && temp->head->next==temp->last)
      {
          m2.erase(n->f);
          freqmin++;
      }

      n->f++;
      if(m2.find(n->f)!=m2.end())
      {
          m2[n->f]->add(n);
      }
      else
      {
          dll *newl=new dll();
          newl->add(n);
          m2[n->f]=newl;

      }
      

    }

    int get(int key)
    {
        if(m1.find(key)==m1.end())
        return -1;
        else
        {
            up(m1[key]);
            return m1[key]->v;
        }
    }

    void put(int key,int value)
    {
           if (cap==0)
           return;
           if(m1.find(key)!=m1.end())
           {
               m1[key]->v=value;
               up(m1[key]);
           }
           else
           {
               node* temp=new node(key,value);
               if(m1.size()==cap)
               {
                   dll* temp2=m2[freqmin];

                   node* t2=temp2->dele(temp2->last->prev);
                   m1.erase(t2->k);
               }
               freqmin=1;
               if(m2.find(temp->f)!=m2.end())
               {
                  m2[temp->f]->add(temp);
                  m1[key]=temp;
                }
                else
                {
                 dll *newl=new dll();
                  newl->add(temp);
                 m2[temp->f]=newl;
                 m1[key]=temp;

                 }

           }
    }

};

int main()
{  
   lfu *l=new lfu(2);
   l->put(1,1);
   l->put(2,2);
   cout<<l->get(1)<<endl;
   l->put(3,3);
   cout<<l->get(2)<<endl;
   cout<<l->get(3)<<endl;
   l->put(4,4);
  cout<<l->get(1)<<endl;
   cout<<l->get(3)<<endl;
   cout<<l->get(4)<<endl;




    return 0;
}