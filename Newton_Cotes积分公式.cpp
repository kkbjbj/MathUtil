#include <iostream>
#include <math.h>
using namespace std;

int select_way(int n,int node);
int get_y(int n,float a,float b,float *x ,float *y);  //����XY��ֵ
float N_C_1(int n,float a,float b,float *y,float Cotes[][9]);  //�Ⱦ�ڵ������ʽ
float N_C_2(int n,int node,float *x,float *y,float Cotes[][9]);   //���������ʽ

int main()
{
	int n,node,flag; //n����,node�ڵ���,flag����ѡ��
	int i,j;
	float a,b,S,x[30],y[30];
	float Cotes[9][9]={
		{0},
		{1,1,2},
		{1,4,1,6},
		{1,3,3,1,8},
		{7,32,12,32,7,90},
		{19,75,50,50,75,19,288},
		{41,216,27,272,27,216,41,840},
		{751,3577,1323,2989,2989,1323,3577,751,17280},
		{0}
	};
		
	cout<<"|��������������������������$������������ֵ���ּ���$��������������������|"<<endl;
	cout<<endl;
	cout<<"T=(b-a)/2 *(y1+y2)  һ��"<<endl;
	cout<<"s=(b-a)/6 *(y1+4*y2+y3)   ����"<<endl;
	cout<<endl;
	cout<<"����ڵ���node,���ֽ���n,����a,����b (�ÿո�ֿ�):"<<endl;
	cin>>node>>n>>a>>b;
	
	get_y(node,a,b,x,y);

	flag=select_way(n,node);
	if(flag==0)
		S=N_C_1(n,a,b,y,Cotes);
	if(flag==1)
		S=N_C_2(n,node,x,y,Cotes);
	cout<<"result="<<S<<endl;
	
	cout<<"|��|��|��|��������������������$���μ������$��������������|��|��|��|"<<endl;
	getchar();
	getchar();

	return 0;
}

int select_way(int n,int node)
{
	if(node==n+1) 
		return 0;
	else return 1;
	
}



int get_y(int node,float a,float b,float *x ,float *y)  //����XY��ֵ
{
	int i;
	char c;
	cout<<"����x,y��ֵ?(Y/N)"<<endl;
	cin>>c;
	if(c=='Y'||c=='y')
	{
		for(i=0;i<node;i++)
		{	
			cout<<"����x"<<i<<"y"<<i<<"(�ÿո�ֿ�)"<<endl;
			cin>>x[i]>>y[i];
		}

	}
	else
	{
		for(i=0;i<node;i++)
		{
			x[i]=a+i*(b-a)/(node-1);
			y[i]=pow(x[i],0.5);
			cout<<"x"<<1<<"="<<x[i]<<"y"<<i<<"="<<y[i]<<endl;
		
		}
	}
	return 0;
}



 float N_C_1(int n,float a,float b,float *y,float Cotes[][9])  //�Ⱦ�ڵ������ʽ
 {
	 int i;
	 float S=0,t;
	 t=0;
	 for(i=0;i<=n;i++)
	   	t=t+(Cotes[n][i])*y[i]; 
	 S=t*(b-a)/Cotes[n][n+1];

	 return(S);

 }
 float N_C_2(int n,int node,float *x,float *y,float Cotes[][9])   //���������ʽ 
 {
	 int i,j,m;
	 float tx[8],ty[8];
	 float S=0,ts[20];

	 m=(node-1)/n;
	 for(i=0;i<m;i++)
	 {	for(j=0;j<=n;j++)
		 { 
			 tx[j]=x[n*(i)+j];
			 
			 ty[j]=y[n*(i)+j];
			
		 }
	 ts[i]=N_C_1(n,tx[0],tx[n],ty,Cotes);
	 }
	 for(i=0;i<m;i++)
		 S=S+ts[i];
		  
	 
	 return(S); 
 } 

	


