#include<iostream>
using namespace std;
class Array
{
	int *a,p,size;
public:
	Array(int n)
	{
		p=(n*(n+1))/2;
		a=new int[p];
		size=0;
	}
	void insert(int x,int index)
	{
		for(int i=size-1;i>=index;i--)
		{
			a[i+1]=a[i];
		}
		a[index]=x;
		size++;
	}
	void delete1(int index)
	{
		for(int i=index;i<size;i++)
			a[i]=a[i+1];
		size--;
	}
	void display()
	{
		for(int i=0;i<size;i++)
			cout<<a[i];
	}
};
void insertmin(int index,Array &a)
{
	int k=0;
	for(int i=0;i<index;i++)
	{
		for(int j=0;j<=i;j++)
		{
			a.insert(i+1,k);
			k++;
		}
	}
}
void insertmax(int index,Array &a)
{
	for(int i=index-1;i>=0;i--)
	{
		for(int j=0;j<=i;j++)
		{
			a.insert(i+1,0);
		}
	}
}

int main()
{
	int p,n;
	cout<<"Enter the index till which you want to print the pattern\n";
	cin>>p;
	Array a(p);
	cout<<"Do you want to perform it with min or max moves\n1.For min\n2.For max\n";
	cin>>n;
	if(n==1)
		insertmin(p,a);
	else
		if(n==2)
			insertmax(p,a);
	a.display();
}