#include<iostream>
#include<stdlib.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
//采用中序遍历的形式进行求解，一旦有一个分支出现缺失，返回非缺失值的一方。
public:
	TreeNode * mergeTrees(TreeNode *t1,TreeNode *t2)
	{
		if (t1==NULL&&t2==NULL) return NULL;
		if (t1!=NULL&&t2!=NULL)
		{
			t1->val+=t2->val;
			t1->left=mergeTrees(t1->left,t2->left);
			t1->right=mergeTrees(t1->right,t2->right);
			return t1;
		}		
		else
		{
			if (t1==NULL)
			{
				return t2;
			}
			else return t1;					
		}
		
	}
};
