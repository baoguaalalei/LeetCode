#include<iostream>
using namespace std;
const int N = 4;
void knapsack(float M,float v[],float w[],float x[]);
/*int main()
{
	int M=50;//背包容量
	float w[] = {0,10,30,20,5};//每种物品的重量
	float v[] = {0,400,200,100,10};//每种物品的价值
	float x[N+1] = {0};//记录结果的数组
	knapsack(M,v,w,x);
	cout<<"选择装下的物品比例："<<endl;
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
		//整个装入
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











