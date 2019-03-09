#include<iostream>
using namespace std;
class Array
{
	int *a,p,size;
public:
	Array(int n)
	{
		p=(n*(n+1))/2;
		size=0;
		a=new int[p];
	}
	void getpattern(int index)
	{
		for(int i=0;i<index;i++)
		{
			for(int j=0;j<=i;j++)
			{
				a[size]=i+1;
				size++;
			}
		}
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
		{
			cout<<a[i];
		}
	}
void removeduplicatemin(int n)
{
	int k=0;
	for(int i=n;i>0;i--)
	{
		for(int j=0;j<i-1;j++)
			{delete1(size-1-k);
			}
			k++;
	}
}
void removeduplicatemax(int n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			delete1(i);
		}
	}
}
};
int main()
{
	int p,o;
	cout<<"Enter the number till you want to print the pattern\n";
	cin>>p;
	Array a(p);
	a.getpattern(p);
	cout<<"Do you want to remove duplicate in maximum or minimum moves\n1.Max\n2.Min\n";
	cin>>o;
	if(o==1)
		a.removeduplicatemax(p);
	else
		a.removeduplicatemin(p);
	a.display();
}