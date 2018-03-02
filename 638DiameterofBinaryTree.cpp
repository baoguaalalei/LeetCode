/*
*Given a binary tree, you need to compute the length of the diameter of the tree. 
*The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
*This path may or may not pass through the root.
//给定一个二叉树，求其最长直径。基本思路是深度搜索每一个节点，比较每个结点左右分支长度之和与最大值的大小。
//
**/
//计算方法如下：
#include <iostream>
#include <stdlib.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};
class Solution{
	int maxnum;
public:
	int diameterOfBinaryTree(TreeNode * root){
		maxnum = 0;
		dfs(root);
//		cout<<maxnum;
		return maxnum;

	}
	 int dfs(TreeNode * root){
		 int left;
		 int right;
		 if (root == NULL) return 0;
		 else
		 {
			 left = dfs(root->left);
			 right = dfs(root->right);
		 }
		 int res = max(right,left)+1;
		 maxnum = max(maxnum,right+left);
		 return res;
	 }
};
int main(){
	Solution solute;
	TreeNode *node1 = new TreeNode(1);
	node1->right = new TreeNode(3);
	node1->left = new TreeNode(2);
	node1->left->left = new TreeNode(4);
	node1->left->right = new TreeNode(5);
	solute.find(node1);
}

