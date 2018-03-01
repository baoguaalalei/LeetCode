/*
653. Two Sum IV - Input is a BST
Given a Binary Search Tree and a target number, return true if there 
exist two elements in the BST such that their sum is equal to the given target.
�ж������������Ƿ����������ݵĺ���ָ����ֵ���,��ȵĻ�����true,���򷵻�false.����BFS��������� in-order ����
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