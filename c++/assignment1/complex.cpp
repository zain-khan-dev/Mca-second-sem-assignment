#include<iostream>
using namespace std;
class complex
{
	int real,img;
public:
	void getdata(int r, int i)
	{
		real=r;
		img=i;
	}
	void show()
	{
		cout<<"The number is "<<real<<"+"<<img<<"i"<<endl;
	}
	void sum(complex c1,complex &c2)
	{
		c2.real=this->real+c1.real;
		c2.img=this->img+c1.img;
	}
};
int main()
{
	complex c1,c2,c3;
	int r,i;
	cout<<"Enter the real part of the first number\n";
	cin>>r;
	cout<<"Enter the imaginary part of the first number\n";
	cin>>i;
	c1.getdata(r,i);
	cout<<"Enter the real part of the second number\n";
	cin>>r;
	cout<<"Enter the imaginary part of the second number\n";
	cin>>i;
	c2.getdata(r,i);
	c1.sum(c2,c3);
	c3.show();
}