#include<iostream>
using namespace std;
struct buffer
{
	int arrival;
	int burst;
};
int main()
{
	int n;
	cout<<"Enter the number of jobs\n";
	cin>>n;
	buffer b[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the arrival time of the "<<i+1<<"job\n";
		cin>>b[i].arrival;
		cout<<"Enter the burst time of the "<<i+1<<"job\n";
		cin>>b[i].burst;
	}
	int timer=b[0].arrival,min=b[0].burst,sum=0;
	while(1)
	{
		int a[100];
		int index,in,count=0;
		for(int i=0;i<n;i++)
		{
			if(b[i].burst==0)
				count++;
		}
		if(count==n)
			break;
		int k=0;
		for(int i=0;i<n;i++)
		{
			if(b[i].arrival<=timer&&b[i].burst!=0)
			{
				a[k]=b[i].burst;
				k++;
				in=i;
			}
		}
		min=a[0];
		for(int i=1;i<k;i++)
		{
			if(a[i]<min)
			min=a[i];
		}
		sum=sum+min;
		for(int i=0;i<n;i++)
		{
			if(min==b[i].burst)
			{
				cout<<"The job currently going on  is "<<i+1<<"\n";
				b[i].burst=0;
				break;
			}
		}
		timer=sum;
	}
	cout<<sum;
}
