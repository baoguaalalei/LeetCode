/* 681.Next Closest Time
*Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.
You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
*/
//Edit By Xuwh

#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
//解题思路，XX：XX四个位置每个位置的数据大小限制 （1）0-2；（2）0-4；（3）0-6；（4）0-9
//所有新组成的数据可能有3*5*7*10种情况，实际中最多只能有3*4*4*4=192种情况

class Solution
{	
public:
	string nextClosestTime(string time){
		vector<int> data_out;
		int m[4] = {600,60,10,1};
		int dat[4];		
		//提取出四个有效值
		dat[0] = time[0]-'0';
		dat[1] = time[1]-'0';
		dat[2] = time[3]-'0';
		dat[3] = time[4]-'0';
	
		//记录初始值的大小
		int data_in = dat[0]*m[0]+dat[1]*m[1]+dat[2]*m[2]+dat[3]*m[3] ;
		
		int max_data;
		int min_data;
		for (int i = 0;i <= 3;i++)
		{
			if (dat[i]>=0&&dat[i]<=2) 
			{
				for (int j=0;j<=3;j++)
				{
					if (dat[i]!=2)
					{
						for (int p=0;p<=3;p++)
						{
							if (dat[p]>=0&&dat[p]<=5)
							{
								for (int q=0;q<=3;q++)
								{
									data_out.push_back(dat[i]*600+dat[j]*60+dat[p]*10+dat[q]);								
								}
							}
						}
					}
					else
					{
						if (dat[j]==4)
						{
							if(dat[i]==2&&(dat[0]==0||dat[1]==0||dat[2]==0||dat[3]==0))
							{
								data_out.push_back(60*24);										
								continue;
							}
						}
						if (dat[j]>=0&&dat[j]<=3)
						{							
							for (int p=0;p<=3;p++)
							{
								if (dat[p]>=0&&dat[p]<=5)
								{
									for (int q=0;q<=3;q++)
									{
										data_out.push_back(dat[i]*600+dat[j]*60+dat[p]*10+dat[q]);	
									}
								}
							}
						}
					}			
				}
			}			
		}		
		//计算符合要求的大值和最小值
		vector<int>::iterator it;
		max_data = data_in;
		min_data = data_in;
		for (it = data_out.begin();it!=data_out.end();it++)
		{
			if(*it>data_in)
			{
				if (max_data == data_in)
				{
					max_data =*it;
				}
				else
				{
					if (*it<max_data)
					{
						max_data = *it;
					}
				}			
			}
			if (*it<data_in)
			{
				if (min_data == data_in)
				{
					min_data = *it;
				}
				else
				{
					if (*it<min_data)
					{
						min_data = *it;
					}
				}				
			}
		}
		int res;
		if (max_data == data_in)
		{
			res = min_data;
		}
		else
		{
			res = max_data;
		}
		time[0] = res/600 + '0';
		res %= 600;
		time[1] = res/60 + '0';
		res %= 60;
		time[3] = res/10 + '0';
		res %= 10;
		time[4] = res +'0';
		return time;		
	}
};

int main(){
	string  time = "06:49";
	Solution solu;
	string ret = solu.nextClosestTime(time);
	cout<<ret;
	return 0;

}
