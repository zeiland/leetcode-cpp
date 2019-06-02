#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:

int findKth(const vector<int>& nums1, int begin1, const vector<int>& nums2, int begin2, int k)
{
	if (begin1 == nums1.size()){
		return nums2[begin2 + k - 1];
    }
	if (begin2 == nums2.size()){
		return nums1[begin1 + k - 1];
    }
	if (k == 1){
		return min(nums1[begin1], nums2[begin2]);
    }
	int mid = min(k / 2, static_cast<int>(nums1.size()));
	mid = min(static_cast<int>(nums2.size()), mid);
	if (nums1[begin1 + mid - 1] < nums2[begin2 + mid - 1]){
		return findKth(nums1, begin1 + mid, nums2, begin2, k - mid);
    } else {
		return findKth(nums1, begin1, nums2, begin2 + mid, k - mid);
    }
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	int m = nums1.size();
	int n = nums2.size();
	if ((m + n) % 2 == 0) {
		return (static_cast<double>(findKth(nums1, 0, nums2, 0, (m + n) / 2)) + findKth(nums1, 0, nums2, 0, (m + n) / 2 + 1)) / 2;
    } else {
		return static_cast<double>(findKth(nums1, 0, nums2, 0, (m + n) / 2 + 1));
    }
}

};