#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
/************************************************************************/
/* 
//�ȿ���û���ظ������ֵ����
vector<vector<int>>res;
//ÿһ�ν���Ҫ�������е������ŵ�ǰ�棬Ȼ��ɾ��
int switch_data(vector<int>&data,int first,int second){
int temp = data[first];
data[first] = data[second];
data[second] = temp; 
return 0;
}

int sort(vector<int>&data,vector<int>&res1,int len)
{
if (len == 0)  //�����Ѿ�Ϊ��
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
//�������ظ����ֵ�ȫ���У�ÿ�ο��ǿ��Ա��滻��λ�á�

vector<vector<int>>res;   //���ڱ������Ľ��

//�Ƿ񽻻�
bool isSwap(vector<int>data,int len,int index){
	for (int i = index+1;i<len;i++)
	{
		if(data[index] == data[i])
			return false;
	}
	return true;
}
//ÿһ�ν���Ҫ�������е������ŵ�ǰ�棬Ȼ��ɾ��
int switch_data(vector<int>&data,int first,int second){
	int temp = data[first];
	data[first] = data[second];
	data[second] = temp; 
	return 0;
}
int sort(vector<int>&data,int len,int index)
{
	if (index == len)  //�����Ѿ�Ϊ��
	{
		res.push_back(data);
		return 0;
	}
	for (int i = index; i < len;i++)
	{
		if (isSwap(data,len,i)) //�����ж� i ��λ�õ�ֵ�Ƿ�������ֵ���ظ�������������
		{
			switch_data(data,index,i); //ÿ����index����
			sort(data,len,index+1);
			switch_data(data,i,index); //������	
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