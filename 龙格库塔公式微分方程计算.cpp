#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

float f(float x,float y)   //函数形式为y'=f(x,y)
{

	float f;
	f=-25*y;

	return f;

}

int main()
{
	cout<<"|—————————$本程序用于四阶龙格-库塔微分方程计算$————————|"<<endl;
	cout<<"|—————————$函数形式为y'=f(x,y)$———----------------—————|"<<endl;
	cout<<"方法："<<endl;
	cout<<"x0=x0; u0=y0; h为步长"<<endl;
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
	cerr<<"写入失败!"<<endl; exit(1);
	}

	cout<<"输入计算区间X0，Xn, 步长h,初值y0 :"<<endl;
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
		coutfile<<"_____________第"<<i<<"次计算————————"<<endl;
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