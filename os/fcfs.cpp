#include<iostream>
using namespace std;
class link
{
	int arrival;
	int burst;
	link *next;
public:
	link* createnode(int n,link *first)
	{
		link *p;
		p=first;
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				first=new link;
				p=first;
				int r;
				cout<<"Enter the arrival time of the 1 job\n";
				cin>>r;
				p->arrival=r;
				cout<<"Enter the burst time of the 1 job\n";
				cin>>r;
				p->burst=r;
				p->next=NULL;

			}
			else
			{
				int r;
				p->next=new link;
				cout<<"Enter the arrival time of the "<<i+1<<"job\n";
				cin>>r;
				p->next->arrival=r;
				cout<<"Enter the burst time of the "<<i+1<<"job\n";
				cin>>r;
				p->next->burst=r;
				p->next->next=NULL;
				p=p->next;
			}
		}
		return first;
		
	}
	int turnaround(link *first)
	{
		link *p=first;
		int sum=0,diff;
		while(p!=NULL)
		{
			if(sum>=p->arrival)
			{
			sum=sum+p->burst;
			}
			if(sum<p->arrival)
			{
			sum=p->burst+p->arrival;
			}
			p=p->next;
		}
		return sum;
	}
};
int main()
{
	int n,s;
	cout<<"Enter the number of nodes\n";
	cin>>n;
	link *first,*p;
	first=p->createnode(n,first);
	s=p->turnaround(first);
	cout<<s;
}