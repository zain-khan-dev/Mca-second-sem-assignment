#include<iostream>
using namespace std;
class distance1
{
	int feet,inches;
public:
	distance1()
	{
		feet=0;
		inches=0;
	}
	distance1(int p)
	{
		feet=inches=p;
	}
	void getdata(int f,int i)
	{
		feet=f;
		inches=i;
	}
	void show()
	{
		cout<<"The value of the distance is "<<feet<<" feet and "<<inches<<" inches\n";
	}
	int convert()
	{
		int totalinch;
		totalinch=this->feet*12+this->inches;
		return totalinch;
	}
	int operator<(distance1 d1)
	{
		if(this->convert()>d1.convert())
			return 0;
		else
			return 1;
	}
	distance1& operator+=(int n)
	{
		int p;
		p=this->inches+n;
		if(p>=12)
		{
		while(p>=12)
		{
			p=p-12;
			this->inches=p;
			this->feet++;
		}
		}
		else
		{
			this->inches=p;
		}
		return *this;
	}
};
int main()
{
	int f,i,n,p,a;
	distance1 d1;
	distance1 d2;
	cout<<"Enter the value in feet of the first distance\n";
	cin>>f;
	cout<<"Enter the value in inches of the first distance\n";
	cin>>i;
	d1.getdata(f,i);
	cout<<"Enter the value in feet of the second distance\n";
	cin>>f;
	cout<<"Enter the value in inches of the second distance\n";
	cin>>i;
	d2.getdata(f,i);
	while(1)
	{
		cout<<"Enter what you want to do\n1.Compare distance 1 and distance\n2.Add value in inches in distance\n";		
		cout<<"3.display the value of distance\nPress any other key to exit\n";
		cin>>n;
		if(n==1)
		{
		if(d1<d2)
			cout<<"Distance 1 is less than distance 2\n";
		else
			cout<<"Distance 2 is less than distance 1\n";
		}
		else
			if(n==2)
			{
				cout<<"In which distance do you want to add the value of inches\n";
				cout<<"1.IN the first distance \n";
				cout<<"2.In the second distance\n";
				cin>>p;
				if(p==1)
				{
					cout<<"Enter the value of inches you want to add in the first distance\n";
					cin>>a;
					d1+=a;
				}
				if(p==2)
				{
					cout<<"Enter the value of inches you want to add in the second distance\n";
					cin>>a;
					d2+=a;
				}
			}
			else if(n==3)
			{
				cout<<"which value you want to display\n1.Distance 1\n2.Distance 2\n";
				cin>>p;
				if(p==1)
				{
					d1.show();
				}
				if(p==2)
				{
					d2.show();
				}
			}
			else
			{
				break;
			}
			}
}
