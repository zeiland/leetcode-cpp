#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;
        vector<int> m(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < nums[i].size(); ++j){
                v.push_back(pair<int,int>(nums[i][j],i));
            }
        }
        sort(v.begin(),v.end());
        int left = 0;
        int right = 0;
        int res_left = 0;
        int res_right = 0;
        int min_diff = INT_MAX;
        int count = 0;
        while(right < v.size()){
            if(m[v[right].second] == 0){
                ++count;
            }
            ++m[v[right].second];
            while(left <= right && count == m.size()){
                if(v[right].first - v[left].first < min_diff){
                    min_diff = v[right].first - v[left].first;
                    res_left = v[left].first;
                    res_right = v[right].first;
                }
                --m[v[left].second];
                if(m[v[left].second] == 0){
                    --count;
                }
                ++left;
            }
            ++right;
        }
        return vector<int>{res_left, res_right};
    }
};