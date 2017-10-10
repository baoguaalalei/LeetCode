#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
/*
leetcode 647
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
*/
//Edit by xwh 2017/10/10

//算法思路
/*
*以每一点为中心向外扩展，碰到两边的数据相同时，count增加1。
*/

class Solution{
public:
	int countSubstrings(string s){
		int res = 0, n = s.length();
		for(int i = 0; i < n; i++){
			for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)res++;   //substring s[i-j, ..., i+j]
			for(int j = 0; i-1-j >= 0 && i+j < n && s[i-1-j] == s[i+j]; j++)res++; //substring s[i-1-j, ..., i+j]
		}
		return res;	
	}
};

int main(){
	string s = "xkjkqlajprjwefilxgpdpebieswu";
	Solution soul;
	int num = soul.countSubstrings(s);
	printf("The result is %d",num);
	return 0;
}