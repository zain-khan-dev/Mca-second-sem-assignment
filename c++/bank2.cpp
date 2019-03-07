#include<iostream>
using namespace std;
class account
{
	string username,password;
	int balance;
public:
	account()
	{
		username="zainkhan";
		password="Helloworld";
	}
	int validate(string u,string p)
	{
		if(u!=username)
			{
				cout<<"Wrong username entered\n";
				return 0;
			}
		else
			if(p!=password)
				{
					cout<<"The password entered is wrong\n";
					return 0;
				}
			else
				return 1;
	}
	void withdraw(int t)
	{
		balance-=t;
	}
	void deposit(int t)
	{
		balance+=t;
	}
	int getbalance()
	{
		return balance;
	}
};
int main()
{
	account a;
	string pass,user;
	int n,amount;
	do
	{
	cout<<"Enter your username\n";
	cin>>user;
	cout<<"Enter your password\n";
	cin>>pass;
	if(a.validate(user,pass)==0)
	{
		cout<<"Enter \n1 to exit\n";
		cout<<"2.To continue\n";
		cin>>n;
		if(n==1)
			break;
	}
	}while(a.validate(user,pass)==0);
	if(n==1)
		return 0;
	while(1)
	{
		cout<<"Enter what you want to do\n";
		cout<<"1.Deposit into the account\n";
		cout<<"2.Withdraw from the account\n";
		cout<<"3.Display information\n";
		cout<<"4.Exit\n";
		try
		{
			cin>>n;
			if(n>4)
				throw 'u';
		}
		catch(char y)
		{
			cout<<"Enter the value within the range\n";
			continue;
		}
		if(n==1)
		{
			cout<<"Enter the amount you want to deposit\n";
			cin>>amount;
			try
			{
				int negative;	 
				if(amount<0)
					throw negative;
				a.deposit(amount);
			}
			catch(int negative)
			{
				cout<<"You entered a value less than 0\n";
			}
		}
		else
		if(n==2)
		{
			try
			{

			cout<<"Enter the amount you want to withdraw\n";
			cin>>amount;
			if(amount>a.getbalance())
				throw 'a';
			else
				if(amount<0)
					throw 1;
			a.withdraw(amount);
			}
			catch(char a)
			{
				cout<<"The amount entered to be withdrawn is greater than the balance\n";
			}
			catch(int a)
			{
				cout<<"the amount to be withdrawn is less than zero\n";
			}
		}
		else if(n==3)
		{
			cout<<"The balance remaining is "<<a.getbalance()<<endl;
		}
		else
			if(n==4)
			{
				break;
			}
	}
}