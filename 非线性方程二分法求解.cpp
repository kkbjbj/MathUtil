#include<iostream>
#include<math.h>
using namespace std;


float f(float x)
{
	float y;
	y=x*x-9;
	return y;
}

void dev2(float a,float b,float e,float x,float y)
{
	
	
		cout<<"a="<<a<<"   b="<<b<<endl;
		x=(a+b)/2;
		cout<<"X="<<x<<endl;
		y=f(x);
		cout<<"f((a+b)/2))="<<y<<endl;
		if(y==0) { cout<<"X=="<<x<<endl; a=b;}
		if(y>0)  b=x;
		if(y<0)  a=x;
		if((a-b)>e||(a-b)<-1*e) dev2(a,b,e,x,y);
		
}

int main()
{
	
	float a,b,e,x,y,X;
	cout<<"put a,b ,e:"<<endl;
	cin>>a>>b>>e;
	if(f(a)*f(b)>0)
	{
	cout<<"change a,b"<<endl;
	cout<<"put a,b :"<<endl;
	cin>>a>>b;
	}
	else
	{
		if(f(a)>0)
		{
			float t;
			t=a; a=b; b=t;
		}
	}
	x=(a+b)/2;
	y=f(x);

	dev2(a,b,e,x,y);
	//cout<<"X="<<x<<endl;

	return 0;
}

	
