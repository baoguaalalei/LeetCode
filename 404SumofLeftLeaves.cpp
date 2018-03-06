/************************************************************************/
/*Find the sum of all left leaves in a given binary tree.

Example:

3
/ \
9  20
/  \
15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
������Ҷ�ӽ��ĺͣ��������ÿһ����㣬��left����Ϊȫ�ֱ������ж�Ϊ��Ҷ����Ӻͼ��ɡ�                                                                   */
/************************************************************************/
#include <iostream>
#include<stdlib.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

class Solution{
int left;
public:
	int sumOfLeftLeaves(TreeNode* root) {
		left = 0;
		dfs(root);
		return left;
	}
	void dfs(TreeNode *node)
	{
		if (node==NULL)
		{
			return;
		}
		if (node->left!=NULL)
		{
			if (node->left->left!=NULL||node->left->right!=NULL)
			{
				dfs(node->left);
			}
			else
			{
				left += node->left->val;
							
			}			
		}
		if (node->right!=NULL)
		{
			dfs(node->right);
		}
		return;

	}
};