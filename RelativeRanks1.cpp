class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();    
		int i,j;
		vector <vector <int> >array(n);             
		for(i=0;i < n;i++) array[i].resize(2);           
		for(i=0;i < n;i++) 
		{
			array[i][0]=nums[i];
			array[i][1]=i;
		}
		vector<int>temp(2);				
		for (i=0;i<n;i++)            
			for (j=0;j<n-i-1;j++)
			{
				if(array[j][0]<array[j+1][0])
				{
					temp[0]=array[j][0];
					temp[1]=array[j][1];
					array[j][0]=array[j+1][0];
					array[j][1]=array[j+1][1];
					array[j+1][0]=temp[0];
					array[j+1][1]=temp[1];				
				}
			}
		vector<string> newArray(n);
			for(i = 0; i < n ; i++) 
			{
				if(i==0) newArray[array[i][1]]="Gold Medal";
				else if(i==1) newArray[array[i][1]]="Silver Medal";
				else if(i==2) newArray[array[i][1]]="Bronze Medal";
				else
				{
				    char c[8];
					int length = sprintf(c,"%d",1+i);
					newArray[array[i][1]]=c;					
				}
			}    
			return newArray;        
	}
};