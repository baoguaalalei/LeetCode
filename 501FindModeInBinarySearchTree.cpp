#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>

using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
}; 

class Solution
{
public:
	vector<int> findMode(TreeNode* root)
	{
		vector<int>data;
		unordered_map<int,int>m;
		int mx  = 0;
		inorder(root,mx,m);
		for (auto a:m)
		{
			if (a.second == mx)
			{
				data.push_back(a.first);
			}
		}
		return data;
	}

	void inorder(TreeNode * node,int &mx,unordered_map<int,int>&m)
	{
		if (node==NULL) return;

		inorder(node->left,mx,m);
		mx = max(mx,++m[node->val]);
		inorder(node->right,mx,m);
		return;
	}
	
};

























