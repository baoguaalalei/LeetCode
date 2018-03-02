/************************************************************************/
/* Given a Binary Search Tree (BST), 
convert it to a Greater Tree such that every key of the original BST is changed 
to the original key plus sum of all keys greater than the original key in BST. 
*/
//采用的方法是将一个全局变量作为统计量，右序遍历
/************************************************************************/
#include<iostream>
#include<stdlib.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

class Solution{
int sum;
public:
	TreeNode* convertBST(TreeNode*root)
	{
		sum = 0;
		if (root==NULL) return NULL;
		searchData(root);
		return root;					
	}
	int searchData(TreeNode * root)
	{
		if (root==NULL) return NULL;
		if (root->right!= NULL)
		{
		   searchData(root->right);
		}
		root->val += sum;
		sum = root->val;
		if (root->left != NULL)
		{
			searchData(root->left);
		}

		return sum;
	}
};

/*
int main(){
	Solution solute;
	TreeNode *node1 = new TreeNode(5);
	node1->right = new TreeNode(13);
	node1->left = new TreeNode(2);
	solute.convertBST(node1);
}
*/