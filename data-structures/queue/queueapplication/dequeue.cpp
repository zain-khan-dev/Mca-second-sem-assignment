#include<iostream>
using namespace std;
class queue
{
	int *a,front,rear,size;
public:
	queue(int n)
	{
		size=n;
		a=new int[size];
		front=-1;
		rear=n;
	}
	void enterfront(int n)
	{
		if(front==size||front==rear-1)
			{
				cout<<"The deque is full at the front side\n";
				return;
			}
		front++;
		a[front]=n;
	}
	void enterrear(int n)
	{
		if(rear==-1||rear==front+1)
		{
			cout<<"The deque is full at the rear side\n";
			return;
		}
		rear--;
		a[rear]=n;
	}
	void removerear()
	{
		if(rear==size)
		{
			cout<<"The deque is empty at the rear side\n";
			return;
		}
		else
		{
			rear++;
		}
	}
	void removefront()
	{
		if(front==-1)
		{
			cout<<"The deque is empty at the front side\n";
			return;
		}
		else
		{
			front--;
		}
	}
	int getrear()
	{
		return a[rear];
	}
	int getfront()
	{
		return a[front];
	}
};
int main()
{
	int a,n,p;
	cout<<"Enter the size of the deque\n";
	cin>>a;
	queue q(a);
	while(1)
	{
		cout<<"Enter what you want to do\n";
		cout<<"1.Enter an element at the front\n";
		cout<<"2.Enter an element ar the rear end\n";
		cout<<"3.Removes an element from the front\n";
		cout<<"4.Removes an element from the rear\n";
		cout<<"5.Display the element at the front\n";
		cout<<"6.Display the element at the rear\n";
		cout<<"7.Exit\n";
		cin>>n;
		if(n==1)
		{
			cout<<"Enter the element you want to enter\n";
			cin>>p;
			q.enterfront(p);
		}
		else
			if(n==2)
			{
			cout<<"Enter the element you want to enter\n";
			cin>>p;
			q.enterrear(p);
			}
		else
			if(n==3)
			{
				q.removerear();
			}
		else
			if(n==4)
			{
				q.removefront();
			}
		else
			if(n==5)
			{
				q.getfront();
			}
		else
			if(n==6)
			{
				q.getrear();
			}
		else
			if(n==7)
			{
				break;
			}
	}
}