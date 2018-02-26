#include <iostream>
using namespace std;

float L_insert(int ,float *,float *,float);

int main()
{
	int i;
	int n=0;
	char again;
	float x[20],y[20],X,Y;
	
lb: cout<<"|—————————————$本程序用于拉格良朗日插值计算$——————————|"<<endl;
	cout<<"Y=L(X)= {i=0->n} yi*Wn+1(xi)/((X-xi)*W'n+1(xi)) 共n+1项"<<endl;
	cout<<"Wn+1=(X-x0)*....*(X-xn) X为插值点"<<endl;
	cout<<"W'n+1(xi)=(xi-x0)*....*(xi-xn)  但不含(xi-xi)"<<endl;
	cout<<"输入插值次数(小于20):"<<endl;
	cin>>n;
	for(i=0;i<=n;i++)
	{
		cout<<"输入x"<<i<<endl;
		cin>>x[i];
	}
	for(i=0;i<=n;i++)
	{
		cout<<"输入y"<<i<<endl;
		cin>>y[i];
	}
	cout<<"输入待求变量X:"<<endl;
	cin>>X;
	Y=L_insert(n,x,y,X);
	cout<<"待求值Y="<<Y<<endl;
	cout<<"|—|—|—|——————————$本次计算结束$———————|—|—|—|"<<endl;
	cout<<"是否继续计算Y/N?"<<endl;
	cin>>again;
	if(again=='Y'||again=='y')   goto lb;

	return 0;

}
float L_insert(int n,float *x,float *y,float X)
{
	int i,j,k;
	float a,b,c,Y;
	Y=0;
	for(i=0;i<=n;i++)
	{
		a=b=1;
		for(j=0;j<=n;j++)  a=a*(X-x[j]);
		for(k=0;k<=n;k++)  
		{
			if(k!=i)
			
				b=b*(x[i]-x[k]);
			
		}
		Y=Y+a*y[i]/(b*(X-x[i]));
		cout<<"第"<<i+1<<"项="<<a*y[i]/(b*(X-x[i]))<<endl;
	}

	return (Y);
}