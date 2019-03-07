#include<iostream>
using namespace std;
class vector;   //first class declaration
class matrix;  //second class declaration
class matrix
{
	int **b,n,m;   //n and m are variables that i want to access
public:
	matrix(int row,int column)
	{
		n=row;
		m=column;
		b=new int *[n];
		for(int i=0;i<n;i++)
			b[i]=new int[m];
	}
	void getmatrix()
	{
		cout<<"Enter the elements of the matrix\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>b[i][j];
			}
		}
	}
	void dismatrix()
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<b[i][j]<<" ";
			}
			cout<<endl;
		}

	}
	friend vector multiply(matrix &t,vector &v);
};
class vector
{
	int *a,p; //also want to access p
public:
	vector(int column)
	{
		p=column;
		a=new int[p];
	}
	void getvector()
	{
		cout<<"Enter the value of the vector\n";
		for(int i=0;i<p;i++)
			cin>>a[i];
	}
	void disvector()
	{
		for(int i=0;i<p;i++)
			cout<<a[i]<<" ";
	}
	friend vector multiply(matrix &t,vector &v);

};
vector multiply(matrix &t,vector &v)
	{
		vector v1(v.p); //problem is here showing p is not declared here
		for(int i=0;i<t.n;i++) //problem here also n was not declared here
		{
			int sum=0;
			for(int j=0;j<t.m;j++) //problem is here showing no match for m
			{
				sum=sum+v.a[j]*t.b[i][j];
			}
			v1.a[i]=sum;
		}
		return v1;

	}
int main()
{
	try
	{
	int mrow,mcol,vcol;
	cout<<"Enter the dimension of the row of the matrix\n";
	cin>>mrow;
	cout<<"Enter the dimension of the column of the matrix\n";
	cin>>mcol;
	cout<<"Enter the column of the vector to be multiplied\n";
	cin>>vcol;
	if(vcol!=mrow)
	{
		throw 'a';
	}
	matrix m(mrow,mcol);
	vector v(vcol);
	m.getmatrix();
	v.getvector();
	vector v1(vcol);
	v1=multiply(m,v);
	v1.disvector();
	}
	catch(char p)
	{
		cout<<"The matrix and vector multiplication cannot be done\n";
	}
}