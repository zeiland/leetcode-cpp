#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1){
            return s;
        }
        string ret;
        for(int i = 0; i < numRows; ++i){
            bool flag = 0;
            for(int j = i; j < s.size();){
                ret += s[j];
                if(!flag){
                    if(numRows - 1 - i == 0){
                        j += 2 * i;
                    }
                    j += 2 *(numRows - 1 - i);
                } else{
                    if(i == 0){
                        j += 2 *(numRows - 1 - i);
                    }
                    j += 2 * i;
                }
                flag = !flag;
            }
        }
        return ret;
    }
};