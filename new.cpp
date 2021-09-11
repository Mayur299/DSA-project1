
#include<iostream>
#include<unordered_map>
using namespace std;

class lru
{   public:
     int cap;
    //map<int,ll*>m;
     class ll
     {  public:
         int key;
         int value;
         ll* next;
         ll* prev;

     };
     unordered_map<int,ll*>m;
     ll* head;
     ll* last;

     lru(int capacity)
     {
         cap=capacity;
         head=new ll();
         last=new ll();
         head->next=last;
         head->prev=NULL;
         last->prev=head;
         last->next=NULL;


     }

     void insert(ll*n)
     {
         n->next=head->next;
         n->prev=head;
         ll* headn=head->next;
         headn->prev=n;
         head->next=n;

    }



     ll* remove(ll*n)
     {
         ll*temp=n;
         ll*nex=n->next;
         ll*pre=n->prev;
         nex->prev=pre;
         pre->next=nex;
         return temp;

     }

     

     int get(int k)
     {
         
         if(m.find(k)==m.end())
         return -1;
         ll *temp=remove(m[k]);
         insert(temp);
         return m[k]->value;

         
         
     }

     void set(int k,int v)
     {   if(cap==0)
         {
             int sorry=0;
         }
         else
         {
         if(m.find(k)==m.end())
         {
             if(m.size()==cap)
         {
             ll* temp=last->prev;
             ll* tempn=remove(temp);
             
    
         
             m.erase(temp->key);
         }


             ll* n=new ll();
             n->key=k;
             n->value=v;
             insert(n);
             m[k]=n;
            
         

         }
         else
         {
             ll* temp=remove(m[k]);
             temp->value=v;
             insert(temp);

         }
         }
         


         
     }

};

  
    




int main()
{
    lru* exp;

    while(1)
    {
      int c;
      cin>>c;
      switch (c)
      {
          case 1:
          int k;
          cin>>k;
          exp=new lru(k);
          break;

          case 2:
          int key;
          cin>>key;
          cout<<exp->get(key)<<endl;
          break;

          case 3:
          int ke;
          int ve;
          cin>>ke>>ve;
          exp->set(ke,ve);
          break;

          case -1:
          exit(0);
          break;

          default :
          cout<<"invalid choice"<<endl;
          

      }
      {
      //case /* constant-expression */:
          /* code */
          //break;
      
      //default:
          //break;
      }
    }

   /* exp->set(1,10);
    exp->set(2,20);
    exp->set(3,30);
    cout<<exp->get(2)<<endl;
    exp->set(4,40);
    cout<<exp->get(1)<<endl;
    cout<<exp->get(3)<<endl;
    cout<<exp->get(2)<<endl;
    cout<<exp->get(4)<<endl;
    exp->set(1,10);*/
    

    return 0;
}
