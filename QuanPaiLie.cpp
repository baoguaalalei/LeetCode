#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
/************************************************************************/
/* 
//先考虑没有重复的数字的情况
vector<vector<int>>res;
//每一次将需要加入序列的数字排到前面，然后删除
int switch_data(vector<int>&data,int first,int second){
int temp = data[first];
data[first] = data[second];
data[second] = temp; 
return 0;
}

int sort(vector<int>&data,vector<int>&res1,int len)
{
if (len == 0)  //数据已经为零
{
res.push_back(res1);
return 0;
}
for (int i = 0; i < len;i++)
{
res1.push_back(data[i]);
switch_data(data,i,len-1);
sort(data,res1,len-1);
switch_data(data,len-1,i);
res1.pop_back();
}
return 0;
}
*/
/************************************************************************/
//考虑有重复数字的全排列，每次考虑可以被替换的位置。

vector<vector<int>>res;   //用于保存最后的结果

//是否交换
bool isSwap(vector<int>data,int len,int index){
	for (int i = index+1;i<len;i++)
	{
		if(data[index] == data[i])
			return false;
	}
	return true;
}
//每一次将需要加入序列的数字排到前面，然后删除
int switch_data(vector<int>&data,int first,int second){
	int temp = data[first];
	data[first] = data[second];
	data[second] = temp; 
	return 0;
}
int sort(vector<int>&data,int len,int index)
{
	if (index == len)  //数据已经为零
	{
		res.push_back(data);
		return 0;
	}
	for (int i = index; i < len;i++)
	{
		if (isSwap(data,len,i)) //首先判断 i 点位置的值是否与后面的值有重复，如果有则后移
		{
			switch_data(data,index,i); //每个与index交换
			sort(data,len,index+1);
			switch_data(data,i,index); //换回来	
		}
		
	}
	return 0;
}
int main(){
	vector<int>data(4);
	for(int i = 0;i < 4;i++)
	{
		data[i]=i;
	}
	vector<int>res1;
	sort(data,4,0);
	for (int i = 0;i < 24;i++)
	{
		for (int j = 0;j < 4;j++){
			cout<<res[i][j];
		}
		cout<<endl;
	}
	return 0;
}