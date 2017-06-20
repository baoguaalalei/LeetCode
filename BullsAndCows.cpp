class Solution {
public:
    string getHint(string secret, string guess) {
        
        int a=0;
        
        int b=0;
        
        vector<int>Svet(10,0);//0~9 for vector
        
        vector<int>Gvet(10,0);//0~9 for guess
		
		if(secret.size()!==guess.size()||secret.size()==0)
			
		return "0A0B";
        
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
            {
                a++;
            }
            else
            {
                Svet[secret[i]-'0']++;
                Gvet[guess[i]-'0']++;
            }
        }
        
        for(int i=0;i<Svet.size();i++)
        {
            b+=min(Svet[i],Gvet[i]);
        }
        
        return to_string(a)+"A"+to_string(b)+"B";
    }
};