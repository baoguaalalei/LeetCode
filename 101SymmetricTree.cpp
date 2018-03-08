/*
*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
检查是不是镜像二叉树,可以采用在队列中做比较的方式，分别保存左边分支和右边分支的队列，再在队列里面分别对比值的大小。
*/
#include<stdlib.h>
#include<queue>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

class Solution{
public:
	bool isSymmetric(TreeNode*root){
		TreeNode *left,*right;
		if(root==NULL) return true;
		queue<TreeNode*> q1,q2;
		q1.push(root->left);
		q2.push(root->right);
		while(!q1.empty()&&!q2.empty())
		{
			left = q1.front();
			q1.pop();
			right = q2.front();
			q2.pop();
			if (left==NULL&&right==NULL) continue;
			if (left==NULL||right==NULL) return false;
			if (left->val != right->val) return false;
			q1.push(left->left);
			q1.push(right->left);
			q2.push(left->right);
			q2.push(right->right);			
		}
		return true;
	}
};