#include<iostream>
using namespace std;
class stack
{
	int *a;
	int top;
	int size;
public:
	stack(int p)
	{
		a= new int[p];
		size=p;
		top=-1; 
	}
	void push(int n)
	{
		if(top==size-1)
		{
		cout<<"The stack is full first delete some itmes\n";
		return;
		}
		top++;
		a[top]=n;
	}
	int pop()
	{
		top--;
		return a[top+1];
	}
	int peek()
	{
		return a[top];
	}
	int isempty()
	{
		if (top==-1)
			return 1;
		else
			return 0;
	}
};
int main()
{
	int size,n,a;
	cout<<"Enter the size of the stack you want\n";
	cin>>size;
	stack s(size);
	while(1)
	{
		cout<<"Enter what you want to do\n";
		cout<<"1.Push elements in the stack\n";
		cout<<"2.Pop elements from the stack\n";
		cout<<"3.See the top element in the stack\n";
		cout<<"4.Exit from the function\n";
		cin>>n;
		if(n==1)
		{
			cout<<"Ente the value you want to push to stack\n";
			cin>>a;
			s.push(a);
		}
		if(n==2)
		{
			if(s.isempty()==1)
			{
				cout<<"The stack is empty\n";
				continue;
			}
			cout<<"The value popped out is"<<s.pop()<<endl;
		}
		if(n==3)
		{
			cout<<"THe top element is "<<s.peek()<<endl;
		}
		if(n==4)
			break;
	}
}