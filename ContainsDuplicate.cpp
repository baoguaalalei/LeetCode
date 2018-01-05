#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_set<int> s;
	if (k <= 0) return false;
	if (k >= nums.size()) k = nums.size()-1;
	for (int i = 0;i < nums.size();i++)
	{
		if (i > k) s.erase(nums[i-k-1]);//相当于以K值大小的窗口为限制进行数据的寻找，当超出的时候不断进行数据的消减。
		if (s.find(nums[i]) != s.end()) return true;
		s.insert(nums[i]);
	}
	return false;
    }
}; 
/*
int main(){

	Solution* res = new Solution();
	vector <int> data;
	data.push_back(1);
	data.push_back(2);
	data.push_back(3);
	data.push_back(2);
	bool ret = res->containsNearbyDuplicate(data,3);
	return 0;
}
*/