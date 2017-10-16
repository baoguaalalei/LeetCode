/************************************************************************/
/*49. Group Anagrams
/*Given an array of strings, group anagrams together.
*For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],                                                         */
/************************************************************************/
//Edit By Xuwh 2017/10/16

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
class Solution{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs){
		
		unordered_map<string,multiset<string>> mp;
		for (string s:strs)
		{
			string t = s;
			sort(t.begin(),t.end());
			mp[t].insert(s);
		}
		vector<vector<string>> res;
		for (auto m : mp)
		{
			vector<string> anagram(m.second.begin(),m.second.end());
			res.push_back(anagram);
		}
		return res;		
	}
};

int main(){
	vector<string>strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");

	Solution solute;
	vector<vector<string>> res;
	res = solute.groupAnagrams(strs);
	vector<vector<string>>::iterator it;
	for (it = res.begin();it != res.end();it++)
	{
		vector<string>::iterator it1;
		for (it1 = (*it).begin();it1 != (*it).end();it1++)
		{
			cout<<*it1<<" ";	

		}
		cout <<endl;
	}
    
   

}