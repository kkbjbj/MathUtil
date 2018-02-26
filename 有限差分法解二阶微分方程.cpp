#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;



float p(float x)
{
	return 0.0;
}
float q(float x)
{
	return -0.25;
}
float rr(float x)
{
	return -8.0;
}
void help();
void zuigan(int n,float *a,float *b,float *c,float *d,float *u);

int main()
{

	int i,N;
	float *x,*a,*b,*c,*u,*r;
	float x0,xN,h,y0,yN;
	help();
	cout<<"input x0,xN+1,y0,yN+1,N+1"<<endl;
	cin>>x0>>xN>>y0>>yN>>N;
	h=(xN-x0)/N;
	
	cout<<"N+1="<<N;
	x=new float[N+1];
	a=new float[N+1];
	b=new float[N+1];
	c=new float[N+1];
	u=new float[N+1];
	r=new float[N+1];

	ofstream outfile;
	outfile.open("D:t.txt",ios::out);
	if(!outfile)
	{ 
	cerr<<"写入失败!"<<endl; exit(1);
	}

	N=N-1;

	for(i = 0;i <= N+1;i++)
	{
		x[i] = x0 + i*h;
	
	}

	for(i=1;i<=N;i++)
	{
		a[i] = -0.5*(1 + h*p(x[i])/2 );

		b[i] =( 1 + h*h*q(x[i])/2 );

		c[i] = -0.5*(1 - h*p(x[i])/2 );
		
	}

	r[1] =0.5*h*h*( rr(x[1]) - 2*a[1]*y0/(h*h) );
	r[N] =0.5*h*h*( rr(x[N]) - 2*c[N]*yN/(h*h) );

	for(i = 2;i < N;i++)
	{
		r[i] = h*h*rr(x[i])/2;
	
	}

	for(i=1;i<=N;i++)
	{
		//cout<<"a"<<i<<"="<<a[i]<<endl;
		outfile<<"a"<<i<<"="<<a[i]<<endl;
	}
	for(i=1;i<=N;i++)
	{
		//cout<<"b"<<i<<"="<<b[i]<<endl;
		outfile<<"b"<<i<<"="<<b[i]<<endl;
	}
	for(i=1;i<=N;i++)
	{
		//cout<<"c"<<i<<"="<<c[i]<<endl;
		outfile<<"c"<<i<<"="<<c[i]<<endl;
	}
	for(i=1;i<=N;i++)
	{
		//cout<<"r"<<i<<"="<<r[i]<<endl;
		outfile<<"r"<<i<<"="<<r[i]<<endl;
	}
	

	for(i=1;i<=N;i++)
	{
		a[i]=a[i+1];
	}
	zuigan(N,a,b,c,r,u);

	for(i=1;i<=N;i++)
	{
		cout<<"Y("<<x[i]<<")="<<u[i]<<endl;
		outfile<<"Y("<<x[i]<<")="<<u[i]<<endl;
	}
	
	outfile.close();
	system("D:t.txt");




	return 0;

}

void help()
{
	cout<<"|—————————$本程序用于二阶微分方程边值计算$————————|"<<endl;
	cout<<"|—————————$函数形式为: -y\" + p(x)*y' + q(x)*y =r(x) ———----------------—————|"<<endl;
	cout<<"方法："<<endl;
	cout<<"ai=-0.5(1+0.5h*p(xi))"<<endl;
	    cout<<"bi=1+0.5h*h*q(xi)"<<endl; 
		cout<<"ci=-0.5(1-0.5h*p(xi)"<<endl; 
		cout<<"解a，b，c的三对角线方程(中b1..bn;下a2..an;上c1..cn-1)"<<endl;
		

}

void zuigan(int n,float *a,float *b,float *c,float *d,float *u)
{
	cout<<"||=============本程序用于追赶法解三对角线方程组================||"<<endl;
	int i,j,k,l;
	float *x,*w,*g;
	x=new float[n+2];
	w=new float[n+2];
	g=new float[n+2];
	for(i=0;i<31;i++)
	{
		w[i]=x[i]=0;

	}


	w[1]=c[1]/b[1];
	cout<<"________________________"<<endl;
	cout<<"w[i]=c[i]/(b[i]-a[i-1]*w[i-1])"<<endl;
	cout<<"w1=c1/b1="<<w[1]<<endl;
	for(i=2;i<=n-1;i++)        //change c[] to w[] to make a[1..n]=0 and b[1...n]=1 
	{
		w[i]=c[i]/(b[i]-a[i-1]*w[i-1]);
		//cout<<"w"<<i<<"="<<c[i]<<" / (";
		//cout<<b[i]<<"-"<<a[i-1]<<"*"<<w[i-1]<<" )="<<w[i]<<endl;


	}
	g[1]=d[1]/b[1];
	//cout<<"________________________"<<endl;
	//cout<<"g[i]=(d[i]-a[i-1]*g[i-1])/(b[i]-a[i-1]*w[i-1])"<<endl;
	//cout<<"g1=d1/b1="<<g[1]<<endl;
	for(i=2;i<=n;i++)       //Ad=g   get g[1...n]
	{
		g[i]=(d[i]-a[i-1]*g[i-1])/(b[i]-a[i-1]*w[i-1]);
		//cout<<"g"<<i<<"=( "<<d[i]<<"-"<<a[i-1]<<"*"<<g[i-1];
		//cout<<")/("<<b[i]<<"-"<<a[i-1]<<"*"<<w[i-1]<<"="<<g[i]<<endl;
	
	}


	x[n]=g[n];
	cout<<"________________________"<<endl;
	cout<<"x[i]=g[i]-w[i]*x[i+1]"<<endl;
	cout<<"x"<<n<<"=g"<<n<<"="<<x[n]<<endl;
	for(i=n-1;i>=1;i--)             //get x[1...n]
	{
		x[i]=g[i]-w[i]*x[i+1];
		//cout<<"x"<<i<<"="<<g[i]<<"-"<<w[i]<<"*"<<x[i+1]<<"="<<x[i]<<endl;
	
	}
	cout<<"________________________"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"x"<<i<<"="<<x[i]<<endl;
		u[i]=x[i];
	}


	getchar();
	getchar();

	return ;

	

}


