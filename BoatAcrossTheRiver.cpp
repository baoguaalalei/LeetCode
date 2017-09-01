//有一艘船能乘坐两个人，船的运行速度为两个人中速度较慢的一个人的速度，过去以后还需要一个人将船划回来，将n个人运到对岸最少需要多久
//需要考虑将最慢的两个人运过去
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
		//都是先将最慢的和次慢的送过去
		//最快和次快的过河，最快的将船划回来，次慢和最慢的过河，次快的将船划回来，需要的时间为t[0]+2*t[1]+t[n-1]
		//最快和最慢的过河，最快的将船划回来，最快和次慢的过河，最快的将船划过来，需要的时间为2*t[0]+t[n-1]+t[n-2]
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


