#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;


int lglr(); //拉格朗日插值
int fdcz();  //分段插值
int szjf();  //数值积分
int zxex();  //最小二乘法
int xxfc();  //线性方程组直接解法
int sdjx_zg();  //追赶法解三对角线方程组
int sdjx_LUfj();  //LU分解方程组
int xxdd();      //线性迭代解方程组




void show_manue()
{
	cout<<"请从以下菜单选择操作:"<<endl;
	cout<<"_____________________________________________"<<endl;
	cout<<"0:退出程序"<<endl;
	cout<<"21:拉格朗日插值"<<"\n22:分段插值"<<endl;
	cout<<"23:数值积分"<<"\n24:最小二乘法"<<endl;
	cout<<"31:线性方程组直接解法"<<"\n32:追赶法解三对角线方程组"<<endl;
	cout<<"33:LU分解方程组"<<endl;
	cout<<"34:迭代解线性方程组"<<endl;
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

				default :cout<<"无此项菜单!"<<endl; break;
			}

			show_manue();
			cin>>manue;
		}


	return 0;
}


//++++++++++++++++++++++拉格朗日插值+++++++++++++++++++++
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
		cout<<"第"<<i+1<<"项="<<a*y[i]/(b*(X-x[i]))<<endl;
	}

	return (Y);
}

void help_lglr()
{
	cout<<endl;
	cout<<"Y=L(X)= {i=0->n} yi*Wn+1(xi)/((X-xi)*W'n+1(xi)) 共n+1项"<<endl;
	cout<<"Wn+1=(X-x0)*....*(X-xn) X为插值点"<<endl;
	cout<<"W'n+1(xi)=(xi-x0)*....*(xi-xn)  但不含(xi-xi)"<<endl;
	cout<<endl;
}

int lglr()
{
	int i;
	int n=0;
	char again;
	float x[20],y[20],X,Y;
	
lb: cout<<"|—————————————$本程序用于拉格良朗日插值计算$——————————|"<<endl;
	help_lglr();
	cout<<"输入插值次数(小于20):"<<endl;
	cin>>n;
	for(i=0;i<=n;i++)
	{
		cout<<"输入x"<<i<<endl;
		cin>>x[i];
	}
	for(i=0;i<=n;i++)
	{
		cout<<"输入y"<<i<<endl;
		cin>>y[i];
	}
	cout<<"输入待求变量X:"<<endl;
	cin>>X;
	Y=L_insert(n,x,y,X);
	cout<<endl;
	cout<<"待求值Y="<<Y<<endl;
	cout<<"|—|—|—|——————————$本次计算结束$———————|—|—|—|"<<endl;
	cout<<"是否继续计算Y/N?"<<endl;
	cin>>again;
	if(again=='Y'||again=='y')   goto lb;

	return 0;

}

//++++++++++++++++++++++分段插值+++++++++++++++++++++++

int get_chashan(int n,float *x,float *y)   //差商及β、α计算
{
	int i,j;
	float f[21][21],p[21],a[21],h[21];
		for(i=1;i<=n+1;i++)
			for(j=1;j<=n+1;j++)
				f[i][j]=0;

	printf("-----------------------差商计算结果如下：------------------\n");
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
	printf("--------------------β计算结果如下：----------------------\n");
	for(i=2;i<=n;i++)
		p[i]=6*f[2][i];
	for(i=2;i<=n;i++)
		printf("β%d=%f\n",i,p[i]);
	printf("--------------------α计算结果如下：----------------------\n");
	for(i=0;i<n;i++)
		h[i]=x[i+1]-x[i];
	for(i=0;i<n;i++)
		printf("h%d=%f\n",i,h[i]);
	for(i=1;i<=n-1;i++)
		a[i]=h[i]/(h[i]+h[i-1]);
	for(i=1;i<=n-1;i++)
		printf("α%d=%f\n",i,a[i]);




	return 0;	
}

