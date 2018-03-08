/*
*Given a binary tree, return all root-to-leaf paths.
*For example, given the following binary tree:
*    1
   /   \
  2     3
   \
    5
*·µ»ØÖµÊÇ:
["1->2->5", "1->3"]
*/
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode*left;
	TreeNode*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
};

class Solution{
public:
	void binarySearch(TreeNode*node,vector<string>&res,string temp){
		if (node->left==NULL&&node->right==NULL)
		{
			res.push_back(temp);
			return;
		}
		if (node->left) binarySearch(node->left,res,temp+"->"+to_string(node->left->val));
		if (node->right) binarySearch(node->right,res,temp+"->"+to_string(node->right->val));	
		return;
	}
	vector<string>binaryTreePaths(TreeNode * root){	
		vector<string> res;
		if (root==NULL) return res;
		binarySearch(root,res,to_string(root->val));	
		return res;
	}
};
