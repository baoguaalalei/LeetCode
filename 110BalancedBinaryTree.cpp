/*
*Given a binary tree, determine if it is height-balanced.
*For this problem, a height-balanced binary tree is defined as:
*a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//判断一个二叉树是否平衡，两边的纵深不超过1，可以采用队列形式容易出現考慮不周的情況，可以採用深度搜索。
*/
#include<iostream>
#include<queue>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

struct Solution{
	bool balance;

public:
	bool isBalanced(TreeNode* root)
	{ 
		balance = true;
		if (root == NULL) return true;
		dfs(root);
		return balance;
	}
	int dfs(TreeNode*node){
		if (node==NULL) return 0;
		int left = dfs(node->left);
		int right = dfs(node->right);
		if (abs(left-right)>1)
		{
			balance = false;
		}
		return max(left,right)+1;
	
	}
};

int main(){
	Solution solute;
	TreeNode *node1 = new TreeNode(1);
	node1->right = new TreeNode(2);
	node1->left = new TreeNode(2);
	node1->right->left = new TreeNode(3);
	node1->right->right = new TreeNode(3);
	node1->left->left = new TreeNode(3);
	node1->left->right = new TreeNode(3);
	bool  res = solute.isBalanced(node1);
	return 0;
}
