#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
class Solution{
public:
	int countSubstrings(string s){
		int num;//��¼������
		int size_num;//�����ַ����Ĵ�С
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