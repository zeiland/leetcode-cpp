#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ret;

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> res;
        helper(res, 1, k, n);
        return ret;
    }

    void helper(vector<int>& res, int begin, int k, int n){
        if(n == 0 && k == 0){
            ret.push_back(res);
            return;
        }
        if (n == 0 || k == 0){
            return;
        }
        for(int i = begin; i <= n && i <= 9; ++i){
            res.push_back(i);
            helper(res, i + 1, k - 1, n - i);
            res.pop_back();
        }
        return;
    }
};