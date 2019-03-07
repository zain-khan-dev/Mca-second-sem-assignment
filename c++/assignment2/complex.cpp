#include<iostream>
using namespace std;
class complex
{
	int img,real;
public:
	complex()
	{
		img=real=0;
	}
	complex(int s)
	{
		img=real=s;

	}
	complex(int i,int r)
	{
		img=i;
		real=r;
	}
	void display()
	{
		cout<<real<<img;
	}
	friend complex &add(complex &,complex &);
	
	friend void disp(complex c)
	{
		cout<<"The number is"<<c.real<<"+"<<c.img<<"i\n";
	}
}c3;
	complex &add(complex &c1,complex &c2)
	{
		c3.img=c1.img+c2.img;
		c3.real=c1.real+c2.real;
		return c3;
	}
int main()
{
	int t=2,n,p,r,i;
	complex c1,c2;
	cout<<"Do you want to enter \n";
	cout<<"1.The same value for both real and imaginary\n";
	cout<<"2.Diffrent values for real and imaginary\n";
	cin>>n;
	if(n==1)
	{
		cout<<"Enter the value for real and imaginary part\n";
		cin>>p;
		  c1=complex(p);
	} 
	if(n==2)
	{
		cout<<"Enter the value for real part of the number\n";
		cin>>r;
		cout<<"Enter the imaginary part of the number\n";
		cin>>i;
		 c1=complex(i,r);
	}
	cout<<"Do you want to enter \n";
	cout<<"1.The same value for both real and imaginary\n";
	cout<<"2.Diffrent values for real and imaginary\n";
	cin>>n;
	if(n==1)
	{
		cout<<"Enter the value for real and imaginary part\n";
		cin>>p;
		 c2=complex(p);
	} 
	if(n==2)
	{
		cout<<"Enter the value for real part of the number\n";
		cin>>r;
		cout<<"Enter the imaginary part of the number\n";
		cin>>i;
		c2=complex(i,r);
	}
	complex c3;
	c3=add(c1,c2);
	disp(c3);

}