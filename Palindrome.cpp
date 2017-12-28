#include<iostream>
#include<stdlib.h>
#include <string>
#include<math.h>
using namespace std;

class Solution{
public:
	int largestPalindrome(int n){
		if (n==1)
		{
			return 9;
		}
		int high = (int)pow(10,n)-1,low=high /10;
		
		for(int i = high;i > low; i--)
		{
			long palindrome =createPalindrome(i);
			for(long j = high;j > low;j--)
			{
				if (palindrome/j>high)
				{
					break;
				}
				if (palindrome%j==0)
				{
					return(int)(palindrome%1337);
				}
			}
					
		}
		return -1;
	}

private:
	long createPalindrome(long num){
		string lastHalf = to_string(num);

		reverse(lastHalf.begin(),lastHalf.end());
		return stol(to_string(num)+lastHalf);		
	}

};
 int main(){
	 Solution solute;
	 int a = solute.largestPalindrome(3);	 
 }

