#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;


int lglr(); //�������ղ�ֵ
int fdcz();  //�ֶβ�ֵ
int szjf();  //��ֵ����
int zxex();  //��С���˷�
int xxfc();  //���Է�����ֱ�ӽⷨ
int sdjx_zg();  //׷�Ϸ������Խ��߷�����
int sdjx_LUfj();  //LU�ֽⷽ����
int xxdd();      //���Ե����ⷽ����




void show_manue()
{
	cout<<"������²˵�ѡ�����:"<<endl;
	cout<<"_____________________________________________"<<endl;
	cout<<"0:�˳�����"<<endl;
	cout<<"21:�������ղ�ֵ"<<"\n22:�ֶβ�ֵ"<<endl;
	cout<<"23:��ֵ����"<<"\n24:��С���˷�"<<endl;
	cout<<"31:���Է�����ֱ�ӽⷨ"<<"\n32:׷�Ϸ������Խ��߷�����"<<endl;
	cout<<"33:LU�ֽⷽ����"<<endl;
	cout<<"34:���������Է�����"<<endl;
	cout<<"_____________________________________________"<<endl;

}


int main()
{
	int manue;

	show_manue();
	cin>>manue;
	while(manue!=0)
		{
			switch(manue)
			{
				case 21: lglr();    break;
				case 22: fdcz();    break;
				case 23: szjf();    break;
				case 24: zxex();    break;
				case 31: xxfc();    break;
				case 32: sdjx_zg(); break;
				case 33: sdjx_LUfj(); break;
				case 34: xxdd();    break;

				default :cout<<"�޴���˵�!"<<endl; break;
			}

			show_manue();
			cin>>manue;
		}


	return 0;
}


//++++++++++++++++++++++�������ղ�ֵ+++++++++++++++++++++
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
			if(k!=i)  b=b*(x[i]-x[k]);
		}
		Y=Y+a*y[i]/(b*(X-x[i]));
		cout<<"��"<<i+1<<"��="<<a*y[i]/(b*(X-x[i]))<<endl;
	}

	return (Y);
}

void help_lglr()
{
	cout<<endl;
	cout<<"Y=L(X)= {i=0->n} yi*Wn+1(xi)/((X-xi)*W'n+1(xi)) ��n+1��"<<endl;
	cout<<"Wn+1=(X-x0)*....*(X-xn) XΪ��ֵ��"<<endl;
	cout<<"W'n+1(xi)=(xi-x0)*....*(xi-xn)  ������(xi-xi)"<<endl;
	cout<<endl;
}

int lglr()
{
	int i;
	int n=0;
	char again;
	float x[20],y[20],X,Y;
	
lb: cout<<"|��������������������������$�������������������ղ�ֵ����$��������������������|"<<endl;
	help_lglr();
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
	cout<<endl;
	cout<<"����ֵY="<<Y<<endl;
	cout<<"|��|��|��|��������������������$���μ������$��������������|��|��|��|"<<endl;
	cout<<"�Ƿ��������Y/N?"<<endl;
	cin>>again;
	if(again=='Y'||again=='y')   goto lb;

	return 0;

}

//++++++++++++++++++++++�ֶβ�ֵ+++++++++++++++++++++++

int get_chashan(int n,float *x,float *y)   //���̼��¡�������
{
	int i,j;
	float f[21][21],p[21],a[21],h[21];
		for(i=1;i<=n+1;i++)
			for(j=1;j<=n+1;j++)
				f[i][j]=0;

	printf("-----------------------���̼��������£�------------------\n");
	for(j=0;j<=n+1;j++)
		f[0][j]=y[j];
	for(i=1;i<=n+1;i++)
		for(j=i;j<=n+1;j++)
			f[i][j]=(f[i-1][j]-f[i-1][j-1])/(x[j]-x[j-i]);
	for(i=1;i<=n;i++)
	{	for(j=1;j<=i;j++)
		{
		
			printf("%f  ",f[j][i]);
		}
	printf("\n");
	} 
	printf("--------------------�¼��������£�----------------------\n");
	for(i=2;i<=n;i++)
		p[i]=6*f[2][i];
	for(i=2;i<=n;i++)
		printf("��%d=%f\n",i,p[i]);
	printf("--------------------�����������£�----------------------\n");
	for(i=0;i<n;i++)
		h[i]=x[i+1]-x[i];
	for(i=0;i<n;i++)
		printf("h%d=%f\n",i,h[i]);
	for(i=1;i<=n-1;i++)
		a[i]=h[i]/(h[i]+h[i-1]);
	for(i=1;i<=n-1;i++)
		printf("��%d=%f\n",i,a[i]);




	return 0;	
}

