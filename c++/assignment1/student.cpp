#include<iostream>
using namespace std;
void getpattern()
{
	for(int i=0;i<50;i++)
		cout<<"-";
	cout<<endl;
}
class student
{
	int rollno,mark1,mark2,mark3,total,average;
	string name;
	public:
		void getdata(string n,int r,int m1,int m2,int m3)
		{
			name=n;
			rollno=r;
			mark1=m1;
			mark2=m2;
			mark3=m3;
		}
		void displaydata(int i)
		{
			total=mark1+mark2+mark3;
			average=total/3;
			getpattern();
			cout<<"The name of the student "<<i+1<<" is "<<name<<endl;
			cout<<"The marks in the first subject of the "<<i+1<<" student are "<<mark1<<endl;
			cout<<"The marks in the second subject of the "<<i+1<<" student are "<<mark2<<endl;
			cout<<"The marks in the third subject of the "<<i+1<<" student are "<<mark3<<endl;
			cout<<"The total marks of the student of the "<<i+1<<" student are "<<total<<endl;
			cout<<"The average marks of the student of the "<<i+1<<" student are "<<average<<endl;
			getpattern();
		}
};
int main()
{
	string t;
	int r,m1,m2,m3,n;
	cout<<"Enter the number of students\n";
	cin>>n;
	student s[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the name of the "<<i+1<<" student\n";
		cin>>t;
		cout<<"Enter the roll number of the "<<i+1<<" student\n";
		cin>>r;
		cout<<"Enter the marks in the first subject of the "<<i+1<<" student\n";
		cin>>m1;
		cout<<"Enter the marks in the second subject of the "<<i+1<<" student\n";
		cin>>m2;
		cout<<"Enter the marks in the third subject of the "<<i+1<<" student\n";
		cin>>m3;
		s[i].getdata(t,r,m1,m2,m3);
	}
	for(int i=0;i<n;i++)
	{
		s[i].displaydata(i);
	}
}