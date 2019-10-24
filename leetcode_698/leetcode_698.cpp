#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


class Solution {
public:
    bool enumerate(vector<int>& nums, vector<int> &sums, int start, int target){
        if ( start < 0 ) {
            return true;
        }
        for (size_t subset = 0; subset < sums.size(); subset++ )
        {
            if ( sums[subset] + nums[start] <= target ) {
                sums[subset] += nums[start];
                if ( enumerate(nums, sums, start-1, target) )
                    return true;
                sums[subset] -= nums[start];
            }
            
            if (sums[subset] == 0 ) break; //key point
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k){
        vector<int> sums(k, 0);
        
        int sum = 0;
        for ( int num : nums )
            sum += num;
        
        if ( sum % k != 0 )
            return false;
        int target = sum / k;
        sort(nums.begin(), nums.end());
        if ( nums[nums.size()-1] > target ) {
            return false;
        }
        return enumerate(nums, sums, nums.size()-1, target);
    }
};