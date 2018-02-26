#include<iostream>
using namespace std;

void showLU(float L[][21],float U[][21],int n);
void showxy(float x[],float y[],int n);

int main()
{
	cout<<"||=============本程序用于LU分解三对角线方程组================||"<<endl;
	int i,j,k,l,n;
	float a[21][21],b[21],L[21][21],U[21][21],x[21],y[21];
	float temp1,temp2;
	temp1=temp2=0;


	i=j=k=n=0;
	for(i=0;i<21;i++)
	{
		b[i]=0;
		x[i]=0;
		for(j=0;j<21;j++)
		{	a[i][j]=1;
			L[i][j]=U[i][j]=0;
		}
	}
	
	cout<<"put n"<<endl;
	cin>>n;
	for(i=1;i<=n;i++)
	{	
		x[i]=y[i]=0;
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

	for(i=1;i<=n;i++)          //A=LU     get L[left down]  U[right 1 up]
	{
		U[i][i]=1;
		for(j=1;j<=i;j++)
		{
			cout<<"L"<<i<<j<<"=";
			cout<<a[i][j]<<"- (";
			temp1=0;
			for(k=1;k<=i-1;k++)
			{
					temp1+=L[i][k]*U[k][j]; 
					cout<<L[i][k]<<"*"<<U[k][j]<<"+";  
					
			
			} 
			cout<<" )"<<endl;
			L[i][j]=a[i][j]-temp1;

		}
		for(l=i+1;l<=n;l++)
		{
			temp2=0;
			cout<<"U"<<i<<l<<"=";
			cout<<" {"<<a[i][l]<<"- (";
			for(k=1;k<=i-1;k++)
			{
					 
					temp2+=L[i][k]*U[k][l]; 
					cout<<L[i][k]<<"*"<<U[k][l]<<"+"; 
			
			} 
			cout<<" ) }/ "<<L[i][i]<<endl;
			U[i][l]=(a[i][l]-temp2)/L[i][i];

		}

	}
	showLU(L,U,n);

	for(i=1;i<=n;i++)    //LY=b  get y[1...n]
	{
		temp1=0;
		cout<<"y"<<i<<"=";
		cout<<b[i]<<"- (";
		for(k=1;k<=i-1;k++)
		{
			temp1+=L[i][k]*y[k];
			cout<<L[i][k]<<"*"<<y[k]<<"+";
		}
		cout<<" )/ "<<L[i][i]<<endl;
		y[i]=(b[i]-temp1)/L[i][i];
	}

	for(i=n;i>=1;i--)    //UX=Y   get x[1...n]
	{
		temp1=0;
		cout<<"x"<<i<<"=";
		cout<<y[i]<<"- (";
		for(k=i+1;k<=n;k++)
		{
			temp1+=U[i][k]*x[k];
			cout<<U[i][k]<<"*"<<x[k]<<"+";
		}

		cout<<" ) "<<endl;
		x[i]=y[i]-temp1;
	}
	
	
	showxy(x,y,n);

	getchar();
	getchar();
	return 0;


}

void showLU(float L[][21],float U[][21],int n)
{
	int i,j;
	cout<<"__________________________"<<endl;
	for(i=1;i<=n;i++)
	{	
		for(j=1;j<=n;j++)
		{
			cout<<L[i][j]<<"	";
			
			
		}
	cout<<endl;
	}
	cout<<"__________________________"<<endl;
	for(i=1;i<=n;i++)
	{	
		for(j=1;j<=n;j++)
		{
			cout<<U[i][j]<<"	";
			
			
		}
		cout<<endl;
	cout<<"__________________________"<<endl;
	cout<<endl;
	}

}

void showxy(float x[],float y[],int n)
{
	int i;
	cout<<"__________________________"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"y"<<i<<"=";
		cout<<y[i]<<endl;
	}
	cout<<"__________________________"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"x"<<i<<"=";
		cout<<x[i]<<endl;
	}
	cout<<"__________________________"<<endl;

}
