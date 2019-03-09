#include<iostream>
using namespace std;
class queue
{
	int *a,front,rear,size;
public:
	queue(int s)
	{
		a=new int[s];
		front=0;
		size=s;
		rear=-1;
	}
	void enqueue(int n)
	{
		rear++;
		a[rear]=n;
	}
	int dequeue()
	{
			return(a[front++]);
	}
	int getfront()
	{
		return(a[front]);
	}
	int getrear()
	{
		return(a[rear]);
	}
	int isempty()
	{
		if(front==rear+1)
			return 1;
		else 
			return 0;
	}
	int isfull()
	{
		if(rear==size-1)
			return 1;
		else
			return 0;
	}

};
int main()
{
	int n,a;
	queue q(1);
	while(1)
	{
		cout<<"Enter what you want to do\n";
		cout<<"1.Enter elements in the queue\n";
		cout<<"2.Remove  elements from the queue\n";
		cout<<"3.See the front element in the queue\n";
		cout<<"4.See the rear element of the queue\n";
		cout<<"5.Exit from the function\n";
		cin>>n;
		if(n==1)
		{
			if(q.isfull())
			{
				cout<<"THe queue is full \n";
			}
			else
			{
			cout<<"Enter the value you want to add to queue\n";
			cin>>a;
			q.enqueue(a);
			}
		}
		if(n==2)
		{
			if(q.isempty()==1)
			{
				cout<<"The queue is empty\n";
				continue;
			}
			cout<<"The value popped out is"<<q.dequeue()<<endl;
		}
		if(n==3)
		{
			if(q.isempty())
				cout<<"Nothing to show the queue is empty\n";
			else
			cout<<"The front element of the queue is "<<q.getfront()<<endl;
		}
		if(n==4)
		{
			if(q.isempty())
				cout<<"Nothing to show queue is empty\n";
			else
			cout<<"The rear element of the queue is"<<q.getrear()<<endl;
		}
		if(n==5)
			break;
	}
}