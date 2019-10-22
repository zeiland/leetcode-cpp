#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:

    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        int max_pre = A[0];
        int ret = 0;
        for(int j=1; j<n; j++){
            ret = max(ret, max_pre+A[j]-j);
            max_pre = max(max_pre, A[j]+j);
        }
        return ret;
    }
};