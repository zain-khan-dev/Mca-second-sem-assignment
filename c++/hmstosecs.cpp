#include<iostream>
#include<regex>
using namespace std;
long hmstosecs(int h,int m,int s)
{
	long int p;
	p=h*3600+m*60+s;
	return p;
}
int main()
{
	int n=0;
	cout<<"Enter the time in the format hh:mm:ss\n";
	string a;
	cin>>a;
	regex b("[0-1][0-9](:)[0-6][0-9](:)[0-6][0-9]");
	while(regex_match(a,b)==0)
	{
		cout<<"You entered an invalid time format please enter in the form hh:mm:ss\n";
		cout<<"Press\n1.To exit\n2.To continue\n";
		cin>>n;
		if(n==1)
			break;
		else
			if(n==2)
			cin>>a;
		else
			cout<<"Invalid choice\n";
	}
	if(n!=1)
	{
	int hour=(a[0]-48)*10+(a[1]-48);
	int minutes=(a[2]-48)*10+(a[3]-48);
	int seconds=(a[4]-48)*10+(a[5]-48);
	cout<<hmstosecs(hour,minutes,seconds);
}

}