#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

float f(float x,float y)   //函数形式为y'=f(x,y)
{

	float f;
	f=-21.6*y;

	return f;

}

int main()
{
	cout<<"|—————————$本程序用于 欧拉公式 计算微分方程解$————————|"<<endl;
	cout<<"|—————————$函数形式为y'=f(x,y)$———----------------—————|"<<endl;
		cout<<"|————方法：u0=y0; ui+1=ui+h*f(xi,ui) ;(h为步长)—--————|"<<endl;
		cout<<endl;


	int i,N;
	float x0,xn,h,y0,*x,*u;

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
		u[i+1]=u[i]+h*f(x[i],u[i]);

		coutfile<<i<<"	f(xi,ui)=f("<<x[i]<<" , "<<u[i]<<") ="<<f(x[i],u[i])<<endl;
	
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
