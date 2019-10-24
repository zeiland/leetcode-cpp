#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int ccw(vector<int>& o, vector<int>& a, vector<int>& b) {
        return (a[0] - o[0]) * (b[1] - o[1]) - (b[0] - o[0]) * (a[1] - o[1]);
    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 3) return points;
        
        // Sort points by x coordinate
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
        });
        
        // Hull
        vector<vector<int>> hull(2 * n, vector<int>(2));
        
        // Lower hull
        int k = 0;
        for (int i = 0; i < n; ++i) {
            while (k >= 2 && ccw(hull[k-2], hull[k-1], points[i]) < 0) --k;
            hull[k++] = points[i];
        }

        // Upper hull;
        for (int i = n - 2, t = k + 1; i >= 0; --i) {
            while (k >= t && ccw(hull[k-2], hull[k-1], points[i]) < 0) --k;
            hull[k++] = points[i];
        }
        
        hull.resize(k-1);
        return hull;
    }
};