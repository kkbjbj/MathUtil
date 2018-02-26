#include<iostream>
using namespace std;


int main()
{
	int i,j,k,n,flag=0,count=1;
	float a[21][21],b[21],x[21],X[21],t[21],w,temp=0;

	cout<<"|————————$本程序用于线性方程组迭代解法$————————|"<<endl;
	cout<<"雅可比  Xi=(bi-{j=1:n &!=i}aij*xi)/aii"<<endl;
	cout<<"G-S     Xi=(bi-{j=1:i-1 }aij*Xi-{j=i+1:n }aij*xi)/aii"<<endl;
	cout<<"SOR　　Xi=xi+w*(bi-{j=1:i-1 }aij*Xi-{j=i:n }aij*xi)/aii"<<endl;
	cout<<"或SOR　　Xi=(1-w)*xi+w*G-S"<<endl;

	i=j=k=n=0;
	for(i=0;i<21;i++)
	{
		b[i]=0;
		x[i]=0;
		for(j=0;j<21;j++)
			a[i][j]=1;
			
	}

	cout<<"输入未知数个数："<<endl;
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
		t[i]=x[i];
	}
cout<<"____________雅可比迭代解法____________"<<endl;	
lab1: flag=0;
         if(count>100)
         {
         	cout<<"雅可比迭代发散"<<endl;
         goto lab2;
         }
         cout<<count++<<"   ";
	  
	for(i=1;i<=n;i++)
	{
		temp=0;
		for(j=1;j<=n;j++)
			if(i!=j) temp+=a[i][j]*x[j];
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

cout<<"____________G-S迭代解法____________"<<endl;
for(i=1;i<=n;i++)
	{
	x[i]=t[i];
	}
count=1;
lab11: flag=0;	
cout<<count++<<"   ";
if(count>100)
{
	cout<<"G-S迭代发散"<<endl;
	goto lab21;
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
			goto lab01;
		}
	}
lab01:	for(i=1;i<=n;i++)
	{
		x[i]=X[i];
	}
	if (flag==1)   goto lab11;
lab21:  cout<<endl;

cout<<"____________SOR迭代解法____________"<<endl;

		cout<<"输入松弛因子w"<<endl;
		cin>>w;
		for(i=1;i<=n;i++)
	{
	x[i]=t[i];
	}
count=1;
lab12: flag=0;	
cout<<count++<<"   ";
if(count>100)
{
	cout<<"SOR迭代发散"<<endl;
	goto lab22;
}

	for(i=1;i<=n;i++)
	{
		temp=0;
		for(j=1;j<i;j++)
			temp+=a[i][j]*X[j];
		for(j=i;j<=n;j++)
			temp+=a[i][j]*x[j];
		X[i]=x[i]+w*(b[i]-temp)/a[i][i];
		cout<<"X"<<i<<"="<<X[i]<<"  ";
	
	}
	cout<<endl;
	for(i=1;i<=n;i++)
	{
		if(X[i]-x[i]!=0) 
		{ 
			flag=1;
			goto lab02;
		}
	}
lab02:	for(i=1;i<=n;i++)
	{
		x[i]=X[i];
	}
	if (flag==1)   goto lab12;
lab22:  cout<<endl;
		
	return 0;
}

	