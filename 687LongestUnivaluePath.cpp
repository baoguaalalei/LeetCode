/*
leetCode 687
Given a binary tree, find the length of the longest path where each node in the path has the same value. 
This path may or may not pass through the root.
��һ����������ÿ����������ֵͬ���·������·�����Դ������ڵ㣬Ҳ���Բ��������ڵ㡣
*/
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution{
public:
	int longestUnivaluePath(TreeNode* root)
	{
		if(root==NULL) return 0;
		int mLength = 0;
		findLength(root,mLength);
		return mLength;	
	}
	int findLength(TreeNode *root,int &mLength)
	{
		//����ÿ����������������˵����·���������������ˡ�
		int l = root->left ? findLength(root->left,mLength):0;
		int r = root->right ? findLength(root->right,mLength):0;
		l = (root->left && root->left->val==root->val) ? l+1:0;
		r = (root->right && root->right->val==root->val) ? r+1:0;
		mLength = max(mLength,l+r);
		return max(l,r);
	}
};
