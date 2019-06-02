#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string str;
        str += '^';
        str += '#';
        for(const auto& ch: s){
            str += ch;
            str += '#';
        }
        str += '$';

        vector<int> p(str.size());
        int id = 0;
        int mx = 0;
        for(int i = 1; i < str.size() - 1; ++i){
            if(i < mx){
                p[i] = min(p[2 * id - i], mx - i);
            } else {
                p[i] = 0;
            }
            while (str[i + p[i] + 1] == str[i - p[i] - 1]){
                ++p[i];
            }
            if(i + p[i] > mx){
                mx = i + p[i];
                id = i;
            }
        } 

        int max_pos = 0;
        int max_p = 0;
        for(int i = 1; i < p.size(); ++i){
            if(p[i] > max_p){
                max_pos = i;
                max_p = p[i];
            }
        }
        string ret;
        for(int i = max_pos - max_p; i < max_pos + max_p ; ++i){
            if(str[i] != '#'){
                ret += str[i];
            }
        }
        return ret;
    }
};