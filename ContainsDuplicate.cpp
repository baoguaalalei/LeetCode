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
		if (i > k) s.erase(nums[i-k-1]);//�൱����Kֵ��С�Ĵ���Ϊ���ƽ������ݵ�Ѱ�ң���������ʱ�򲻶Ͻ������ݵ�������
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