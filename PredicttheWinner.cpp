#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

//leetcode 486 动态规划，判断第一个选牌的人是否可以胜出。
/*
Given an array of scores that are non-negative integers. 
Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. 
Each time a player picks a number, that number will not be available for the next player. 
This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.
*/

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n)); // use to keep the score gap between player1 and player2
		for (int i = 0; i < n; i++)
		{
			dp[i][i] = nums[i];
			printf("dp[%d][%d] = nums[%d]   %d\n",i,i,i, nums[i]);
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j+i < n; j++) {
				dp[j][j+i] = max(nums[j+i]-dp[j][j+i-1], nums[j]-dp[j+1][j+i]); // dp[j][j+i] means the max gap between nums[j] and nums[j+i]
		        printf("dp[%d][%d] = max(nums[%d]-dp[%d][%d],nums[%d]-dp[%d][%d])    %d\n",j,j+i,j+i,j,j+i-1,j,j+1,j+i,dp[j][j+i]);
			}
		}
		return dp[0][n-1] >= 0; // player1 get more score points than player2
	}
};

/*
void main(){
	vector<int>nums;
    nums.push_back(1);
	nums.push_back(5);
	nums.push_back(2);
	//nums.push_back(7);
	bool res;
	Solution res1;
	res = res1.PredictTheWinner(nums);
	return;
}*/