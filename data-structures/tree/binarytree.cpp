#include<iostream>
using namespace std;
class node
{
	node *left,*right;
	int data;
public:
	node()
	{
		left=right=NULL;
	}
	friend class tree;
};
class tree
{
	node *root;
public:
	node * build(node *curr)
	{
		char ch;
		if(curr==NULL)
		{
			curr=new node;
			root=curr;
			cout<<"Enter the value of the root node\n";
		}
		cin>>curr->data;
		cout<<"Does "<<curr->data<<"contain a left node\n";
		cin>>ch;
		if(ch=='y')
		{
			cout<<"Enter the value of the left node of "<<curr->data<<endl;
			curr->left=new node;
			build(curr->left);
		}
		cout<<"Does "<<curr->data<<"contain a right node\n";
		cin>>ch;
		if(ch=='y')
		{
			cout<<"Ente rthe value of the right node of the "<<curr->data<<endl;
			curr->right=new node;
			build(curr->right);
		}
		return root;
	}
	void inorder(node *r)
	{	
		if(r->left!=NULL)
			inorder(r->left);
		cout<<r->data<<" "y;
		if(r->right!=NULL)
			inorder(r->right);
	}
	void preorder(node *r)
	{
		cout<<r->data<<" ";
		if(r->left!=NULL)
			preorder(r->left);
		if(r->right!=NULL)
			preorder(r->right);
	}
	void postorder(node *r)
	{
		
		if(r->left!=NULL)
			postorder(r->left);
		if(r->right!=NULL)
			postorder(r->right);
		cout<<r->data<<" ";
	}
};

int main()
{
	tree *n;
	node *root;
	root=new node;	
	n=new tree;
	root=n->build(NULL);
	cout<<"Inorder:-\t";
	n->inorder(root);
	cout<<"\nPreorder:-\t";
	n->preorder(root);
	cout<<"\nPostorder:-\t";
	n->postorder(root);
}