void help_fdcz()
{
	cout<<endl;
	cout<<"��[2...n]=6�����ײ���"<<endl;
	cout<<"��i=hi/(hi-h[i-1]) i=1��ʼ"<<endl;
	cout<<"hi=x[i+1]-x[i] "<<endl;
	cout<<endl;
}

int fdcz()
{
	cout<<"|��������������������������$���������ڷֶβ�ֵ����$��������������������|"<<endl;
	help_fdcz();
	int i;
	int n;
	float x[20],y[20];
	char c;

	cout<<"�����õ�����������(С��20��):"<<endl;
	cin>>n;
	n=n-1;
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
	
	get_chashan(n,x,y);
	cout<<"|��|��|��|��������������������$���μ������$��������������|��|��|��|"<<endl;
	getchar();
	getchar();
	return 0;
}

//++++++++++++++++++++++++��ֵ���ּ���+++++++++++++++++++++++++++++++

int select_way(int n,int node);
int get_y(int n,float a,float b,float *x ,float *y);  //����XY��ֵ
float N_C_1(int n,float a,float b,float *y,float Cotes[][9]);  //�Ⱦ�ڵ������ʽ
float N_C_2(int n,int node,float *x,float *y,float Cotes[][9]);   //���������ʽ

void help_szjf()
{
	cout<<endl;
	cout<<"T=(b-a)/2 *(y1+y2)  һ��"<<endl;
	cout<<"s=(b-a)/6 *(y1+4*y2+y3)   ����"<<endl;
	cout<<endl;
}
int szjf()
{
	cout<<"|��������������������������$������������ֵ���ּ���$��������������������|"<<endl;
	help_szjf();

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
		

	cout<<"����ڵ���node,���ֽ���n,����a,����b (�ÿո�ֿ�):"<<endl;
	cin>>node>>n>>a>>b;
	
	get_y(node,a,b,x,y);

	flag=select_way(n,node);
	if(flag==0)
		S=N_C_1(n,a,b,y,Cotes);
	if(flag==1)
		S=N_C_2(n,node,x,y,Cotes);
	cout<<"���ֽ��S="<<S<<endl;
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

 //+++++++++++++++++++++++++��С���˷�a,b����++++++++++++++++++++++++++++++

 void help_zxex()
{
	cout<<endl;
	cout<<"b=( {i=1..n} (xi-X)*(yi-Y))/( {i=1..n} (xi-X)^2 )"<<endl;
	cout<<"a=Y-bX  X,YΪƽ��ֵ"<<endl;
	cout<<endl;
}

 int zxex()
{
	cout<<"|������������������������$������������С���˷�a,b����$��������������������|"<<endl;
	help_zxex();
	int i,n;
	float t1,t2,a,b,x[30],y[30],X,Y;
	t1=0;
	t2=0;
	X=0;
	Y=0;

	cout<<"������������n:"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<" ����x"<<i<<endl;
		cin>>x[i];
		cout<<" ����y"<<i<<endl;
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

	cout<<"|��|��|��|��������������������$���μ������$��������������|��|��|��|"<<endl;
	getchar();
	getchar();

	return 0;
}

 //++++++++++++++++++++++++++���Է�����ֱ�ӽⷨ++++++++++++++++++++++++++++++

 void show(float a[][21],float b[],int n);

int xxfc()
{
	cout<<"|����������������$�������������Է�����ֱ�ӽⷨ����任$����������������|"<<endl;
	int i,j,k,n;
	float a[21][21],b[21],x[21],l[21][21],h[21],temp=0;

	i=j=k=n=0;
	for(i=0;i<21;i++)
	{
		b[i]=0;
		x[i]=0;
		for(j=0;j<21;j++)
			a[i][j]=1;
			l[i][j]=1;
	}
	
	cout<<"���뷽�̸���n:"<<endl;
	cin>>n;
	for(i=1;i<=n;i++)
	{	
		for(j=1;j<=n;j++)
		{
			cout<<"a"<<i<<j<<"=";
			cin>>a[i][j];
			
		}
	
	}
	for(i=1;i<=n;i++)
	{
		cout<<"b"<<i<<"=";
		cin>>b[i];
	}

	
	
	for(i=1;i<=n-1;i++)            //��Ԫ����
	{
		cout<<"===========���α任���==============="<<endl;
		for(j=i+1;j<=n;j++)
		{
			
			l[j][i]=a[j][i]/a[i][i];
			cout<<l[j][i]<<endl;
			b[j]=b[j]-b[i]*l[j][i];
			for(k=1;k<=n;k++)
			{
				a[j][k]=a[j][k]-a[i][k]*l[j][i];
				

			}
		}

		show(a,b,n);
	}
	
	x[n]=b[n]/a[n][n];         //�ش�����
	for(i=n-1;i>0;i--)
	{
		temp=0;
		for(j=i+1;j<=n;j++)
		{
			temp+=a[i][j]*x[j];
		}

		x[i]=(b[i]-temp)/a[i][i];
	}

	
	for(i=1;i<=n;i++)
	{
	
		cout<<"x"<<i<<"="<<x[i]<<endl;
		
	}

	cout<<"|��|��|��|��������������������$���μ������$��������������|��|��|��|"<<endl;
	return 0;
}

void show(float a[][21],float b[],int n)
{
	int i,j;
	
	for(i=1;i<=n;i++)
	{	for(j=1;j<=n;j++)
		{
		 cout<<a[i][j]<<"   ";
			
		}
	cout<<"			"<<b[i];
	cout<<endl;
	}

}

//+++++++++++++++++++++++++++׷�Ϸ������Խ��߷�����+++++++++++++++++++++++++++

void help_sdjx_zg()
{
	cout<<endl;
	cout<<"a[],b[],c[]Ϊϵ�������������б��"<<endl;
	cout<<"d[]Ϊ�����ұ�,�任���a[]ȫ0,b[]ȫ1,c[]��w[],d[]��g[]"<<endl;
	cout<<"{i=1..n-1} wi=ci/(bi-a[i-1]*w[i-1])"<<endl;
	cout<<"{i=1..n} gi=(di-a[i-1]*g[i-1])/(bi-a[i-1]*w[i-1])"<<endl;
	cout<<endl;
}

int sdjx_zg()
{
	cout<<"||=============����������׷�Ϸ������Խ��߷�����================||"<<endl;
	help_sdjx_zg();

	int i,j,k,l,n;
	float a[31],b[31],c[31],d[31],x[31],w[31],g[31];
	for(i=0;i<31;i++)
	{
		a[i]=b[i]=c[i]=w[i]=x[i]=0;

	}
	cout<<"���뷽�̸���n:"<<endl;
	cin>>n;
	for(i=1;i<=n;i++)
	{	
		cout<<"b"<<i<<"=";
		cin>>b[i];
	}
	for(i=1;i<=n-1;i++)
	{	
		cout<<"a"<<i<<"=";
		cin>>a[i];
	}
	for(i=1;i<=n-1;i++)
	{	
		cout<<"c"<<i<<"=";
		cin>>c[i];
	}
	for(i=1;i<=n;i++)
	{	
		cout<<"d"<<i<<"=";
		cin>>d[i];
		cout<<endl;
	}

	w[1]=c[1]/b[1];
	cout<<"________________________"<<endl;
	cout<<"w[i]=c[i]/(b[i]-a[i-1]*w[i-1])"<<endl;
	cout<<"w1=c1/b1="<<w[1]<<endl;
	for(i=2;i<=n-1;i++)        //change c[] to w[] to make a[1..n]=0 and b[1...n]=1 
	{
		w[i]=c[i]/(b[i]-a[i-1]*w[i-1]);
		cout<<"w"<<i<<"="<<c[i]<<" / (";
		cout<<b[i]<<"-"<<a[i-1]<<"*"<<w[i-1]<<" )="<<w[i]<<endl;


	}
	g[1]=d[1]/b[1];
	cout<<"________________________"<<endl;
	cout<<"g[i]=(d[i]-a[i-1]*g[i-1])/(b[i]-a[i-1]*w[i-1])"<<endl;
	cout<<"g1=d1/b1="<<g[1]<<endl;
	for(i=2;i<=n;i++)       //Ad=g   get g[1...n]
	{
		g[i]=(d[i]-a[i-1]*g[i-1])/(b[i]-a[i-1]*w[i-1]);
		cout<<"g"<<i<<"=( "<<d[i]<<"-"<<a[i-1]<<"*"<<g[i-1];
		cout<<")/("<<b[i]<<"-"<<a[i-1]<<"*"<<w[i-1]<<"="<<g[i]<<endl;
	
	}


	x[n]=g[n];
	cout<<"________________________"<<endl;
	cout<<"x[i]=g[i]-w[i]*x[i+1]"<<endl;
	cout<<"x"<<n<<"=g"<<n<<"="<<x[n]<<endl;
	for(i=n-1;i>=1;i--)             //get x[1...n]
	{
		x[i]=g[i]-w[i]*x[i+1];
		cout<<"x"<<i<<"="<<g[i]<<"-"<<w[i]<<"*"<<x[i+1]<<"="<<x[i]<<endl;
	
	}
	cout<<"________________________"<<endl;
	for(i=1;i<=n;i++)
		cout<<"x"<<i<<"="<<x[i]<<endl;

	cout<<"|��|��|��|��������������������$���μ������$��������������|��|��|��|"<<endl;
	getchar();
	getchar();
	return 0;

}

//+++++++++++++++++++++++LU�ֽ����Խ��߷�����+++++++++++++++++++++++++++++++

void showLU(float L[][21],float U[][21],int n);
void showxy(float x[],float y[],int n);

void help_sdjx_LUfj()
{
	cout<<endl;
	cout<<"{i=1..n,j=1..i} L[ij]=a[ij]-{for k=1..i-1}L[ik]*U[kj]"<<endl;
	cout<<"{i=1..n,j=i+1..n} U[i]=(a[ij]-{for k=1..i-1}L[ik]*U[kj])/L[ii]"<<endl;
	cout<<endl;
}

int sdjx_LUfj()
{
	cout<<"||=============����������LU�ֽ��߷�����================||"<<endl;
	help_sdjx_LUfj();

	int i,j,k,l,n;
	float a[21][21],b[21],L[21][21],U[21][21],x[21],y[21];
	float temp1,temp2;
	temp1=temp2=0;
	i=j=k=n=0;
	
	for(i=0;i<21;i++)
	{
		b[i]=0;
		x[i]=0;
		for(j=0;j<21;j++)
		{	a[i][j]=1;
			L[i][j]=U[i][j]=0;
		}
	}
	
	cout<<"���뷽�̸���n:"<<endl;
	cin>>n;
	for(i=1;i<=n;i++)
	{	
		x[i]=y[i]=0;
		for(j=1;j<=n;j++)
		{
			cout<<"a"<<i<<j<<"=";
			cin>>a[i][j];
			
		}
	
	}
	for(i=1;i<=n;i++)
	{
		cout<<"b"<<i<<"=";
		cin>>b[i];
	}

	for(i=1;i<=n;i++)          //A=LU     get L[left down]  U[right 1 up]
	{
		U[i][i]=1;
		for(j=1;j<=i;j++)
		{
			cout<<"L"<<i<<j<<"=";
			cout<<a[i][j]<<"- (";
			temp1=0;
			for(k=1;k<=i-1;k++)
			{
					temp1+=L[i][k]*U[k][j]; 
					cout<<L[i][k]<<"*"<<U[k][j]<<"+";  
					
			
			} 
			cout<<" )"<<endl;
			L[i][j]=a[i][j]-temp1;

		}
		for(l=i+1;l<=n;l++)
		{
			temp2=0;
			cout<<"U"<<i<<l<<"=";
			cout<<" {"<<a[i][l]<<"- (";
			for(k=1;k<=i-1;k++)
			{
					 
					temp2+=L[i][k]*U[k][l]; 
					cout<<L[i][k]<<"*"<<U[k][l]<<"+"; 
			
			} 
			cout<<" ) }/ "<<L[i][i]<<endl;
			U[i][l]=(a[i][l]-temp2)/L[i][i];

		}

	}
	showLU(L,U,n);

	for(i=1;i<=n;i++)    //LY=b  get y[1...n]
	{
		temp1=0;
		cout<<"y"<<i<<"=";
		cout<<b[i]<<"- (";
		for(k=1;k<=i-1;k++)
		{
			temp1+=L[i][k]*y[k];
			cout<<L[i][k]<<"*"<<y[k]<<"+";
		}
		cout<<" )/ "<<L[i][i]<<endl;
		y[i]=(b[i]-temp1)/L[i][i];
	}

	for(i=n;i>=1;i--)    //UX=Y   get x[1...n]
	{
		temp1=0;
		cout<<"x"<<i<<"=";
		cout<<y[i]<<"- (";
		for(k=i+1;k<=n;k++)
		{
			temp1+=U[i][k]*x[k];
			cout<<U[i][k]<<"*"<<x[k]<<"+";
		}

		cout<<" ) "<<endl;
		x[i]=y[i]-temp1;
	}
	
	
	showxy(x,y,n);
	cout<<"|��|��|��|��������������������$���μ������$��������������|��|��|��|"<<endl;
	getchar();
	getchar();
	return 0;


}

void showLU(float L[][21],float U[][21],int n)
{
	int i,j;
	cout<<"__________________________"<<endl;
	for(i=1;i<=n;i++)
	{	
		for(j=1;j<=n;j++)
		{
			cout<<L[i][j]<<"	";
			
			
		}
	cout<<endl;
	}
	cout<<"__________________________"<<endl;
	for(i=1;i<=n;i++)
	{	
		for(j=1;j<=n;j++)
		{
			cout<<U[i][j]<<"	";
			
			
		}
		cout<<endl;
	
	cout<<endl;
	}
	cout<<"__________________________"<<endl;

}

void showxy(float x[],float y[],int n)
{
	int i;
	cout<<"__________________________"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"y"<<i<<"=";
		cout<<y[i]<<endl;
	}
	cout<<"__________________________"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<"x"<<i<<"=";
		cout<<x[i]<<endl;
	}
	cout<<"__________________________"<<endl;

}

