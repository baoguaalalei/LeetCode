/*
Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). 
You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.
һ���������е������Ѿ����к���,����������ʱ�����Ҽ�֦���ɡ�
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution
{
public:TreeNode *trimBST(TreeNode *root,int L,int R)
	   { 
		   if (root == NULL) return NULL;
		   
		   if (root->val < L) 
		   {
			   return trimBST(root->right,L,R);
		   }else if (root->val > R)
		   {
			   return trimBST(root->left,L,R);
		   }
		   else
		   {
			   root->left = trimBST(root->left,L,R);
			   root->right = trimBST(root->right,L,R);
			   return root;
		   }
	   }
};
