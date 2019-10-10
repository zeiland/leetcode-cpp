#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int high = *max_element(A.begin(), A.end());
        int low = *min_element(A.begin(),A.end());
        int ret = high - low;
        return ret - 2 * K < 0 ? 0 :  ret - 2 * K;
    }
};