#include<iostream>
using namespace std;

template <typename T>
class avl
{
    public:
    class node
    {
        public:
        T k;
        node* l;
        node* r;
        int h;

        int o;

        node(T key)
        {
            k=key;
            l=NULL;
            r=NULL;
            h=1;
            o=1;
        }
    };

    node* head;
    avl()
    {
        head=NULL;
    }

    int balance(node* a)
    {
          if(a->l==NULL&&a->r==NULL)
          return 0;
          else if(a->l!=NULL&&a->r==NULL)
          return a->l->h;
          else if(a->l==NULL&&a->r!=NULL)
          return -1*(a->r->h);
          else
          return (a->l->h)-(a->r->h);
    }

    int maxht(node*a)
    {
        if(a->l!=NULL&&a->r!=NULL)
        {
            if(a->l->h > a->r->h)
            return a->l->h;
            else 
            return a->r->h;
        }
        else if(a->l!=NULL&&a->r==NULL)
          return a->l->h;
        else if(a->l==NULL&&a->r!=NULL)
          return a->r->h;
          else
          return 0;
    }

    node* ll(node*cr)
    {
        node* m=cr->r;
        node* ml=m->l;
        cr->r=ml;
        m->l=cr;
        
        cr->h=1+maxht(cr);
         m->h=1+maxht(m);
        return m;

    }

    node* rr(node* cr)
    {
        node* m=cr->l;
        node* mr=m->r;
        cr->l=mr;
        m->r=cr;
       
        cr->h=1+maxht(cr);
         m->h=1+maxht(m);
        return m;
        
    
    
    }

    int search(T given)
    {
        node*curr=head;
        while(curr!=NULL)
        {
        if(curr->k==given)
        return curr->k;
        else if(given<curr->k)
        {
            curr=curr->l;
        }
        else
            curr=curr->r;
        }
        return -1;
    }

    

    void insertion(T val)
    {
        head=add(head,val);
       // cout<<head->k;
    }

    node* add(node*hd,T val)
    {
        if(hd==NULL)
        {
            node* c=new node(val);
            return c;
        }

        if(val==hd->k)
        {
            hd->o++;
            return hd;
        }
        
        else if(val<hd->k)
            hd->l=add(hd->l,val);
        else 
            hd->r=add(hd->r,val);


        hd->h=1+(maxht(hd));
       // if(balance(hd)<=1 && balance(hd)>=-1)
        
         if(balance(hd)>1)
        {
            if(hd->l->k>val)
            {
                return rr(hd);
            }
            else
            {
               hd->l=ll(hd->l);
               return rr(hd);
            }
        }

        else if(balance(hd)<-1)
        {
            if(hd->r->k<=val)
            {
                return ll(hd);
            }
            else
            {
                hd->r=rr(hd->r);
                return ll(hd);
            }
        }
      return hd;


    }

    node* successor(node* hd)
    {
        node* curr=hd;
        while(curr->l!=NULL)
        curr=curr->l;

        return curr;
    }


    int count_occurence(T val)
    {
        node*curr=head;
        while(curr!=NULL)
        {
        if(curr->k==val)
        return curr->o;
        else if(val<curr->k)
        {
            curr=curr->l;
        }
        else
            curr=curr->r;
        }
        return 0;
    }


    void deletion(T val)
    {
        head=deletehelp(head,val);
    }

    node* deletehelp(node*hd ,T val)
    {
        if(hd==NULL)
        {
            return hd;

        }

        if(hd->k<val)
        hd->r=deletehelp(hd->r,val);
        else if(hd->k>val)
        hd->l=deletehelp(hd->l,val);
        else
        {
            if(hd->l==NULL&&hd->r==NULL)
            {
                free(hd);
                return NULL;
            }
            else if(hd->l!=NULL&& hd->r==NULL)
            {
                node* it=hd->l;
                free(hd);
                return it;

            }
            else if(hd->l==NULL&& hd->r!=NULL)
            {
                node* it=hd->r;
                free(hd);
                return it;

            }

            else
            {
                node* it=successor(hd->r);
                hd->k=it->k;
                hd->r=deletehelp(hd->r,it->k);
            }
        }

        if (hd==NULL)
        return NULL;
        hd->h=maxht(hd)+1;
        if(balance(hd)<=1&&balance(hd)>=-1)
        return hd;
         if(balance(hd)>1)
        {
            if(balance(hd->l)<0)
            {
                hd->l=ll(hd->l);
                return rr(hd);
            }
            
            return rr(hd);
        }

         if(balance(hd)<-1)
        {
            if(balance(hd->r)>0)
            {
                hd->r=rr(hd->r);
                return ll(hd);
            }
            return ll(hd);
        }
        return(hd);

    }

