#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

float f(float x,float y,float z)   //函数形式为y'=f(x,y,z)  && z'=f(x,y,z)
{

	float f;
	f=x*z+1;

	return f;

}

float f1(float x,float y,float z)  
{

	float f;
	f=-1*x;

	return f;

}

int main()
{
	cout<<"|—————————$本程序用于四阶龙格-库塔微分方程组计算$————————|"<<endl;
	cout<<"|—————————$函数形式为y'=f(x,y,z) && z'=f(x,y,z)$------—————|"<<endl;
	cout<<"方法："<<endl;
	cout<<"x0=x0; u0=y0; v0=z0; h为步长"<<endl;
	 	cout<<"L1=h*f1(x[i],u[i],v[i])"<<endl;
		cout<<"K1=h*f(x[i],u[i],v[i])"<<endl;
		cout<<"L2=h*f1(x[i]+h/2,u[i]+K1/2,v[i]+L1/2)"<<endl;
		cout<<"K2=h*f(x[i]+h/2,u[i]+K1/2,v[i]+L1/2)"<<endl;
		cout<<"L3=h*f1(x[i]+h/2,u[i]+K2/2,v[i]+L2/2)"<<endl;
		cout<<"K3=h*f(x[i]+h/2,u[i]+K2/2,v[i]+L2/2)"<<endl;
		cout<<"L4=h*f1(x[i]+h/2,u[i]+K3,v[i]+L3)"<<endl;
		cout<<"K4=h*f(x[i]+h,u[i]+K3,v[i]+L3)"<<endl;
		cout<<"v[i+1]=v[i]+(L1+2*L2+2*L3+L4)/6"<<endl; 
		cout<<"u[i+1]=u[i]+(K1+2*K2+2*K3+K4)/6"<<endl;

	cout<<endl;


	int i,N;
	float x0,xn,h,y0,z0,*x,*u,*v;
	float K1,K2,K3,K4,L1,L2,L3,L4;

	ofstream coutfile;
	coutfile.open("D:t.txt",ios::out);
	if(!coutfile)
	{ 
	cerr<<"写入失败!"<<endl; exit(1);
	}

	cout<<"输入计算区间X0, Xn, 步长h,初值y0, z0 :"<<endl;
	cin>>x0>>xn>>h>>y0>>z0;
	
	N=(xn-x0)/h+1;
	x=new float[N];
	u=new float[N]; 
	v=new float[N]; 

	x[0]=x0;
	for(i=0;i<N;i++)
	{
		x[i]=x0+i*h;
	
	}
	u[0]=y0;
	v[0]=z0;
	
	for(i=0;i<N;i++)
	{
		coutfile<<"_____________第"<<i<<"次计算————————"<<endl;
		L1=h*f1(x[i],u[i],v[i]);	coutfile<<"L1="<<L1;  
		K1=h*f(x[i],u[i],v[i]);  coutfile<<"	K1="<<K1<<endl; 
		L2=h*f1(x[i]+h/2,u[i]+K1/2,v[i]+L1/2);  coutfile<<"L2="<<L2;
		K2=h*f(x[i]+h/2,u[i]+K1/2,v[i]+L1/2);  coutfile<<"	K2="<<K2<<endl; 
		L3=h*f1(x[i]+h/2,u[i]+K2/2,v[i]+L2/2);  coutfile<<"L3="<<L3;
		K3=h*f(x[i]+h/2,u[i]+K2/2,v[i]+L2/2);   coutfile<<"	K3="<<K3<<endl;
		L4=h*f1(x[i]+h/2,u[i]+K3,v[i]+L3);   coutfile<<"L4="<<L4;
		K4=h*f(x[i]+h,u[i]+K3,v[i]+L3);	  coutfile<<"	K4="<<K4<<endl;

		v[i+1]=v[i]+(L1+2*L2+2*L3+L4)/6; 
		u[i+1]=u[i]+(K1+2*K2+2*K3+K4)/6; 


	}

	for(i=0;i<N;i++)
	{
		cout<<"X"<<i<<"="<<x[i];
		cout<<"		u"<<i<<"="<<u[i];
		cout<<"		v"<<i<<"="<<v[i];
		cout<<endl;


	}

	
	for(i=0;i<N;i++)
	{
		coutfile<<"X"<<i<<"="<<x[i];
		coutfile<<"		u"<<i<<"="<<u[i];
		coutfile<<"		v"<<i<<"="<<v[i];
		coutfile<<endl;


	}


	

	coutfile.close();
	system("D:t.txt");


	return 0;

}


