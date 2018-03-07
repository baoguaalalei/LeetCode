/************************************************************************/
/* Given a binary tree and a sum, 
*  determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
*  For example:
*  Given the below binary tree and sum = 22,                            */
/************************************************************************/
#include <iostream>
#include<stdlib.h>
#include <queue>
using namespace std;
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

 class Solution{
 bool ret;
 int sumAll;
 public:
	 bool hasPathSum(TreeNode *root,int sum){
		 if (root==NULL) return false;
		 ret = false;
		 sumAll = sum;
		 int calSum = 0;
		 search(root,calSum);
		 return ret;
	 }
	 void search(TreeNode*node,int calSum){		 
		 if (node==NULL) 
		 {		 
			 return;
		 }	
		 calSum += node->val;
		 if (node->left==NULL&&node->right == NULL)
		 {
			 if (calSum == sumAll) ret = true;
			 return;
		 }
		 search(node->left,calSum);
		 search(node->right,calSum);		 
		
	 }	 
 };