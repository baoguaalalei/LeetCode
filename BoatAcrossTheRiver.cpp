//��һ�Ҵ��ܳ��������ˣ����������ٶ�Ϊ���������ٶȽ�����һ���˵��ٶȣ���ȥ�Ժ���Ҫһ���˽�������������n�����˵��԰�������Ҫ���
//��Ҫ���ǽ��������������˹�ȥ
#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[1000],t,n,sum;
	printf("Input t:\n");
	scanf("%d",&t);
	while (t--)
	{
		printf("Input n:\n");
		scanf("%d",&n);
		sum = 0;
		printf("Input a:\n");
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		//�����Ƚ������ĺʹ������͹�ȥ
		//���ʹο�Ĺ��ӣ����Ľ����������������������Ĺ��ӣ��ο�Ľ�������������Ҫ��ʱ��Ϊt[0]+2*t[1]+t[n-1]
		//���������Ĺ��ӣ����Ľ��������������ʹ����Ĺ��ӣ����Ľ�������������Ҫ��ʱ��Ϊ2*t[0]+t[n-1]+t[n-2]
		while (n>3)
		{
			sum =min(sum+a[1]+a[0]+a[n-1]+a[1],sum+a[n-1]+a[0]+a[n-2]+a[0]);
			n-=2;
		}
		if (n==3) sum += a[0]+a[1]+a[2];
		else if (n==2) sum+=a[1];
		else sum +=a[0];
		printf("%d\n",sum);
	}
	return 0;
}


