/**************************************************************************************************/
/* 121.Best Time to Buy and Sell Stock
   Say you have an array for which the ith element is the price of a given stock on day i.
   If you were only permitted to complete at most one transaction 
   (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.*/
/*先保存最小值，再保存最大间隔值
/*************************************************************************************************/
#include<stdlib.h>
#include<vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>&prices){
		int maxPro = INT_MIN;
		int minVal = INT_MAX;
		for (int i = 0;i < prices.size();i++)
		{
			minVal = min(minVal,prices[i]);
			maxPro = max(maxPro,prices[i] - minVal);
		}
		return maxPro;
		
	}
};