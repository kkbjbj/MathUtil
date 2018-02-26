#include<iostream>
using namespace std;

int main()
{
	int i,n;
	float t1,t2,a,b,x[30],y[30],X,Y;
	t1=0;
	t2=0;
	X=0;
	Y=0;
	cout<<"|————————————$本程序用于最小二乘法a,b计算$——————————|"<<endl;
	cout<<endl;
	cout<<"b=( {for i=1..n} (xi-X)*(yi-Y))/( {fori=1..n} (xi-X)^2 )"<<endl;
	cout<<"a=Y-bX  X,Y为平均值"<<endl;
	cout<<endl;
	cout<<"输入数据组数n:"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<" 输入x"<<i<<endl;
		cin>>x[i];
		cout<<" 输入"<<i<<endl;
		cin>>y[i];
	}
	for(i=0;i<n;i++)  X+=x[i];
	X=X/n;
	cout<<"X="<<X<<endl;
	for(i=0;i<n;i++)   Y+=y[i];
	Y=Y/n;
	cout<<"Y="<<Y<<endl;
	for(i=0;i<n;i++)
	{
		t1+=(x[i]-X)*(y[i]-Y);
		t2+=(x[i]-X)*(x[i]-X);

	}
	b=t1/t2;
	a=Y-b*X;
	cout<<"___________________________"<<endl;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"|—|—|—|——————————$本次计算结束$———————|—|—|—|"<<endl;
	getchar();
	getchar();

	return 0;
}