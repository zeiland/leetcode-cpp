#include <string>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text2.size() < text1.size()){
            swap(text1,text2);
        }
        vector<int> dp(text2.size() + 1);
        int old = 0;
        for(int i = 1; i <= text1.size(); ++i){
            old = dp[0];
            for(int j = 1; j <= text2.size(); ++j){
                int tmp = dp[j];
                if(text1[i - 1] == text2[j - 1]){
                    dp[j] = old + 1;
                } else {
                    dp[j] = max(dp[j - 1], dp[j]);
                }
                old = tmp;
            }
        }
        return dp[text2.size()];
    }
};