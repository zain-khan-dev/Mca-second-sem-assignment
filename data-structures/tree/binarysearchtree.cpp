#include<iostream>
using namespace std;
class node
{
	node *left,*right;
	int data;
public:
	friend class bsearch1;
	node()
	{
		left=right=NULL;
	}
};
class bsearch1
{
	node *root;
	node *curr;
	node *p;	
public:

	node * build(int x)
	{
		if(root==NULL)
		{
			curr=new node;
			root=curr;
			p=curr;
			root->data=x;
		}
		else
		{
			while(curr!=NULL)
			{
				if(curr->data<x)
				{
					p=curr;
					curr=curr->right;
				}
				else
					if(curr->data>x)
						{
							p=curr;
							curr=curr->left;
						}
				else
					if(curr->data==x)
					{
						cout<<"Data already exist\n";
						return root;
					}
			}
			if(p->data>x)
			{
				p->left=new node;
				curr=p->left;
				curr->data=x;
			}
			if(p->data<x)
			{
				p->right=new node;
				curr=p->right;
				curr->data=x;
			}
		}
		return root;
	}
	void displayascend(node *r)
	{
		if(r->left!=NULL)
			displayascend(r->left);
		cout<<r->data<<endl;
		if(r->right!=NULL)
			displayascend(r->right);
	}
	void displaydescend(node *r)
	{
		if(r->right!=NULL)
			displaydescend(r->right);
		cout<<r->data<<endl;
		if(r->left!=NULL)
			displaydescend(r->left);
	}
};

int main()
{
	int n,p;
	bsearch1 *b;
	b=new bsearch1;
	node *root;
	root=new node;
	while(1)
	{
		cout<<"What do you want to do\n";
		cout<<"1.Insert an element\n";
		cout<<"2.Display all the elements in the ascending order\n";
		cout<<"3.Display all the elements in the descending order\n";
		cout<<"Enter any other number to exit\n";
		cin>>n;
		if(n==1)
		{
			cout<<"Enter the element you want to enter into the binary tree\n";
			cin>>p;
			root=b->build(p);
			continue;
		}
		if(n==2)
		{
			cout<<"The elements in the ascending order are\n";
			b->displayascend(root);
			cout<<endl;
			continue;
		}
		if(n==3)
		{
			cout<<"The elements in the descending order are\n";
			b->displaydescend(root);
			cout<<endl;
			continue;
		}
		else
			break;	
	}
}