#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    bool isPali(string s){        
        for(int i = 0; i < s.size() / 2; i ++)         
            if(s[i] != s[s.size() - i - 1])                
                return false;         
        return true;    
    }
 
    
    void dfs(vector<vector<string>> &ans, vector<string> &tmp, int n, string s){
        if(n == s.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i = n; i < s.size(); i ++){
            if(isPali(s.substr(n, i - n + 1))){                
                tmp.push_back(s.substr(n, i - n + 1));                
                dfs(ans, tmp, i + 1, s);                
                tmp.pop_back();            
            }
 
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        dfs(ans, tmp, 0, s);
        return ans;
    }
};