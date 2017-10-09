/*
leetCode 682 Baseball Game 
You're now a baseball game point recorder.
Given a list of strings, each string can be one of the 4 following types:

Integer (one round's score): Directly represents the number of points you get in this round.
"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
Each round's operation is permanent and could have an impact on the round before and the round after.
You need to return the sum of the points you could get in all the rounds.
*/

//Edit by xuwh 2017Äê10ÔÂ9ÈÕ

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution
{
public:
	int calPoints(vector<string>& ops){
		int sum = 0;
		int score =0;
		vector <int> Round;
		vector <string>::iterator it;
		//int num = 0;
		for (it = ops.begin();it != ops.end(); it++)
		{
		//	num++;
			string a = *it;
			if (a=="C")
			{
				sum -= Round.back();
				Round.pop_back();
				continue;		
			}
			if (a=="D")
			{
				score = Round.back()*2;
				sum += score;				
			}
			else if (a == "+")
			{			
				score = Round[Round.size()-1]+Round[Round.size()-2];
				sum += score;
			}
			else
			{
				std::stringstream str;
				str<<a;				
				str>>score;
				sum += score;
			}
			Round.push_back(score);
			//printf("Round %d: You get %d point.The sum is :%d\n",num,score,sum);
	    } 
		return sum;		
	}
};
int main(){
	vector<string> a;
	a.push_back("5");
	a.push_back("-2");
	a.push_back("4");
	a.push_back("C");
	a.push_back("D");
	a.push_back("9");
	a.push_back("+");
	a.push_back("+");
	Solution solu;
	int result_data = solu.calPoints(a);
	printf("The result is %d",result_data);
}
