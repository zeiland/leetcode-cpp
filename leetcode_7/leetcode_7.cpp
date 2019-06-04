#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x < 0){
            sign = -1;
        }
        long long int num = x;
        string n = to_string(abs(num));
        std::reverse(n.begin(), n.end());
        long long int ret = sign * stol(n);
        if(ret <= INT_MAX && ret >= INT_MIN){
            return ret;
        } else{
            return 0;
        }
    }
};