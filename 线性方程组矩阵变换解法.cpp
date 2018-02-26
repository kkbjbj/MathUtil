#include<iostream>
using namespace std;

void show(float a[][21],float b[],int n);

int main()
{
	int i,j,k,n;
	float a[21][21],b[21],x[21],l[21][21],h[21],temp=0;

	cout<<"|————————$本程序用于线性方程组直接解法矩阵变换$————————|"<<endl;
	i=j=k=n=0;
	for(i=0;i<21;i++)
	{
		b[i]=0;
		x[i]=0;
		for(j=0;j<21;j++)
			a[i][j]=1;
			l[i][j]=1;
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

	
	
	for(i=1;i<=n-1;i++)            //消元过程
	{
		cout<<"===========本次变换结果==============="<<endl;
		for(j=i+1;j<=n;j++)
		{
			
			l[j][i]=a[j][i]/a[i][i];
			cout<<l[j][i]<<endl;
			b[j]=b[j]-b[i]*l[j][i];
			for(k=1;k<=n;k++)
			{
				a[j][k]=a[j][k]-a[i][k]*l[j][i];
				

			}
		}

		show(a,b,n);
	}
	
	x[n]=b[n]/a[n][n];         //回代过程
	for(i=n-1;i>0;i--)
	{
		temp=0;
		for(j=i+1;j<=n;j++)
		{
			temp+=a[i][j]*x[j];
		}

		x[i]=(b[i]-temp)/a[i][i];
	}

	for(i=1;i<=n;i++)
	{
	
		cout<<"b"<<i<<"="<<b[i]<<endl;
		
	}

	
	for(i=1;i<=n;i++)
	{
	
		cout<<"x"<<i<<"="<<x[i]<<endl;
		
	}
	cout<<"|—|—|—|——————————$本次计算结束$———————|—|—|—|"<<endl;
	return 0;
}

void show(float a[][21],float b[],int n)
{
	int i,j;
	
	for(i=1;i<=n;i++)
	{	for(j=1;j<=n;j++)
		{
		 cout<<a[i][j]<<"   ";
			
		}
	cout<<"			"<<b[i];
	cout<<endl;
	}

	
}