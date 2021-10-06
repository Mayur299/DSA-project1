#include<iostream>
using namespace std;







template <class T,class comp>
class avl
{
    public:
    class node
    {
        public:
        T k;
        node* l;                   //avl tree node members
        node* r;
        int h;
        int lt;
        int rt;

        int o;

        node(T key)
        {
            k=key;
            l=NULL;            //node constructor
            r=NULL;
            h=1;
            o=1;
            lt=0;
            rt=0;
        }
    };
    comp cmp;                //comparator object

    node* head;
    avl()
    {
        head=NULL;               //avl constructor
        
    }

    int balance(node* a)
    {
          if(a->l==NULL&&a->r==NULL)
          return 0;
          else if(a->l!=NULL&&a->r==NULL)                      //checks balance factor a node 
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
            return a->l->h;                                     //returns max height among l and r subtree of given node
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
        m->l=cr;                                                        //left rotation for given critical node
        
        cr->h=1+maxht(cr);

        if(cr->l!=NULL)
        {
            cr->lt=cr->l->lt+cr->l->rt+cr->l->o;
        }
        if(cr->r!=NULL)
        {
            cr->rt=cr->r->lt+cr->r->rt+cr->r->o;
        }

         m->h=1+maxht(m);


          if(m->l!=NULL)
        {
            m->lt=m->l->lt+m->l->rt+m->l->o;
        }
        if(m->r!=NULL)
        {
            m->rt=m->r->lt+m->r->rt+m->r->o;
        }

         


        return m;

    }

    node* rr(node* cr)
    {
        node* m=cr->l;
        node* mr=m->r;
        cr->l=mr;                                                        //right rotation for given critical node
        m->r=cr;
       
        cr->h=1+maxht(cr);

         if(cr->l!=NULL)
        {
            cr->lt=cr->l->lt+cr->l->rt+cr->l->o;
        }
        if(cr->r!=NULL)
        {
            cr->rt=cr->r->lt+cr->r->rt+cr->r->o;
        }

         m->h=1+maxht(m);

         if(m->l!=NULL)
        {
            m->lt=m->l->lt+m->l->rt+m->l->o;
        }
        if(m->r!=NULL)
        {
            m->rt=m->r->lt+m->r->rt+m->r->o;
        }

        return m;
        
    
    
    }

    int search(T given)
    {
        node*curr=head;
        while(curr!=NULL)
        {                                                                     //search given value
        if(cmp(curr->k,given)==0)
        return curr->k;
        else if(cmp(given,curr->k)==-1)
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
        head=add(head,val);                                                       //insert given value
       // cout<<head->k;
    }

    node* add(node*hd,T val)
    {
        if(hd==NULL)
        {
            node* c=new node(val);
            return c;
        }
                                                                               //helper function for insertion
        if(cmp(val,hd->k)==0)
        {
            hd->o++;
            return hd;
        }
        
        else if(cmp(val,hd->k)==-1)
            hd->l=add(hd->l,val);
        else 
            hd->r=add(hd->r,val);


        hd->h=1+(maxht(hd));
        if(hd->l!=NULL)
        {
            hd->lt=hd->l->lt+hd->l->rt+hd->l->o;
        }
        if(hd->r!=NULL)
        {
            hd->rt=hd->r->lt+hd->r->rt+hd->r->o;
        }
       // if(balance(hd)<=1 && balance(hd)>=-1)
        
         if(balance(hd)>1)
        {
            if(cmp(hd->l->k,val)==1)
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
            if(cmp(hd->r->k,val)==0 || cmp(hd->r->k,val)==-1)
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
        curr=curr->l;                                                                      //returns 

        return curr;
    }


    int count_occurence(T val)
    {
        node*curr=head;
        while(curr!=NULL)
        {
        if(cmp(curr->k,val)==0)
        return curr->o;
        else if(cmp(val,curr->k)==-1)
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

        if(cmp(hd->k,val)==-1)
        hd->r=deletehelp(hd->r,val);
        else if(cmp(hd->k,val)==1)
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

         if(hd->l!=NULL)
        {
            hd->lt=hd->l->lt+hd->l->rt+hd->l->o;
        }
        if(hd->r!=NULL)
        {
            hd->rt=hd->r->lt+hd->r->rt+hd->r->o;
        }


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
         if(cmp(hd->k,i)==0)
         {
             lb=hd->k;
             break;
         }
         else if(cmp(hd->k,i)==1)
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
        if(cmp(hd->k,i)==1)
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
T init=pre;
T Preceed(node* hd,T i)
{
    if(hd==NULL)
    return pre;
    if(cmp(hd->k,i)==-1)
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
    if(lc==init)
    return rc;
    else
    {
    if(cmp((i-lc),(rc-i))==-1)
    {
        return lc;
    }
    return rc;
    }
}





int range(T lvalue,T rvalue)
{
    return helprange(head,lvalue,rvalue);

}

int helprange(node* hd,T lv,T rv)
{
    if(hd==NULL)
    return 0;
    else if(hd->k<lv)
    {
        return helprange(hd->r,lv,rv);
    }
    else if(hd->k>rv)
    {
        return helprange(hd->l,lv,rv);

    }
    else 
    {
        return hd->o + helprange(hd->l,lv,rv) + helprange(hd->r,lv,rv);
    }
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


template< class T>
 class uni
{
public:
    int operator()(T a,T b)
    {
        if (a < b)
            return -1;
        else if(a>b)
            return 1;
            else
            return 0;
    }
};








  int main()
  {
      avl<string,uni<string>>a;
   /*   a.insertion(1);
     a.insertion(2);
     a.insertion(3);
     a.insertion(4);
    a.insertion(5);
    a.insertion(6);   */
    
       a.insertion("a");
     a.insertion("ab");
     a.insertion("z");
     a.insertion("z");
     a.insertion("mayur");
     a.insertion("heeanl");
     a.insertion("kkk");
     a.insertion("br");
     a.insertion("encyclopedia");
     a.insertion("cat");
     a.deletion("zzzzz");
     cout<<a.klargest(5)<<endl;
     cout<<a.klargest(4)<<endl;
     cout<<a.klargest(3)<<endl;
     cout<<a.klargest(2)<<endl;
     cout<<a.klargest(1)<<endl;
     cout<<a.klargest(2)<<endl;
     cout<<a.klargest(6)<<endl;
     cout<<a.upperbound("z")<<endl;
     cout<<a.lowerbound("a")<<endl;
     //cout<<a.closest("cat")<<endl;
     cout<<a.range("a","zat")<<endl;
    // cout<<a.search(0)<<endl;
    // cout<<a.head->l->l->o<<endl;
    // cout<<a.count_occurence(9)<<endl;

     
     
    // a.insertion(5);
    // a.insertion(-1);
     //a.insertion(-2);


    a.printTree(a.head,nullptr,false);

     
    
      
      return 0;
  }      