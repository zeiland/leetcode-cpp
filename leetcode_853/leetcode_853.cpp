#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    double calArriveTime(int target, int position, int speed){
        return double(target-position) / speed;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.empty()){
            return 0;
        }

        int size = position.size();
        vector<pair<int,int>> v; 
        for(int i = 0;i < size; ++i){
            v.push_back(pair<int,int>(position[i],speed[i]));
        }
        sort(v.begin(), v.end());

        double last_arrive_time = calArriveTime(target, v[size-1].first, v[size-1].second);
        int ret = 1;
        for(int i = size - 2; i >= 0; --i){
            double arrive_time = calArriveTime(target, v[i].first, v[i].second);
            if(arrive_time > last_arrive_time){
                last_arrive_time = arrive_time;
                ++ret;
            }
        }     
        return ret;   
    }
};