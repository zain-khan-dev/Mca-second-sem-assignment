#include<iostream>
using namespace std;
class Array
{
	int *a;
	int size,p;
public:
	Array(int n)
	{
		p=(n*(n+1))*(2*n+1)/6;
		a=new int[p];
		size=0;
	}
	void getpattern(int index)
	{
		for(int i=1;i<=index;i++)
		{
			for(int j=1;j<=i*i;j++)
			{
				a[size]=i;
				size++;
			}
		}
	}
	void delete1(int index)
	{
		for(int i=index;i<size;i++)
		{
			a[i]=a[i+1];
		}
		size--;
	}
	void display()
	{
		for(int i=0;i<size;i++)
		{
			cout<<a[i];
		}
	}
	void remduplicatemin(int index)
	{
		int k=0;
		for(int i=index;i>=0;--i)
		{
			for(int j=0;j<i*i-1;j++)
			{
				delete1(size-k-1);
			}
			k++;
		}
	}
	void remduplicatemax(int index)
	{
		int k=0;
		for(int i=0;i<=index;i++)
		{
			for(int j=0;j<i*i-1;j++)
			{
				delete1(k);
			}
			k++;
			
		}
	}
};
int main()
{
	int n,t;
	cout<<"Enter the index till which you want to print the pattern\n";
	cin>>n;
	Array a(n);
	a.getpattern(n);
	cout<<"The pattern is\n";
	a.display();
	cout<<endl;
	cout<<"Do you want to remove the elements in maximum or minimum moves\n1.maximum\n2.minimum\n";
	cin>>t;
	if(t==1)
		a.remduplicatemax(n);
	if(t==2)
		a.remduplicatemin(n);
	a.display();
}