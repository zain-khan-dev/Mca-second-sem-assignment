#include<iostream>
using namespace std;
class complex
{
	int real,img;
public:
	complex()
	{
		real=0;
		img=0;
	}
	complex(int r,int i)
	{
		real=r;
		img=i;
	}
	complex operator +(complex c1)
	{
		complex c2;
		c2.real=this->real+c1.real;
		c2.img=this->img+c1.img;
		return c2;
	}
	void disp()
	{
		cout<<" "<<this->real<<"+"<<this->img<<"i ";
	}
};
int main()
{
	int r,i;
	cout<<"Enter the real part of the first number\n";
	cin>>r;
	cout<<"Enter the imaginary part of the first number\n";
	cin>>i;
	complex c1(r,i);
	cout<<"Enter the real part of the second number\n";
	cin>>r;
	cout<<"Enter the imaginary part of the second number\n";
	cin>>i;
	complex c2(r,i);
	complex c3;
	c3=c1+c2;
	c1.disp();
	cout<<"+";
	c2.disp();
	cout<<"=";
	c3.disp();
}