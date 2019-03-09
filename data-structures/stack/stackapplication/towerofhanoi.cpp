#include<iostream>
using namespace std;
int hanoi(int n,char beg,char aux,char end)
{
	if(n==1)
	{
		cout<<"Move disk from "<<beg<<" to "<<end<<endl;
		return 0;
	}
	hanoi(n-1,beg,end,aux);
	hanoi(1,beg,aux,end);
	hanoi(n-1,aux,beg,end);

}
int main()
{
	int n;
	cin>>n;
	hanoi(n,'a','b','c');
}