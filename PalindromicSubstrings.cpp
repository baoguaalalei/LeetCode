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
*以某一点为起始点开始出发，向前寻找相同的数，若有相同的值，则判断这一段之间是不是回文数，如果是，则记录数增加1.
*/

class Solution{
public:
	int countSubstrings(string s){
		int num;//记录回文数
		int size_num;//保存字符串的大小
	    num = 0;
		size_num = s.size();
		for (int i = 0;i < size_num;i++)
		   for(int j = i;j < size_num;j++){
			   if (j==i)
			   {
				   num++;
			   }
			   if (j>i)
			   {
				   if (s[j]!=s[i]) continue;
				   else
				   {
					   int kuadu = j-i;
					   for (int p = 0;p <= kuadu/2; p++)
					   {
						   if (p==kuadu/2&&(s[i+p]==s[j-p])) 
						   {
							   num++;
							  // printf("%c %d\n",s[i+p],i+p);
							   break;
						   }
						   if (s[i+p]!=s[j-p]) break;
					   }
				   }
			   }
		   }
		   return num;
	}
};

int main(){
	string s = "xkjkqlajprjwefilxgpdpebieswu";
	Solution soul;
	int num = soul.countSubstrings(s);
	printf("The result is %d",num);
	return 0;
}