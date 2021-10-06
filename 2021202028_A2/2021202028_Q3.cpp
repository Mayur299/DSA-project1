#include<iostream>
using namespace std;


template<class T>
class deque
{
   public:
   long long cap;
   long long total;
   long long f;
   long long r;
 

   T * it;
   deque()
   {
      it=new T[5];
      cap=5;
      total=0;
      f=r=-1;
   }

  

   deque(long long n,T x)
   {
      it =new T[n];
      long long i;
      for(i=0;i<n;i++)
      {
          it[i]=x;
      }
      total=n;
      cap=n;
      f=0;
      r=n-1;
   }


   T &operator[](long long i)
   {     
       
       long long x;
         x=(f+i)%cap;
        
        return it[x];
    }


   void push_back(T x)
   {
       if(total==cap)
       {
           long long capnew=cap*2;
           T* itnew=new T[capnew];
           long long i,j;
           i=0;
           for(j=f;j!=r;j=(j+1)%cap)
           {
               itnew[i++]=it[j];
           }
           itnew[i]=it[r];
           delete[] it;
           it=itnew;
           f=0;
           r=total-1;
            r++;
           it[r]=x;
           total++;
           cap=capnew;
       }
       else if(f==-1&&r==-1)
       {
           f=r=0;
           it[r]=x;
           total++;
       }
       else
       {
           r=(r+1)%cap;
           it[r]=x;
           total++;
       }
   }

   long long size()
   {
       return total;
   }

   bool isempty()
   {
       if(total==0)
       return true;
       return false;
   }

   T front()
   {
       
       return it[f];
       
   }

    T back()
   {
       
       return it[r];
   }


   void clear()
   {
       delete []it;
       it=new T[5];
       total=0;
       cap=5;
       f=r=-1;
   }

   void resize(long long x,T d)
   {
       
       T* itnew=new T[x+1];
       long long i=0;
       if(f!=-1&&r!=-1)
       {
           long long j=f;
           while(j!=r && i<x)
           {
               itnew[i++]=it[j];
               j=(j+1)%cap;
           }
           if(total<=x)
           itnew[i]=it[r];
           
           i++;
       }
       if(i<x)
       {
          while(i<x)
          {
              itnew[i]=d;
              i++;
          }
       }

       f=0;
       r=x-1;
       total=x;
       cap=x+1;
       delete [] it;
       it=itnew;
   }


  void pop_back()
  {
      if(r==-1)
      cout<<"invalid"<<endl;
      else
      {
          if(total==1)
          {
              f=r=-1;
          }
          else if(r!=0)
          {
             r-=1;
          }
          else
          {
              r=cap-1;
          }
      }
      total--;
  }

  void push_front(T x)
  {
      if(total==cap)
       {
           long long capnew=cap*2;
           T* itnew=new T[capnew];
           long long i,j;
           i=0;
           for(j=f;j!=r;j=(j+1)%cap)
           {
               itnew[i++]=it[j];
           }
           itnew[i]=it[r];
           delete[] it;
           it=itnew;
           f=0;
           r=total-1;
           cap=capnew;
            f=cap-1;
            it[f]=x;
           total++;
           cap=capnew;

       }

       else if(f==-1&r==-1)
       {
           f=r=0;
           it[f]=x;
           total++;
       }

       else
       {
           if(f!=0)
           {
               f--;
               it[f]=x;
               total++;
           }
           else
           {
               f=cap-1;
               it[f]=x;
               total++;
           }
       }
  }

  void pop_front()
  {
      if(total==0)
      {
         cout<<"invalid"<<endl;
      }
      else if(total==1)
      {
         f=r=-1;
         total--;
      }
      else
      {
          f=(f+1)%cap;
          total--;
      }
  }


};

int main()
{
    deque<int> arr(100,0);
   /* arr.push_back(1);
    arr.push_back(2);
    cout<<arr[20]<<endl;
    cout<<arr[21]<<endl;
    cout<<arr.size()<<endl;
    arr.clear();
    cout<<arr[0]<<endl;
    cout<<arr.size()<<endl;
    */
     arr.resize(101,0);
     arr.push_back(5);
     
    // arr.pop_back();
     arr.push_front(40);
    // arr.pop_front();
     int i;
     for(i=0;i<arr.size();i++)
     cout<<arr[i]<<" ";
   cout<<arr.size();

   


    
     return 0;
}