#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

float f(float x,float y)   //������ʽΪy'=f(x,y)
{

	float f;
	f=-25*y;

	return f;

}

int main()
{
	cout<<"|������������������$�����������Ľ�����-����΢�ַ��̼���$����������������|"<<endl;
	cout<<"|������������������$������ʽΪy'=f(x,y)$������----------------����������|"<<endl;
	cout<<"������"<<endl;
	cout<<"x0=x0; u0=y0; hΪ����"<<endl;
	    cout<<"K1=h*f(x[i],u[i])"<<endl; 
		cout<<"K2=h*f(x[i]+h/2,u[i]+K1/2)"<<endl; 
		cout<<"K3=h*f(x[i]+h/2,u[i]+K2/2)"<<endl; 	
		cout<<"K4=h*f(x[i]+h,u[i]+K3)"<<endl;      
		cout<<"u[i+1]=u[i]+(K1+2*K2+2*K3+K4)/6"<<endl; 




	int i,N;
	float x0,xn,h,y0,*x,*u,K1,K2,K3,K4;

	ofstream coutfile;
	coutfile.open("D:t.txt",ios::out);
	if(!coutfile)
	{ 
	cerr<<"д��ʧ��!"<<endl; exit(1);
	}

	cout<<"�����������X0��Xn, ����h,��ֵy0 :"<<endl;
	cin>>x0>>xn>>h>>y0;
	
	N=(xn-x0)/h+2;
	x=new float[N];
	u=new float[N]; 
	x[0]=x0;
	for(i=0;i<N;i++)
	{
		x[i]=x0+i*h;
	
	}
	u[0]=y0;

	for(i=0;i<N;i++)
	{
		coutfile<<"_____________��"<<i<<"�μ��㡪��������������"<<endl;
		K1=h*f(x[i],u[i]);  coutfile<<"	K1="<<K1<<endl; 
		K2=h*f(x[i]+h/2,u[i]+K1/2);    coutfile<<"	K2="<<K2<<endl;  
		K3=h*f(x[i]+h/2,u[i]+K2/2);		   coutfile<<"	K3="<<K3<<endl;
		K4=h*f(x[i]+h,u[i]+K3);	       coutfile<<"	K4="<<K4<<endl;
		u[i+1]=u[i]+(K1+2*K2+2*K3+K4)/6; 
	}

	

	for(i=0;i<N;i++)
	{
		cout<<"X"<<i<<"="<<x[i];
		cout<<"		u"<<i<<"="<<u[i];
		cout<<endl;


	}

	for(i=0;i<N;i++)
	{
		coutfile<<"X"<<i<<"="<<x[i];
		coutfile<<"		u"<<i<<"="<<u[i];
		coutfile<<endl;


	}

	coutfile.close();
	system("D:t.txt");


	

	return 0;

}