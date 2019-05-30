#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int cur_len = 0; 
        unordered_map<char,int> m;
        for(int i=0;i<s.size();++i){
            int limit_len = 0;
            if(m.count(s[i])){
                limit_len = i - m[s[i]];
            } else{
                limit_len = i + 1; 
            }
            m[s[i]] = i;
            cur_len = min(cur_len + 1, limit_len);
            max_len = max(max_len, cur_len);
        }
        return max_len;
    }
};