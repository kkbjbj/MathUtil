#include <iostream>
using namespace std;

float L_insert(int ,float *,float *,float);

int main()
{
	int i;
	int n=0;
	char again;
	float x[20],y[20],X,Y;
	
lb: cout<<"|��������������������������$�������������������ղ�ֵ����$��������������������|"<<endl;
	cout<<"Y=L(X)= {i=0->n} yi*Wn+1(xi)/((X-xi)*W'n+1(xi)) ��n+1��"<<endl;
	cout<<"Wn+1=(X-x0)*....*(X-xn) XΪ��ֵ��"<<endl;
	cout<<"W'n+1(xi)=(xi-x0)*....*(xi-xn)  ������(xi-xi)"<<endl;
	cout<<"�����ֵ����(С��20):"<<endl;
	cin>>n;
	for(i=0;i<=n;i++)
	{
		cout<<"����x"<<i<<endl;
		cin>>x[i];
	}
	for(i=0;i<=n;i++)
	{
		cout<<"����y"<<i<<endl;
		cin>>y[i];
	}
	cout<<"����������X:"<<endl;
	cin>>X;
	Y=L_insert(n,x,y,X);
	cout<<"����ֵY="<<Y<<endl;
	cout<<"|��|��|��|��������������������$���μ������$��������������|��|��|��|"<<endl;
	cout<<"�Ƿ��������Y/N?"<<endl;
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
		cout<<"��"<<i+1<<"��="<<a*y[i]/(b*(X-x[i]))<<endl;
	}

	return (Y);
}