#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
using namespace std;
class Solution{
public:
	int minimumTotal(vector<vector<int>> &triangle)
	{
		vector<int> mini = triangle[triangle.size()-1];
		//cout<<triangle.size()<<'\n';
		for (int i = triangle.size()-2;i>=0;--i)
		    for (int j = 0;j < triangle[i].size();++j)
		    {
				mini[j]=triangle[i][j]+min(mini[j],mini[j+1]);
			   // cout<<mini[j]<<'\n';
			}
		return mini[0];
	}
};

void main(){
	vector<int>a;
	vector<int>b;
	vector<int>c;
	vector<int>d;
	a.push_back(2);
	b.push_back(3);
	b.push_back(4);
	c.push_back(6);
	c.push_back(5);
	c.push_back(7);
	d.push_back(4);
	d.push_back(1);
	d.push_back(8);
	d.push_back(3);
	
	vector<vector<int>>triangle;
	triangle.push_back(a);
	triangle.push_back(b);
	triangle.push_back(c);
	triangle.push_back(d);
	int a1 = triangle[3].size(); 
   
   Solution solute;
   solute.minimumTotal(triangle);	
	

}