    T ans;
    bool flag=false;


    void klhelper(node* hd,int& i)
    {
        if(hd==NULL)
        return;
        klhelper(hd->r,i);
       
        i=i-hd->o;
        if(i<=0&&flag==false)
        {
        ans=hd->k;
        flag=true;
        return;
        }
        klhelper(hd->l,i);

    }
     T klargest(int i)
    {   flag=false;
       klhelper(head,i);
       return ans;
    }



  T lowerbound(T i)
  {    
      T lb;
      node* hd=head;
      while(hd!=NULL)
      {
         if(hd->k==i)
         {
             lb=hd->k;
             break;
         }
         else if(hd->k>i)
         {
             lb=hd->k;
             hd=hd->l;
         }
         else
         {
             hd=hd->r;
         }
      }
      return lb;
  }


T upperbound(T i)
{
    T ub;
    node* hd=head;
    while (hd!=NULL)
    {
        if(hd->k>i)
        {
            ub=hd->k;
            hd=hd->l;
        }
        else
        {
            hd=hd->r;
        }
    }
    return ub;
    
}


T pre;
T Preceed(node* hd,T i)
{
    if(hd==NULL)
    return pre;
    if(hd->k<i)
    {
        pre=hd->k;
        return Preceed(hd->r,i);
    } 
    return Preceed(hd->l,i);
}

T closest(T i)
{
    T rc=lowerbound(i);
    T lc=Preceed(head,i);
    if((i-lc)<(rc-i))
    {
        return lc;
    }
    return rc;
}























    struct Trunk
{
    Trunk *prev;
    string str;
 
    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};
 
// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == nullptr) {
        return;
    }
 
    showTrunks(p->prev);
    cout << p->str;
}
 
// Recursive function to print a binary tree.
// It uses the inorder traversal.
void printTree(node* root, Trunk *prev, bool isLeft)
{
    if (root == nullptr) {
        return;
    }
 
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);
 
    printTree(root->r, trunk, true);
 
    if (!prev) {
        trunk->str = "———";
    }
    else if (isLeft)
    {
        trunk->str = ".———";
        prev_str = "   |";
    }
    else {
        trunk->str = "`———";
        prev->str = prev_str;
    }
 
    showTrunks(trunk);
    cout << root->k << endl;
 
    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";
 
    printTree(root->l, trunk, false);


}
                
        };

  int main()
  {
      avl<int>a;
   /*   a.insertion(1);
     a.insertion(2);
     a.insertion(3);
     a.insertion(4);
    a.insertion(5);
    a.insertion(6);   */
    
       a.insertion(1);
     a.insertion(1);
     a.insertion(1);
     a.insertion(2);
     a.insertion(2);
     a.insertion(4);
     a.insertion(3);
     a.insertion(7);
     cout<<a.klargest(5)<<endl;
     cout<<a.klargest(4)<<endl;
     cout<<a.klargest(3)<<endl;
     cout<<a.klargest(2)<<endl;
     cout<<a.klargest(1)<<endl;
     cout<<a.klargest(2)<<endl;
     cout<<a.klargest(6)<<endl;
     cout<<a.upperbound(7)<<endl;
     cout<<a.closest(1)<<endl;
    // cout<<a.search(0)<<endl;
    // cout<<a.head->l->l->o<<endl;
    // cout<<a.count_occurence(9)<<endl;

     
     
    // a.insertion(5);
    // a.insertion(-1);
     //a.insertion(-2);


    a.printTree(a.head,nullptr,false);

     
    
      
      return 0;
  }      