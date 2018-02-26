#include <iostream>
using namespace std;

int get_chashan(int,float *,float *);
int main()
{
	int i;
	int n;
	float x[20],y[20];
	char c;
	cout<<"|—————————————$本程序用于分段插值计算$——————————|"<<endl;
	cout<<endl;
	cout<<"β[2...n]=6倍二阶差商"<<endl;
	cout<<"αi=hi/(hi-h[i-1])"<<endl;
	cout<<"hi=x[i+1]-x[i] i=1开始"<<endl;
	cout<<endl;
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

int get_chashan(int n,float *x,float *y)   //差商计算
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
	printf("--------------------β计算结果如下：----------------------\n");
	for(i=0;i<=n;i++)
		h[i]=x[i+1]-x[i];
	for(i=0;i<n;i++)
		printf("h%d=%f\n",i,h[i]);
	for(i=1;i<=n-1;i++)
		a[i]=h[i]/(h[i]+h[i-1]);
	for(i=1;i<=n-1;i++)
		printf("α%d=%f\n",i,a[i]);




	return 0;	
}






