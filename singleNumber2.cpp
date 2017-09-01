class Solution {
public:
	int singleNumber(int A[], int n) 
	{
		int res=0;
		int data[32]={0};
		for(int i=0;i<32;i++)
		{
			for(int j=0;j<n;j++ )
			{
				data[i]+=(A[j]>>i)&1;  //该处应该是和一位数据相加    
			} 
			res |= data[i]%3<<i;
		} 
		return res;      
	}
};
/*int main()
{
	Solution a;
	int num[]={2,2,3,2};
	int res;
	res=a.singleNumber(num,4);
return 0;
}*/