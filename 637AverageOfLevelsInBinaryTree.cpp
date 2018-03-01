/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
3
/ \
9  20
/  \
15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
优先想到的是二叉树的层序遍历，采用广度优先遍历的方式，广度优先遍历采用队列的形式进行数据的存储
*/
#include<iostream>
/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
      3
     / \
    9  20
  /  \
 15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
//二叉树的层序遍历，采用队列的形式
*/

#include<stdlib.h>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Solution
{
public:
	vector<double>averageOfLevels(TreeNode* root)
	{
		queue<TreeNode*> q;  //用于保存每一行的节点数据
		vector<double> res;  //用于保存每一层的计算结果
		q.push(root);
		double sum;
		while (!q.empty())
		{
			sum = 0;
			int num = q.size();
			for (int i = 0;i < num;i ++)
			{
				TreeNode * sel = q.front();
				q.pop();
				sum += sel->val;
				if (sel->left!=NULL) q.push(sel->left);
				if (sel->right!=NULL) q.push(sel->right);
			}
			sum/=num;
			res.push_back(sum);
		}
		return res;
	}
};