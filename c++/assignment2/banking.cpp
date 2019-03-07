#include<iostream>
using namespace std;
class banking
{
	int amount, years;
	string type;
public:
	banking(int a,int y,string t)
	{
		amount=a;
		years=y;
		type=t;
	}
	double calculate()
	{
		double total;
		if(type=="savings")
		{
			if(years>=5)
				total=amount*(1.09);
			else
				total=amount*(1.06);
		}
		else
			if(type=="current")
			{
				total=amount*(1.04);
			}
		return total;
	}
};
int main()
{
	int am,ye;
	string t;
	cout<<"Enter the amount in the bank\n";
	cin>>am;
	cout<<"Enter the duration of the account\n";
	cin>>ye;
	cout<<"Enter the type of the bank account\n";
	cin>>t;
	banking b(am,ye,t);
	cout<<b.calculate();
}