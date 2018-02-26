#include<iostream>
using namespace std;


int main()
{
	cout<<"||=============本程序用于追赶法解三对角线方程组================||"<<endl;
	int i,j,k,l,n;
	float a[31],b[31],c[31],d[31],x[31],w[31],g[31];
	
	for(i=0;i<31;i++)
	{
		a[i]=b[i]=c[i]=w[i]=x[i]=0;

	}
	cout<<"put n"<<endl;
	cin>>n;
	for(i=1;i<=n;i++)
	{	
		cout<<"b"<<i<<"=";
		cin>>b[i];
	}
	for(i=1;i<=n-1;i++)
	{	
		cout<<"a"<<i<<"=";
		cin>>a[i];
	}
	for(i=1;i<=n-1;i++)
	{	
		cout<<"c"<<i<<"=";
		cin>>c[i];
	}
	for(i=1;i<=n;i++)
	{	
		cout<<"d"<<i<<"=";
		cin>>d[i];
		cout<<endl;
	}

	w[1]=c[1]/b[1];
	cout<<"________________________"<<endl;
	cout<<"w[i]=c[i]/(b[i]-a[i-1]*w[i-1])"<<endl;
	cout<<"w1=c1/b1="<<w[1]<<endl;
	for(i=2;i<=n-1;i++)        //change c[] to w[] to make a[1..n]=0 and b[1...n]=1 
	{
		w[i]=c[i]/(b[i]-a[i-1]*w[i-1]);
		cout<<"w"<<i<<"="<<c[i]<<" / (";
		cout<<b[i]<<"-"<<a[i-1]<<"*"<<w[i-1]<<" )="<<w[i]<<endl;


	}
	g[1]=d[1]/b[1];
	cout<<"________________________"<<endl;
	cout<<"g[i]=(d[i]-a[i-1]*g[i-1])/(b[i]-a[i-1]*w[i-1])"<<endl;
	cout<<"g1=d1/b1="<<g[1]<<endl;
	for(i=2;i<=n;i++)       //Ad=g   get g[1...n]
	{
		g[i]=(d[i]-a[i-1]*g[i-1])/(b[i]-a[i-1]*w[i-1]);
		cout<<"g"<<i<<"=( "<<d[i]<<"-"<<a[i-1]<<"*"<<g[i-1];
		cout<<")/("<<b[i]<<"-"<<a[i-1]<<"*"<<w[i-1]<<"="<<g[i]<<endl;
	
	}


	x[n]=g[n];
	cout<<"________________________"<<endl;
	cout<<"x[i]=g[i]-w[i]*x[i+1]"<<endl;
	cout<<"x"<<n<<"=g"<<n<<"="<<x[n]<<endl;
	for(i=n-1;i>=1;i--)             //get x[1...n]
	{
		x[i]=g[i]-w[i]*x[i+1];
		cout<<"x"<<i<<"="<<g[i]<<"-"<<w[i]<<"*"<<x[i+1]<<"="<<x[i]<<endl;
	
	}
	cout<<"________________________"<<endl;
	for(i=1;i<=n;i++)
		cout<<"x"<<i<<"="<<x[i]<<endl;


	getchar();
	getchar();

	return 0;

	

}