#include <iostream>
#include <stdlib.h>
#include <iostream>

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
};

void MirrorRecursively(TreeNode *pRoot)
{ 
   if((pRoot == NULL) || (NULL == pRoot->left && NULL == pRoot->right))
	   return;
   TreeNode *pTemp = pRoot->left;
   pRoot->left = pRoot->right;
   pRoot->right = pTemp;
   if(pRoot->left)
	   MirrorRecursively(pRoot->left);  
   if(pRoot->right)
	   MirrorRecursively(pRoot->right); 
 }

