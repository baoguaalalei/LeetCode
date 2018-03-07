/*
*111. Minimum Depth of Binary Tree
*求最小深度//采用深度搜索
*/
#include<stdlib.h>
#include<iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

class Solution{
int length;
public:int minDepth(TreeNode* root)
	   {
		   if (root==NULL)
		   {
			   return 0;
		   }
		   int length = 10000;
		   int curLength = 0;
		   search(root,curLength);
		   return length; 
	   }
	   void search(TreeNode*node,int curLength){
		   if (node == NULL) return;
		   
		   if (node->left == NULL&&node->right==NULL)
		   {
			   if (curLength+1<length)
			   {
				   length = curLength+1;
			   }
			   return;			    
		   }
		   search(node->left,curLength+1);
		   search(node->right,curLength+1);
	   }
};

int main(){
	Solution solute;
	TreeNode *node1 = new TreeNode(0);	
	solute.minDepth(node1);
	return 0;
}

