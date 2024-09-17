class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 1;
        int size = nums.size();

        while (i < size && nums[i] < 1) {
            i++;
        }
        while (i < size) {
            if (j != nums[i])
                return j;
            i++;
            if (i < size && j != nums[i])
                j++;
        }
        if (nums[i - 1] < 1)
            return 1;
        return ++j; 
    }
};