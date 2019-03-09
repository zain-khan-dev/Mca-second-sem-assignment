#include<iostream>
using namespace std;
class stack
{
	int data;
	stack *next;
	stack *curr;
	stack *prev;
public:
	stack()
	{
		curr=NULL;
		curr=NULL;
		prev=NULL;
	}
	void push(int n)
	{
		if(isempty())
		{
			curr=new stack;
			curr->prev=NULL;
			curr->next=NULL;
			curr->data=n;
		}
		else
		{
		curr->next=new stack;
		curr->next->prev=curr;
		curr=curr->next;
		curr->next=NULL;
		curr->data=n;
		}
	}
	int pop()
	{
		int temp;
		if(isempty())
		{
			cout<<"The stack is empty\n";
			return -1;
		}
		else
			if(curr->next==NULL&&curr->prev==NULL)
		{
			temp=curr->data;
			curr=NULL;
			return(temp);
		}
		else
		{
			temp=curr->data;
			curr=curr->prev;
			return(temp);
		}
	}
	int isempty()
	{
		if(curr==NULL)
			return 1;
		else
			return 0;
	}
	int top()
	{
		return(curr->data); 
	}
};
int main()
{
	int n,a;
	stack s;
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
			if(s.isempty())
				cout<<"Nothing to display \n";
			else
				cout<<"THe top element is "<<s.top()<<endl;
		}
		if(n==4)
			break;
	}
}