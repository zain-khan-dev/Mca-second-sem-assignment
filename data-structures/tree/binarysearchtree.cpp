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
	int i=0;
	node * insert(int x)
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
			curr=root;
			while(curr!=NULL)
			{
				if(curr->data==x)
				{
					cout<<"Data already exist\n";
					return root;

				}
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
		if(i==0)                                   //To make the value of r point to root if root is modified 
		{
			r=root;
			i++;	
		}
		if(r==NULL)
			{
				cout<<"Tree is empty\n";
				return;
			}
		if(r->left!=NULL)
			displayascend(r->left);
		cout<<r->data<<endl;
		if(r->right!=NULL)
			displayascend(r->right);
	}
	void displaydescend(node *r)
	{
		if(i==0)
		{
			r==root;
			i++;
		}

		if(r==NULL)
			{
				cout<<"Tree is empty\n";
				return;
			}
		if(r->right!=NULL)
			displaydescend(r->right);
		cout<<r->data<<endl;
		if(r->left!=NULL)
			displaydescend(r->left);
	}
	int search(node *r,int x)
	{
		while(r!=NULL)
		{
		if(r->data==x)
			return 2;
		else
			if(r->data<x)
			{
				r=r->right;
			}
		else
			if(r->data>x)
			{
				r=r->left;
			}
		}
		return 0;
	}
	int delete1(node *r,int x)
	{
		node *p;
		p=NULL;
		while(r!=NULL)
		{
		if(r->data==x)
			{
				if(p==NULL)                                       //when root node need to be removed
				{
					if(r->left==NULL&&r->right==NULL)            //when only root node is present diffrent return value is used to modify the value of root node
					{
						root=NULL;
					return 1;
					}
					else
						if(r->left==NULL)                       //when removing root node and only right child exist diffrent return value is used to distinguish and modify the root
						{
							root=root->right;
							return 1;
						}
					else
						if(r->right==NULL)                     //when removing root node and only right child is present
						{
							root=root->left;
							return 1;
						}
					else
					{
						p=root->left;                               //when both the child of the root node exist
						root=root->right;
						r=root;
						
						while(r->left!=NULL)	
						{
							r=r->left;
						}
						r->left=p;
						return 1;
					}
				}
				if(r->left==NULL&&r->right==NULL)      //When the node to be removed is a leaf node
				{
					p->left=NULL;
					p->right=NULL;
					return 1;
				}
				if(r->left==NULL)                         //when only right child of the node to be removed is present
				{
					if(p->data>x)
					{
						p->left=r->right;
						return 1;
					}
					if(p->data<x)
					{
						p->right=r->right;
						return 1;
					}
				}
				if(r->right==NULL)                      //when only left child of the node to be removed is present
				{
					if(p->data>x)
					{
						p->left=r->left;
						return 1;
					}
					if(p->data<x)
					{
						p->right=r->left;
						return 1;
					}
				}
				if(p->data>x)                       //when both child nodes are present and the data to be removed is to the left of the parent node
				{
					p->left=r->left;
					p=r->right;
					r=r->left;
					while(r->right!=NULL)
					{
						r=r->right;
					}
					r->right=p;
				}
				if(p->data<x)                       //when both child nodes are present and the data to be removed is to the right of the parent node   
				{
					p->right=r->left;
					p=r->right;
					r=r->left;
					while(r->right!=NULL)
					{
						r=r->right;
					}
					r->right=p;
				}
				return 1;
			}
		else
			if(r->data<x&&r->right!=NULL)
			{
				cout<<"moved right\n";
				p=r;
				r=r->right;
				continue;
			}
		else
			if(r->data>x&&r->left!=NULL)
			{
				cout<<"Moved left\n";
				p=r;
				r=r->left;
				continue;
			}
			return 0;
		}
		return 0;
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
		cout<<"4.Search whether an element in a subtree or not\n";
		cout<<"5.Delete an element from the binary search tree\n";
		cout<<"Enter any other number to exit\n";
		cin>>n;
		if(n==1)
		{
			cout<<"Enter the element you want to enter into the binary tree\n";
			cin>>p;
			root=b->insert(p);
			continue;
		}
		if(n==2)
		{
			cout<<"The elements in the ascending order are\n";
			b->i=0;                                               //to intialise it to zero so that main root and tree root are same
			b->displayascend(root);
			cout<<endl;
			continue;
		}
		if(n==3)
		{
			cout<<"The elements in the descending order are\n";
			b->i=0;                                               //to intialise it to zero so that main root and tree root are same 
			b->displaydescend(root);
			cout<<endl;
			continue;
		}
		if(n==4)
		{
			int x;
			cout<<"Enter the element you want to search for\n";
			cin>>x;
			if(b->search(root,x))
				cout<<"Element exists\n";
			else
				cout<<"Element do not exists\n";
			continue;
		}
		if(n==5)
		{
			int x;
			cout<<"Enter the element to be removed\n";
			cin>>x;
			if(b->delete1(root,x)==1)
					cout<<"Deletion succesfull\n";
			else
				if(b->delete1(root,x)==0)
					cout<<"Deletion not completed.Element does not exists\n";
			continue;
		}
		else
			break;	
	}
}