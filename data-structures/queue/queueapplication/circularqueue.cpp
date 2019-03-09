#include<iostream>
using namespace std;
class queue
{
   int *a,front,rear,size,check;
public:
   queue(int n)
   {
      size=n;
      a=new int[size];
      front=0;
      rear=-1;
      check=0;
   }
   void enqueue(int n)
   {
      if(isfull())
      {
         cout<<"The stack is full\n";
         return;
      }
      rear=(rear+1)%size;
      a[rear]=n;
      check=0;
   }
   void dequeue()
   {
      if(check)
         {
            cout<<"The stack is empty\n";
            return;
         }
      if(rear==front)
         check=1;
      front=(front+1)%size;
   }
   int getfront()
   {
      return(a[front]);
   }
   int getrear()
   {
      return(a[rear]);
   }
   bool isfull()
   {
      if((rear+1+size)%size==front&&rear!=-1)
         return 1;
      return 0;
   }
};
int main()
{
   int n,a,t;
   cout<<"Enter the size of the queue\n";
   cin>>n;
   queue q(n);
   while(1)
   {
      cout<<"Enter the operation you want to perform\n";
      cout<<"1.Enter an element in the queue\n";
      cout<<"2.Remove an element from the queue\n";
      cout<<"3.Get the value from the front\n";
      cout<<"4.Get the value from the rear\n";
      cout<<"5.Exit\n";
      cin>>a;
      if(a==1)
         {
            cout<<"Enter the value to be entered\n";
            cin>>t;
            q.enqueue(t);
         }
      else
         if(a==2)
            q.dequeue();
      else
         if(a==3)
            cout<<"The front element is "<<q.getfront()<<endl;
      else
         if(a==4)
            cout<<"The rear element is "<<q.getrear()<<endl;
      else
         if(a==5)
            break;
         
   }
}