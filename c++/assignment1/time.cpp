#include<iostream>
using namespace std;
void getpattern()
{
	for(int i=0;i<40;i++)
		cout<<"-";
	cout<<endl;
}
class Time
{
	int hour,minutes;
public:
	Time()
	{
		hour=0;
		minutes=0;
	}
	void gettime(int h,int m)
	{
		hour=h;
		minutes=m;
	}
	Time sum(Time t2)
	{
		Time t3;
		int m;
		m=this->minutes+t2.minutes;
		if(m>=60)
			{
				m=m-60;
				t3.hour++;
			}
		t3.minutes=t3.minutes+m;
		t3.hour=t3.hour+this->hour+t2.hour;
		return t3;
	}
	void display()
	{
		getpattern();
		cout<<"The hours are equal to "<<this->hour<<endl;
		cout<<"The minutes are equal to "<<this->minutes<<endl;
		getpattern();
	}
};
int main()
{
	int h,m;
	cout<<"Enter the hours of the first clock\n";
	cin>>h;
	cout<<"Enter the minutes of the first clock\n";
	cin>>m;
	Time t1,t2,t3;
	t1.gettime(h,m);
	cout<<"Enter the hour of the second clock\n";
	cin>>h;
	cout<<"Enter the minutes of the second clock\n";
	cin>>m;
	t2.gettime(h,m);
	t3=t1.sum(t2);
	t3.display();

}
