#include<iostream>
using namespace std;

template<typename T>
class node
{   public:
    int r;
    int c;
    T data;
    node* next;
};

template<typename T>
node<T>* input()
{
    int row;
    int col;
    cin>>row>>col;
    int i,j;
    node<T>* head=new node<T>();
    head->r=row;
    head->c=col;
    head->data=0;
    head->next=NULL;
    node<T>* last=head;
    int count=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
             T t;
             cin>>t;
             if(t!=0)
             {
                node<T>* temp=new node<T>();
                temp->r=i;
                temp->c=j;
                temp->data=t;
                temp->next=NULL;
                last->next=temp;
                last=temp;
                count++;

             }
        }
    }
    head->data=count;
    return head;

}

template<typename T>
void output(node<T>* n)
{
   int row=n->r;
   int col=n->c;
    T **arr;
   int i,j;
   arr=new T*[row];
    
    for(i=0;i<row;i++)
    {
        arr[i]=new T[col];
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            arr[i][j]=0;
        }
    }
   node<T>*t=n->next;
   while(t!=NULL)
   {
       arr[t->r][t->c]=t->data;
       t=t->next;
   } 

    /*for(i=0;i<row;i++)
   {
       for(j=0;j<col;j++)
       {
           cout<<arr[i][j]<<" ";
       }
       cout<<endl;
   }*/

     //node<T>*s=n->next; 
     node<T>*s=n;
     while(s!=NULL)
   {
       cout<<s->r<<" "<<s->c<<" "<<s->data<<endl;
       s=s->next;
   } 
     
   


}


template<typename T>
node<T>* add(node<T>*a,node<T>*b)
{
     node<T>*sum=new node<T>();
     sum->r=a->r;
     sum->c=a->c;
     sum->data=0;
     sum->next=NULL;
     int count=0;
     node<T>* last=sum;

     node<T>*ta=a->next;
     node<T>*tb=b->next;
     while(ta!=NULL && tb!=NULL)
     {
         if(ta->r<tb->r)
         {
             node<T>* nw=new node<T>();
             nw->r=ta->r;
             nw->c=ta->c;
             nw->data=ta->data;
             nw->next=NULL;
             last->next=nw;
             last=nw;
             count++;
             ta=ta->next;

         }
         else if(ta->r>tb->r)
         {
             node<T>* nw=new node<T>();
             nw->r=tb->r;
             nw->c=tb->c;
             nw->data=tb->data;
             nw->next=NULL;
             last->next=nw;
             last=nw;
             count++;
             tb=tb->next;
         }
         else
         {
             if(ta->c<tb->c)
            {
                node<T>* nw=new node<T>();
                nw->r=ta->r;
                nw->c=ta->c;
                nw->data=ta->data;
                 nw->next=NULL;
                last->next=nw;
                last=nw;
                count++;
                ta=ta->next;

            }
            else if(ta->c>tb->c)
            {
                node<T>* nw=new node<T>();
                nw->r=tb->r;
                nw->c=tb->c;
                nw->data=tb->data;
                nw->next=NULL;
                last->next=nw;
                last=nw;
                count++;
                tb=tb->next;
            }

            else
            {
               
               if((ta->data+tb->data)!=0)
               {
                node<T>* nw=new node<T>();
                nw->r=tb->r;
                nw->c=tb->c;
                nw->data=tb->data+ta->data;
                nw->next=NULL;
                last->next=nw;
                last=nw;
                count++;
               }
                tb=tb->next;
                ta=ta->next;


            }
         }
     } 

            while(ta!=NULL)
            {
                node<T>* nw=new node<T>();
                nw->r=ta->r;
                nw->c=ta->c;
                nw->data=ta->data;
                nw->next=NULL;
                last->next=nw;
                last=nw;
                count++;
                ta=ta->next;
            }

            while(tb!=NULL)
            {
                node<T>* nw=new node<T>();
                nw->r=tb->r;
                nw->c=tb->c;
                nw->data=tb->data;
                nw->next=NULL;
                last->next=nw;
                last=nw;
                count++;
                tb=tb->next;
            }

            sum->data=count;
            return sum;
         

     
}


template<typename T>
node<T>* transpose(node<T>*a)
{



        int* cc= new int[a->c];
        int i;
        for(i=0;i<a->c;i++)
        {
             cc[i]=0;
        }
        node<T>* t=a->next;
        while(t!=NULL)
        {
            cc[t->c]++;
            t=t->next;
        }
        
        int* ind=new int[a->c+1];
        ind[0]=1;
        for(i=1;i<=a->c;i++)
        ind[i]=ind[i-1]+cc[i-1];

        node<T>* ans=new node<T>();
        ans->r=a->c;
        ans->c=a->r;
        ans->data=a->data;
        ans->next=NULL;
        node<T>* last=ans;
        for(i=1;i<=a->data;i++)
        {
            node<T>* temp=new node<T>();
            temp->r=0;
            temp->c=0;
            temp->data=0;
            temp->next=NULL;
            last->next=temp;
            last=temp;
    
        }

        node<T>** p = new node<T>*[a->c+1];

        for(i=0;i<=a->c;i++)
        {
            p[i]=ans;
            int j=0;
            while(j<ind[i])
            {
                p[i]=p[i]->next;
                j++;
            }
        }

        t=a->next;
        while(t!=NULL)
        {
            p[t->c]->r=t->c;
            p[t->c]->c=t->r;
            p[t->c]->data=t->data;
            p[t->c]=p[t->c]->next;
            t=t->next;
        }

      /* while(ans!=NULL)
   {
       cout<<ans->r<<" "<<ans->c<<" "<<" "<<ans->data<<endl;
       ans=ans->next;
   } */

        return ans;
        








        

}


template<typename T>
node<T>* mul(node<T>*a,node<T>*b)
{
    node<T>* ans=new node<T>();
    ans->r=a->r;
    ans->c=b->r;
    ans->data=0;
    node<T>* last=ans;
    ans->next=NULL;
    node<T>*x=a->next;
    node<T>*y=b->next;
    int count=0;
    //cout<<a->r<<" "<<b->r;
    while(x!=NULL)
    {
        int row=x->r;
        y=b->next;
        while(y!=NULL)
        {
            T res=0;
            node<T>*p=x;
            node<T>*q=y;
            int col=y->r;
            while(p!=NULL&&q!=NULL&&p->r==row&&q->r==col)
            {
                if(p->c<q->c)
                p=p->next;
                else if(p->c>q->c)
                q=q->next;
                else
                {
                    res+=p->data*q->data;
                    p=p->next;
                    q=q->next;
        
                }
            }

            if(res!=0)
            {
                node<T>* z=new node<T>();
                z->r=row;
                z->c=col;
                z->data=res;
                z->next=NULL;
                last->next=z;
                last=z;
                count++;
            }

            while(y!=NULL&&y->r==col)
            y=y->next;
        }
        while(x!=NULL&&x->r==row)
        x=x->next;
    }
    ans->data=count;
    return ans;
}



int main()
{
    
    
   
   
    node<float>*a=input<float>();
    node<float>*b=input<float>();                    //uncommnent for addition
    node<float>*ans=add<float>(a,b);
    output<float>(ans);  
    
    
    

   

  /*  node<int>*a=input<int>();
    node<int>*res=transpose<int>(a);                   //uncomment for transpose
    output<int>(res);
    */

   

    
   /*
    node<int>*a=input<int>();
    node<int>*b=input<int>();
    node<int>*bt=transpose<int>(b);                   //uncommnent for multiplication
    node<int>*ans=mul<int>(a,bt);
    output<int>(ans); 

    */

    

    return 0;



}

