#include<iostream>
using namespace std;
class stack
{
	int *a;
	int curr;
public:
	stack(int l)
	{
		a=new int[l];
		curr=-1;
	}
	void push(int n)
	{
		curr++;
		a[curr]=n;
	}
	void pop()
	{
		curr--;
	}
	int top()
	{
		return a[curr];
	}
	int isempty()
	{
		if(curr==-1)
			return 1;
		else
			return 0;
	}
};
int main()
{
	int n;
	cout<<"Enter the dimension of the maze\n";
	cin>>n;
	int a[10][10];
	stack x(10),y(10);
	cout<<"Enter 1 for every blocked space in maze and 0 for every free space\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	x.push(0);
	y.push(0);
	while(x.isempty()==0)
	{
		if(x.top()==n-1&&y.top()==n-1)
		{
			break;
		}
		if(y.top()+1<n&&a[x.top()][y.top()+1]!=1)
		{
			a[x.top()][y.top()]=1;
			x.push(x.top());
			y.push(y.top()+1);
			continue;
		}
		if(x.top()+1<n&&a[x.top()+1][y.top()]!=1)
		{
			a[x.top()][y.top()]=1;
			y.push(y.top());
			x.push(x.top()+1);
			continue;
		}
		if(y.top()-1>=0&&a[x.top()][y.top()-1]!=1)
		{
			a[x.top()][y.top()]=1;
			x.push(x.top());
			y.push(y.top()-1);
			continue;
		}
		if(x.top()-1>=0&&a[x.top()-1][y.top()]!=1)
		{
			a[x.top()][y.top()]=1;
			y.push(y.top());
			x.push(x.top()-1);
			continue;
		}
		else
			a[x.top()][y.top()]=1a[x.top()][y.top()]=1;;
			x.pop();
			y.pop();
		}
		if(x.isempty()==0)
		{
		while(x.isempty()==0)
		{
			cout<<x.top();
			cout<<y.top();
			cout<<endl;
			x.pop();
			y.pop();
		}
		}
		else
		{
			cout<<"It is impossible to reach the destination\n";
		}

	}

