#include<iostream>
using namespace std;


int main()
{
	int i,j,k,n,flag,count=1;
	float a[21][21],b[21],x[21],X[21],temp=0;

	cout<<"|————————$本程序用于线性方程组直接解法$————————|"<<endl;
	i=j=k=n=0;
	for(i=0;i<21;i++)
	{
		b[i]=0;
		x[i]=0;
		for(j=0;j<21;j++)
			a[i][j]=1;
			
	}

	
	cout<<"put n"<<endl;
	cin>>n;
	for(i=1;i<=n;i++)
	{	
		for(j=1;j<=n;j++)
		{
			cout<<"a"<<i<<j<<"=";
			cin>>a[i][j];
			
		}
	
	}
	for(i=1;i<=n;i++)
	{
		cout<<"b"<<i<<"=";
		cin>>b[i];
	}

	for(i=1;i<=n;i++)
	{
		cout<<"x"<<i<<"=";
		cin>>x[i];
	}
	
lab1: flag=0;	
cout<<count++<<"   ";
if(count>100)
{
	cout<<"发散"<<endl;
	goto lab2;
}

	for(i=1;i<=n;i++)
	{
		temp=0;
		for(j=1;j<i;j++)
			temp+=a[i][j]*X[j];
		for(j=i+1;j<=n;j++)
			temp+=a[i][j]*x[j];
		X[i]=(b[i]-temp)/a[i][i];
		cout<<"X"<<i<<"="<<X[i]<<"  ";
	
	}
	cout<<endl;
	for(i=1;i<=n;i++)
	{
		if(X[i]-x[i]!=0) 
		{ 
			flag=1;
			goto lab0;
		}
	}
lab0:	for(i=1;i<=n;i++)
	{
		x[i]=X[i];
	}
	if (flag==1)   goto lab1;
lab2:  cout<<endl;
	return 0;
}

	