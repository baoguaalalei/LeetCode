/*
In English, we have a concept called root, which can be followed by some other words to form another longer word.
let's call this word successor. For example, the root an, followed by other, which can form another word another.
Now, given a dictionary consisting of many roots and a sentence. 
You need to replace all the successor in the sentence with the root forming it. 
If a successor has many roots can form it, replace it with the root with the shortest length.
You need to output the sentence after the replacement.
*/
//解题思路是：
//1、先建立一个链表，用于保存不同字母开头的最小字符串字典；
//2、对需要查找的句子按照空格进行分割，将每一个小句子在字典中进行查找并返回查抄的值;
//3、对返回中的值进行拼接。

class Solution{
	public :
	    string replaceWords(vector<string>&dict, string sentence){
			stringstream sen(sentence);
			string res = "";
			string token;
			TrieTree tree;
			tree.buildTree(dict);
			while(getline(sen,token,' ')){
				res+=tree.replace(token);
				res+=" ";
			}
			return res.substr(0,res.size()-1);
		}
		class TrieNode{
		public:
		    bool end;
			string str;
			TrieNode* children[26];
			TrieNode(bool flag, string s){
				end = flag;
				str = s;
				memset(children,0,sizeof(children));
			}
		};
		class TrieTree{
		public:
            TrieNode* root;
            TrieTree(){
				root = new TrieNode(false,"");
			}
            
            void buildTree(vector<string>&dict){
				for(string s:dict){
					TrieNode* cur = root;
					for(char c:s)
					{
						if(cur->children[c-'a']==NULL){
							cur->children[c-'a']=new TrieNode(false,"");
							cur = cur->children[c-'a'];
						}
						else if(cur->children[c-'a']->end==true){
							cur==NULL;
							break;
						}
						else cur=cur->children[c-'a'];
					}
					if(cur!= NULL){
						cur->end=true;
						cur->str=s;
					}					
				}
				return;
			}
           string replace(string s){
			   TrieNode *cur =root;
			   string res = "";
			   for(char c:s){
				   cur = cur->children[c-'a'];
				   if(cur==NULL) break;
				   if(cur->end==true){
					   res = cur ->str;
					   break;				   
				   }				   
			   }
			   if(res!="") return res;
			   return s;
		   }			
		};
};