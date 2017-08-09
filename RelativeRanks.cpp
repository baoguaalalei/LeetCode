#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
//2017.08.09 xwh
//all the scores of atheltes are guaranteed to be **unique** 
class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums)
	{
		//放到一个排好顺序的队列里面
        priority_queue<int> Q;
		for(int num : nums)
			Q.push(num);
		int count = 0; 
		vector<string> ans(nums.size());
		int temp;
		while(Q.size() > 0)
		{
			count++;
			temp = Q.top();
			Q.pop();
			for(int i=0;i<nums.size();i++)
				if(nums[i] == temp)
				{
					if(count == 1)
						ans[i] = "Gold Medal";
					else if(count == 2)
						ans[i] = "Silver Medal";
					else if(count == 3)
						ans[i] = "Bronze Medal";
					else
						ans[i] = to_string(count);
					break;
				}
		}
		return ans;       
	}
};

int main()
{
	Solution a;
	vector<int>nums(5);
	for (int i=0;i<5;i++)
	{
		nums[i]=i;
	}	
	nums[0]=6;
	nums[1]=7;
	nums[2]=1;
	nums[3]=2;
	nums[4]=5;
	vector<string> res(5);
	res=a.findRelativeRanks(nums);
	for (vector<string>::iterator iter = res.begin();iter!=res.end();++iter)
	{
		cout<<*iter<<endl;			
	}
	return 0;
}