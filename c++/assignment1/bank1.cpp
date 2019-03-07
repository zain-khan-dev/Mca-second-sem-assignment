#include<iostream>
typedef unsigned long long int ull;
using namespace std;
void getpattern()
{
	for(int i=0;i<50;i++)
	{
		cout<<"-";
	}
	cout<<endl;
}
class account
{
	string name,type;
	ull account,balance;
public:
	void getvalues(string n,string t,ull a,ull b)
	{
		name=n;
		type=t;
		account=a;
		balance =b;
	}
	void deposit(int t)
	{
		balance+=t;
	}
	void withdraw(int t)
	{
		balance-=t;
	}
	int getbalance()
	{
		return balance;
	}
	void display()
	{
		getpattern();
		cout<<"The name of the account holder is "<<name<<endl;
		cout<<"The account number of the account holder is "<<account<<endl;
		cout<<"The type of the account is "<<type<<endl;
		cout<<"The amount left in the account is "<<balance<<endl;
		getpattern();
	}

};
int main()
{

	account a;
	ull account,balance,n;
	int amount;
	string name,type;
	cout<<"Enter the name of the account holder\n";
	getline(cin,name);
	cout<<"Enter the account number of the account holder\n";
	cin>>account;
	cout<<"Enter the type of the account either savings or current\n";
	cin>>type;
	cout<<"Enter the balance of the account\n";
	cin>>balance;
	a.getvalues(name,type,account,balance);
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
			a.display();
		}
		else
			if(n==4)
			{
				break;
			}
	}	
}
