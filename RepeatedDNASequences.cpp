#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
/*
* xwh
*  'stores' stores all substrings that already appear
*  'added'  stores all substrings that already added into results 
*/
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		string clip=s.substr(0,10);      //Ŀǰ����Աȵ�����
		vector<string>result;            //����ĶԱȵĽ��
		unordered_set<string> stores;    //�������е�Ƭ��
		stores.insert(clip);
		unordered_set<string> added;     //������ֹ�һ��
		for (int i = 10;i<s.length();++i)
		{
			clip = clip.substr(1) + s[i];
			if (stores.count(clip)>0 && added.count(clip)==0)
			{
				result.push_back(clip);
				added.insert(clip);
			}
			stores.insert(clip);
		}
		return result;
	}
};
 int main(){
	 class Solution solution;
	 string a = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	 vector<string>result1 = solution.findRepeatedDnaSequences(a);
	 int Size1= result1.size();
	 for (int i = 0;i < Size1;i++)
	 {
		 string a_out =result1[i];
		 cout<<a_out<<endl;		 
	 }
	// cout<<result1<<endl;
	 return 0;
 }