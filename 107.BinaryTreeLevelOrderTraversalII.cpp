/*
*107. Binary Tree Level Order Traversal II
* Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
* (ie, from left to right, level by level from leaf to root).
//���ù�����ȱ����ķ�����ʹ�ö��н�ÿһ������ݱ���ĵ�vector�У��ٽ��з�ת������������
//�������в������
*/
#include<iostream>
#include<stdlib.h>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

class Solution{
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root){
		queue<TreeNode*>list;
		list.push(root);
		vector<vector<int>>res;
		vector<int>res1;
		if (root==NULL)
		{
			return res ;
		}
		while (!list.empty())
		{
			int size = list.size();
			for (int i = 0;i < size;i++)
			{
				TreeNode* data = list.front();
				list.pop();				
				res1.push_back(data->val);
					
				if (data->left) list.push(data->left);
				if (data->right) list.push(data->right);
			}
			res.push_back(res1);
			res1.clear();
		}
		reverse(res.begin(),res.end());
		return res;
	}
};