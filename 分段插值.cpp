#include <iostream>
using namespace std;

int get_chashan(int,float *,float *);
int main()
{
	int i;
	int n;
	float x[20],y[20];
	char c;
	cout<<"|��������������������������$���������ڷֶβ�ֵ����$��������������������|"<<endl;
	cout<<endl;
	cout<<"��[2...n]=6�����ײ���"<<endl;
	cout<<"��i=hi/(hi-h[i-1])"<<endl;
	cout<<"hi=x[i+1]-x[i] i=1��ʼ"<<endl;
	cout<<endl;
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

int get_chashan(int n,float *x,float *y)   //���̼���
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
	printf("--------------------�¼��������£�----------------------\n");
	for(i=0;i<=n;i++)
		h[i]=x[i+1]-x[i];
	for(i=0;i<n;i++)
		printf("h%d=%f\n",i,h[i]);
	for(i=1;i<=n-1;i++)
		a[i]=h[i]/(h[i]+h[i-1]);
	for(i=1;i<=n-1;i++)
		printf("��%d=%f\n",i,a[i]);




	return 0;	
}






