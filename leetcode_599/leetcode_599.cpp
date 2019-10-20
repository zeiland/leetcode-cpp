#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,pair<int,int>> m;
        for(int i = 0; i < list1.size(); ++i){
            m[list1[i]].first += 1;
            m[list1[i]].second += i;
        }
        for(int i = 0; i < list2.size(); ++i){
            m[list2[i]].first += 1;
            m[list2[i]].second += i;
        }
        vector<string> ret;
        int min_index_sum = INT_MAX;
        for(const auto& x: m){
            if(x.second.first == 2){
                if(x.second.second < min_index_sum){
                    ret.clear();
                    ret.push_back(x.first);
                    min_index_sum = x.second.second;
                } else if(x.second.second == min_index_sum){
                    ret.push_back(x.first);
                }
            }
        }
        return ret;
    }
};