//+++++++++++++++++++++++�����ֽⷽ����+++++++++++++++++++++++++++++++

int xxdd()
{
	int i,j,k,n,flag=0,count=1;
	float a[21][21],b[21],x[21],X[21],t[21],w,temp=0;

	cout<<"|����������������$�������������Է���������ⷨ$����������������|"<<endl;
	cout<<"�ſɱ�  Xi=(bi-{j=1:n &!=i}aij*xi)/aii"<<endl;
	cout<<"G-S     Xi=(bi-{j=1:i-1 }aij*Xi-{j=i+1:n }aij*xi)/aii"<<endl;
	cout<<"SOR����Xi=xi+w*(bi-{j=1:i-1 }aij*Xi-{j=i:n }aij*xi)/aii"<<endl;
	cout<<"��SOR����Xi=(1-w)*xi+w*G-S"<<endl;

	i=j=k=n=0;
	for(i=0;i<21;i++)
	{
		b[i]=0;
		x[i]=0;
		for(j=0;j<21;j++)
			a[i][j]=1;
			
	}

	cout<<"����δ֪��������"<<endl;
	cin>>n;
	for(i=1;i<=n;i++)
	{	
		for(j=1;j<=n;j++)
		{
			cout<<"a"<<i<<j<<"=";
			cin>>a[i][j];
			
		}
	
	}
	for(i=1;i<=n;i++)
	{
		cout<<"b"<<i<<"=";
		cin>>b[i];
	}

	for(i=1;i<=n;i++)
	{
		cout<<"x"<<i<<"=";
		cin>>x[i];
		t[i]=x[i];
	}
cout<<"____________�ſɱȵ����ⷨ____________"<<endl;	
lab1: flag=0;
         if(count>100)
         {
         	cout<<"�ſɱȵ�����ɢ"<<endl;
         goto lab2;
         }
         cout<<count++<<"   ";
	  
	for(i=1;i<=n;i++)
	{
		temp=0;
		for(j=1;j<=n;j++)
			if(i!=j) temp+=a[i][j]*x[j];
			X[i]=(b[i]-temp)/a[i][i];
			cout<<"X"<<i<<"="<<X[i]<<"  ";
	
	}
	cout<<endl;
	for(i=1;i<=n;i++)
	{
		if(X[i]-x[i]!=0) 
		{ 
			flag=1;
			goto lab0;
		}
	}
lab0:	for(i=1;i<=n;i++)
	{
		x[i]=X[i];
		
	}
	if (flag==1)   goto lab1;
lab2:  cout<<endl;

cout<<"____________G-S�����ⷨ____________"<<endl;
for(i=1;i<=n;i++)
	{
	x[i]=t[i];
	}
count=1;
lab11: flag=0;	
cout<<count++<<"   ";
if(count>100)
{
	cout<<"G-S������ɢ"<<endl;
	goto lab21;
}

	for(i=1;i<=n;i++)
	{
		temp=0;
		for(j=1;j<i;j++)
			temp+=a[i][j]*X[j];
		for(j=i+1;j<=n;j++)
			temp+=a[i][j]*x[j];
		X[i]=(b[i]-temp)/a[i][i];
		cout<<"X"<<i<<"="<<X[i]<<"  ";
	
	}
	cout<<endl;
	for(i=1;i<=n;i++)
	{
		if(X[i]-x[i]!=0) 
		{ 
			flag=1;
			goto lab01;
		}
	}
lab01:	for(i=1;i<=n;i++)
	{
		x[i]=X[i];
	}
	if (flag==1)   goto lab11;
lab21:  cout<<endl;

cout<<"____________SOR�����ⷨ____________"<<endl;

		cout<<"�����ɳ�����w"<<endl;
		cin>>w;
		for(i=1;i<=n;i++)
	{
	x[i]=t[i];
	}
count=1;
lab12: flag=0;	
cout<<count++<<"   ";
if(count>100)
{
	cout<<"SOR������ɢ"<<endl;
	goto lab22;
}

	for(i=1;i<=n;i++)
	{
		temp=0;
		for(j=1;j<i;j++)
			temp+=a[i][j]*X[j];
		for(j=i;j<=n;j++)
			temp+=a[i][j]*x[j];
		X[i]=x[i]+w*(b[i]-temp)/a[i][i];
		cout<<"X"<<i<<"="<<X[i]<<"  ";
	
	}
	cout<<endl;
	for(i=1;i<=n;i++)
	{
		if(X[i]-x[i]!=0) 
		{ 
			flag=1;
			goto lab02;
		}
	}
lab02:	for(i=1;i<=n;i++)
	{
		x[i]=X[i];
	}
	if (flag==1)   goto lab12;
lab22:  cout<<endl;
		
	return 0;

}