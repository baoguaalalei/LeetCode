#include <iostream>
#include <stdlib.h>

/*
给定一个排序的数组，给出范围摘要
Given a sorted integer array without duplicates, return the summary of its ranges.
*/
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
	if (NULL == nums)
	{
		return NULL;
	}
	char ** ret = (char**)malloc(sizeof(char*)*numsSize);
	int count;
	int left,right;
	count =0;
	for (int i = 0;i < numsSize;)
	{
		left = nums[i];
		right = nums[i];
		for (int j = i+1;j<=numsSize;j++)
		{	
			if (j==numsSize)
			{

				ret[count++] = (char*)malloc(sizeof(char)*50);
				if (right != left)
				{
					sprintf(ret[count-1],"%d->%d",left,right);
					i=j;
				}
				else
				{
					sprintf(ret[count-1],"%d",left);	
				    i=j;
				}				
		
				break;
			}
			if (nums[j]-nums[j-1]==1) 
			{
				right = nums[j];
				continue;
			}
			else
			{
				right = nums[j-1];
				ret[count++] = (char*)malloc(sizeof(char)*50);
				if (right != left)
				{
					sprintf(ret[count-1],"%d->%d",left,right);
				}
				else
				{
					sprintf(ret[count-1],"%d",left);				
				}
				left = nums[j];
				i = j;
				break;
			}
			if (j==numsSize)
			{

				ret[count++] = (char*)malloc(sizeof(char)*50);
				sprintf(ret[count-1],"%d",left);
				i++;
				break;
			}


			 
		}
	}
	returnSize[0] = count;
	return ret;
}
int main(){
	int nums[] = {0,1,2,4,5,7};
	int returnSize[]={0};
	char ** p =	summaryRanges(nums, 6, returnSize);
	for (int i = 0;i < returnSize[0];i++)
	{
		printf("%s\n",p[i]);
	}

	return 0;
}