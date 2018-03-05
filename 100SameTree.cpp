/************************************************************************/
/*100. Same Tree  
* Given two binary trees, write a function to check if they are the same or not.
* Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
最简单的方式
//if (p==NULL||q==NULL) return (p==q);
//return (p->val == q->val && isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
/************************************************************************/
#include <stdlib.h>
#include<iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
};

class Solution{
	bool isSameTree(TreeNode* p, TreeNode* q) {
		
		
		if (p==NULL&&q==NULL)
		{
			return true;
		}
		else if ((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL))
		{
			return false;
		}
		else
		{
			bool res_left;
			bool res_right;
			if (p->val==q->val)
			{
				res_left= isSameTree(p->left,q->left);
				res_right= isSameTree(p->right,q->right);
				if (res_left==true&&res_right==true)
				{
					return true;
				}
				else
				{
					return false;				
				}
			}
			else return false;			
		}
		
	}
};