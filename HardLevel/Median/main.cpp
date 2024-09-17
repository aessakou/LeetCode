class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int medIndex;
        double res;

        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        std::sort(nums1.begin(), nums1.end());

        if (nums1.size() % 2 == 1) {
            medIndex = nums1.size() / 2;
            res = nums1[medIndex];
        }
        else {
            res = (nums1[nums1.size() / 2] + nums1[(nums1.size() / 2) - 1]) / 2.00;
        }
        return res;
        
    }
};