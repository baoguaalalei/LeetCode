#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;
class  Solution{
public:
	int rob(vector<int>&nums){
		int n =nums.size();
		int a = 0;//存放偶数
		int b = 0;//存放奇数
		for (int i=0;i<n;i++)
		{
			if (i%2==0)
			{
				a = max(a+nums[i],b);
			}
			else
			{
				int o = nums[i];
				b = max(a,b+nums[i]);
			}
		}
		return max(a,b);
	}
};
/*
void main(){
	vector<int>nums;
	int ret;
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(2);
	nums.push_back(7);
	Solution solute;
	ret=solute.rob(nums);
	return;
} */                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               