#include<iostream>
#include<math.h>
using namespace std;
class btree
{
	int *a;
	int height;
public:
	btree(int h)
	{
		height=h;
		a=new int[getnode(height)];
	}
	inline int getnode(int h)
	{
		return(pow(2,h)-1);
	}
	void build()
	{
		static int i=0;
		if(i==0)
		{
			cout<<"Enter the value of the root node\n";
			cin>>a[i];
		}
		if(2*(i+1)-1>=getnode(height))
			return;
		cout<<"Enter the value of the left node of the "<<a[i]<<endl;
		cin>>a[2*(i+1)-1];
		cout<<"Ente the value of the right child of the "<<a[i]<<endl;
		cin>>a[2*(i+1)];
		i++;
		build();		
	}
	void display()
	{
		for(int i=0;i<getnode(height);i++)
			cout<<a[i];
	}
	void inorder(int i)
	{
		if(a[2*(i+1)-1]!=-1&&2*(i+1)-1<getnode(height))
		{
			inorder(2*(i+1)-1);
		}
		cout<<a[i];
		if(a[2*(i+1)]!=-1&&2*(i+1)<getnode(height))
		{
			inorder(2*(i+1));
		}
	}
	void preorder(int i)
	{
			cout<<a[i];
		if(a[2*(i+1)-1]!=-1&&2*(i+1)-1<getnode(height))
		{
			preorder(2*(i+1)-1);
		}
		if(a[2*(i+1)]!=-1&&2*(i+1)<getnode(height))
		{
			preorder(2*(i+1));
		}
	}
	void postorder(int i)
	{
		if(a[2*(i+1)-1]!=-1&&2*(i+1)-1<getnode(height))
		{
			postorder(2*(i+1)-1);
		}
		if(a[2*(i+1)]!=-1&&2*(i+1)<getnode(height))
		{
			postorder(2*(i+1));
		}
		cout<<a[i];
	}
};
int main()
{
	int size;
	cout<<"Enter the height of the tree you want to build\n";
	cin>>size;
btree b(size);
b.build();
b.display();
cout<<endl;
cout<<"inorder:-   ";
b.inorder(0);
cout<<endl;
cout<<"preorder:-   ";
b.preorder(0);
cout<<endl;
cout<<"postorder:-  ";
b.postorder(0);
}