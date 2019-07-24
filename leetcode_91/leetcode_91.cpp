#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0){
            return 0;
        }
        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        if(s[0] != '0'){
            dp[1] = 1;
        }
        for(int i = 1; i < s.size(); ++i){
            if(s[i] != '0'){
                dp[i + 1] = dp[i];
            }
            if(s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7'){
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[s.size()];
    }
};