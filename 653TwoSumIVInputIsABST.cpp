/*
653. Two Sum IV - Input is a BST
Given a Binary Search Tree and a target number, return true if there 
exist two elements in the BST such that their sum is equal to the given target.
判定二叉树里面是否有两个数据的和与指定的值相等,相等的话返回true,否则返回false.采用BFS广度搜索的 in-order 遍历
*/
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) :val(x),left(NULL),right(NULL){}
};

class Solution
{
public:
	bool findTarget(TreeNode* root, int k)
	{
		vector<int> nums;
		stack<TreeNode*> nodes;	   
		DFS(root,nums);

		int left = 0, right = nums.size() - 1;
		while (left < right) 
		{
			int sum = nums[left] + nums[right];
			if (sum == k)
				return true;
			else if (sum < k)
				++left;
			else
				--right;
		}
		return false;
	}
	int DFS(TreeNode*root,vector<int>&nums){
		if (root==NULL) return NULL;
		else 
		{
			DFS(root->left,nums);
			nums.push_back(root->val);
			DFS(root->right,nums);
		}
		return 0;
	}
};