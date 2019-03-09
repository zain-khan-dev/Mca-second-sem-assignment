#include<iostream>
using namespace std;
class car
{
	int *a,front,rear;
public:
	car()
	{}
	car(int n)
	{
		a=new int[n];
		front =0;
		rear=-1;
	}
	void dequeue()
	{
		front++;
	}
	void enqueue(int n)
	{
		rear++;
		a[rear]=n;
	}
	int isempty()
	{
		if(front==rear+1)
			return 1;
		else
			return 0;
	}
	int getfront()
	{
		return a[front];
	}
};
int main()
{
	int n,p,curr=1,entry;
	cout<<"Enter the number of cars\n";
	cin>>n;
	cout<<"Enter the number of queues\n";
	cin>>p;
	car c[p];
	for(int i=0;i<p;i++)
		c[i]=car(n);
	int a[n];
	cout<<"Enter the arrangement of the car\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	int k=0;
	while(curr!=n)
	{
		int index=-1, max=-1;
		entry=0;
		if(a[k]==curr)
		{
			k++;
			curr++;
			entry=1;
			continue;
		}
		else
		{
			for(int i=0;i<p;i++)
				{
					if(c[i].isempty()==0&&c[i].getfront()==curr)
					{
						curr++;
						c[i].dequeue();
						entry=1;
					}
				else
					{
						if(c[i].isempty())
						{
							c[i].enqueue(a[k]);
							k++;
							entry=1;
							break;
						}
						if(k!=n&&a[k]>c[i].getfront())
						{
							if(max<c[i].getfront())
							{
							max=c[i].getfront();
							index=i;
							}
							entry=1;
						}
					}
				}
			if(entry==0)
			{

				cout<<"Not possible\n";
				break;
			}
			if(index!=-1)
			{
				c[index].enqueue(a[k]);
				k++;
			}
		}
	}
	if(entry!=0)
		cout<<"It is possible\n";
}