#include<iostream>
using namespace std;
const int N = 4;
void knapsack(float M,float v[],float w[],float x[]);
/*int main()
{
	int M=50;//��������
	float w[] = {0,10,30,20,5};//ÿ����Ʒ������
	float v[] = {0,400,200,100,10};//ÿ����Ʒ�ļ�ֵ
	float x[N+1] = {0};//��¼���������
	knapsack(M,v,w,x);
	cout<<"ѡ��װ�µ���Ʒ������"<<endl;
	for (int i = 1;i<=N;i++)
	{
		cout<<"["<<i<<"]:"<<x[i]<<endl;
	}
}*/
void knapsack(float M,float v[],float w[],float x[])
{
	for (int i=1;i<=4;i++)
	{
		if (M<=0) break;
		//����װ��
		if (M-w[i]>0)
		{
			x[i]=1;
			M-=w[i];
		}
		else
		{
			x[i]=M/w[i];
			M=0;
		}		
	}
}











