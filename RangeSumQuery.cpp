//leetcode 307 Range Sum Query-mutable
/************************************************************************/
// Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.
//The update(i, val) function modifies nums by updating the element at index i to val.                                                                     */
/************************************************************************/
//Edit By Xuwh  2017/10/25
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class NumArray {
struct TreeNode{
		int start,end,sum;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int a,int b):start(a),end(b),left(nullptr),right(nullptr),sum(0){}
	};
private:
	TreeNode * root;
public:
	NumArray(vector<int> nums) {
		root = buildTree(0,nums.size()-1,nums);
	}
	void update(int i, int val) {
		update_helper(i,val,root);
	}
	int sumRange(int i, int j) {
		return sum_helper(i,j,root);
	}

	TreeNode *buildTree(int start,int end,vector<int>&nums){
	    if (start > end) return nullptr;
	    TreeNode *root = new TreeNode(start,end);
		if (start == end)
		{
			root->sum = nums[start];
			return root;
		}
		int mid = (start + end)/2;
		root->left = buildTree(start,mid,nums);
		root->right = buildTree(mid+1,end,nums);
		root->sum = root->left->sum+root->right->sum;
		return root;
	}

	int update_helper(int i,int val,TreeNode*root){
	int diff = 0;
	if (i==root->start && i ==root->end )
	{
		diff = val - root->sum;
		root->sum = val;
		return diff;
	}

	int mid = (root->start+root->end)/2;
	if (i > mid) diff = update_helper(i,val,root->right);
	else diff = update_helper(i,val,root->left);
	root->sum = root->sum + diff;
	return diff;	
	}

	int sum_helper(int i,int j,TreeNode * root){
		if (root == nullptr) return 0;
		if (i == root->start && j ==root->end) return root->sum;
		int mid = (root->start + root->end)/2;
		if (i>mid) return sum_helper(i,j,root->right);
		else if (j<=mid) return sum_helper(i,j,root->left);
		else return sum_helper(i,mid,root->left) + sum_helper(mid+1,j,root->right);
	}

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
int main(){
	

	
	return 0;
}