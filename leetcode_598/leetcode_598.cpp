#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.empty()){
            return m * n;
        }
        int min_x = INT_MAX;
        int min_y = INT_MAX;
        for(const auto& op : ops){
            min_x = min(min_x, op[0]);
            min_y = min(min_y, op[1]);
        }
        return min_x * min_y;
    }
};