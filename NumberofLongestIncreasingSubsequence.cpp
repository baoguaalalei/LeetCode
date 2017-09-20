#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
//寻找一个序列中的最长子序列的数量。

class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		int res;
		int n = nums.size();
		int len_n = 1;
	//equal[i]用于表示在该点位置最长子序列的数量
    //len[i]用于表示在该点之前最长子序列的长度
		vector<int> len(n,1),equal(n,1);
		for (int i=1;i<n;i++)
		{
			for (int j=0;j<i;j++)
			{
				if (nums[j]<nums[i])
				{
					if (len[j]+1>len[i])
					{
						len[i] = len[j]+1;
						equal[i] = equal[j];
					}
					else if (len[j]+1==len[i])
					{
						equal[i] += equal[j];												
					}
				}
			}
			len_n = max(len[i],len_n);
		}
		res = 0;
		for (int i=0;i<n;i++)
		{
			if (len_n==len[i])
			{ 
				res+=equal[i];
			}
		}
		return res;
	}
};

void main(){
	vector<int>num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(4);
	num.push_back(3);
	num.push_back(5);
	num.push_back(4);
	num.push_back(7);
	num.push_back(2);
	Solution solution;
int a =solution.findNumberOfLIS(num); 
printf("The result is %d\n",a);
return ;
}