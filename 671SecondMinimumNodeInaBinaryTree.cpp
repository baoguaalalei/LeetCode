#include<iostream>
#include <stdlib.h>
using namespace std;
/************************************************************************/
/* Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.
Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
If no such second minimum value exists, output -1 instead.
找出二叉树中第二个最小值
思路：左右两端各找一个最小值，比较最小值的大小，较小值即为所求
*/
/************************************************************************/
struct TreeNode {
	    int val;
	    TreeNode *left;
	    TreeNode *right;
	    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	int findSecondMinimumValue(TreeNode *root){
		if (!root) return -1;		
		int find = findResult(root,root->val);
		return find;	
	}
	int findResult(TreeNode *root,int first)
	{
		if (root==NULL) return -1;
		int left = (root->val != first) ? root->val:findResult(root->left,first);
		int right = (root->val != first) ? root->val:findResult(root->right,first);
		if (left == -1) return right;
		if (right == -1) return left;
		return min(left,right);		
    }
};