void help_fdcz()
{
	cout<<endl;
	cout<<"β[2...n]=6倍二阶差商"<<endl;
	cout<<"αi=hi/(hi-h[i-1]) i=1开始"<<endl;
	cout<<"hi=x[i+1]-x[i] "<<endl;
	cout<<endl;
}

int fdcz()
{
	cout<<"|—————————————$本程序用于分段插值计算$——————————|"<<endl;
	help_fdcz();
	int i;
	int n;
	float x[20],y[20];
	char c;

	cout<<"输入用到的数据组数(小于20组):"<<endl;
	cin>>n;
	n=n-1;
	for(i=0;i<=n;i++)
	{
		cout<<"输入x"<<i<<endl;
		cin>>x[i];
	}
	for(i=0;i<=n;i++)
	{
		cout<<"输入y"<<i<<endl;
		cin>>y[i];
	}
	
	get_chashan(n,x,y);
	cout<<"|—|—|—|——————————$本次计算结束$———————|—|—|—|"<<endl;
	getchar();
	getchar();
	return 0;
}

//++++++++++++++++++++++++数值积分计算+++++++++++++++++++++++++++++++

int select_way(int n,int node);
int get_y(int n,float a,float b,float *x ,float *y);  //计算XY的值
float N_C_1(int n,float a,float b,float *y,float Cotes[][9]);  //等距节点求积公式
float N_C_2(int n,int node,float *x,float *y,float Cotes[][9]);   //复化求积公式

void help_szjf()
{
	cout<<endl;
	cout<<"T=(b-a)/2 *(y1+y2)  一阶"<<endl;
	cout<<"s=(b-a)/6 *(y1+4*y2+y3)   二阶"<<endl;
	cout<<endl;
}
int szjf()
{
	cout<<"|—————————————$本程序用于数值积分计算$——————————|"<<endl;
	help_szjf();

	int n,node,flag; //n阶数,node节点数,flag方法选择
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
		

	cout<<"输入节点数node,积分阶数n,下限a,上限b (用空格分开):"<<endl;
	cin>>node>>n>>a>>b;
	
	get_y(node,a,b,x,y);

	flag=select_way(n,node);
	if(flag==0)
		S=N_C_1(n,a,b,y,Cotes);
	if(flag==1)
		S=N_C_2(n,node,x,y,Cotes);
	cout<<"积分结果S="<<S<<endl;
	cout<<"|—|—|—|——————————$本次计算结束$———————|—|—|—|"<<endl;
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



int get_y(int node,float a,float b,float *x ,float *y)  //计算XY的值
{
	int i;
	char c;
	cout<<"输入x,y的值?(Y/N)"<<endl;
	cin>>c;
	if(c=='Y'||c=='y')
	{
		for(i=0;i<node;i++)
		{	
			cout<<"输入x"<<i<<"y"<<i<<"(用空格分开)"<<endl;
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



 float N_C_1(int n,float a,float b,float *y,float Cotes[][9])  //等距节点求积公式
 {
	 int i;
	 float S=0,t;
	 t=0;
	 for(i=0;i<=n;i++)
	   	t=t+(Cotes[n][i])*y[i]; 
	 S=t*(b-a)/Cotes[n][n+1];

	 return(S);

 }
 float N_C_2(int n,int node,float *x,float *y,float Cotes[][9])   //复化求积公式 
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

 //+++++++++++++++++++++++++最小二乘法a,b计算++++++++++++++++++++++++++++++

 void help_zxex()
{
	cout<<endl;
	cout<<"b=( {i=1..n} (xi-X)*(yi-Y))/( {i=1..n} (xi-X)^2 )"<<endl;
	cout<<"a=Y-bX  X,Y为平均值"<<endl;
	cout<<endl;
}

 int zxex()
{
	cout<<"|————————————$本程序用于最小二乘法a,b计算$——————————|"<<endl;
	help_zxex();
	int i,n;
	float t1,t2,a,b,x[30],y[30],X,Y;
	t1=0;
	t2=0;
	X=0;
	Y=0;

	cout<<"输入数据组数n:"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<" 输入x"<<i<<endl;
		cin>>x[i];
		cout<<" 输入y"<<i<<endl;
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

 //++++++++++++++++++++++++++线性方程组直接解法++++++++++++++++++++++++++++++

 void show(float a[][21],float b[],int n);

int xxfc()
{
	cout<<"|————————$本程序用于线性方程组直接解法矩阵变换$————————|"<<endl;
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
	
	cout<<"输入方程个数n:"<<endl;
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

	
	
	for(i=1;i<=n-1;i++)            //消元过程
	{
		cout<<"===========本次变换结果==============="<<endl;
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
	
	x[n]=b[n]/a[n][n];         //回代过程
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

	cout<<"|—|—|—|——————————$本次计算结束$———————|—|—|—|"<<endl;
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

//+++++++++++++++++++++++++++追赶法解三对角线方程组+++++++++++++++++++++++++++

void help_sdjx_zg()
{
	cout<<endl;
	cout<<"a[],b[],c[]为系数阵从左至右三斜线"<<endl;
	cout<<"d[]为方程右边,变换结果a[]全0,b[]全1,c[]变w[],d[]变g[]"<<endl;
	cout<<"{i=1..n-1} wi=ci/(bi-a[i-1]*w[i-1])"<<endl;
	cout<<"{i=1..n} gi=(di-a[i-1]*g[i-1])/(bi-a[i-1]*w[i-1])"<<endl;
	cout<<endl;
}

int sdjx_zg()
{
	cout<<"||=============本程序用于追赶法解三对角线方程组================||"<<endl;
	help_sdjx_zg();

	int i,j,k,l,n;
	float a[31],b[31],c[31],d[31],x[31],w[31],g[31];
	for(i=0;i<31;i++)
	{
		a[i]=b[i]=c[i]=w[i]=x[i]=0;

	}
	cout<<"输入方程个数n:"<<endl;
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

	cout<<"|—|—|—|——————————$本次计算结束$———————|—|—|—|"<<endl;
	getchar();
	getchar();
	return 0;

}

//+++++++++++++++++++++++LU分解三对角线方程组+++++++++++++++++++++++++++++++

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
	cout<<"||=============本程序用于LU分解线方程组================||"<<endl;
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
	
	cout<<"输入方程个数n:"<<endl;
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
	cout<<"|—|—|—|——————————$本次计算结束$———————|—|—|—|"<<endl;
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

//+++++++++++++++++++++++迭代分解方程组+++++++++++++++++++++++++++++++

int xxdd()
{
	int i,j,k,n,flag=0,count=1;
	float a[21][21],b[21],x[21],X[21],t[21],w,temp=0;

	cout<<"|————————$本程序用于线性方程组迭代解法$————————|"<<endl;
	cout<<"雅可比  Xi=(bi-{j=1:n &!=i}aij*xi)/aii"<<endl;
	cout<<"G-S     Xi=(bi-{j=1:i-1 }aij*Xi-{j=i+1:n }aij*xi)/aii"<<endl;
	cout<<"SOR　　Xi=xi+w*(bi-{j=1:i-1 }aij*Xi-{j=i:n }aij*xi)/aii"<<endl;
	cout<<"或SOR　　Xi=(1-w)*xi+w*G-S"<<endl;

	i=j=k=n=0;
	for(i=0;i<21;i++)
	{
		b[i]=0;
		x[i]=0;
		for(j=0;j<21;j++)
			a[i][j]=1;
			
	}

	cout<<"输入未知数个数："<<endl;
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
cout<<"____________雅可比迭代解法____________"<<endl;	
lab1: flag=0;
         if(count>100)
         {
         	cout<<"雅可比迭代发散"<<endl;
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

cout<<"____________G-S迭代解法____________"<<endl;
for(i=1;i<=n;i++)
	{
	x[i]=t[i];
	}
count=1;
lab11: flag=0;	
cout<<count++<<"   ";
if(count>100)
{
	cout<<"G-S迭代发散"<<endl;
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

cout<<"____________SOR迭代解法____________"<<endl;

		cout<<"输入松弛因子w"<<endl;
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
	cout<<"SOR迭代发散"<<endl;
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