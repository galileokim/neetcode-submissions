class Solution {
public:
    int search(vector<int>& nums, int target) {

        if (nums.size() == 0) {
            return -1;
        }

        if (nums.size() == 1) {
            if (target == nums[0]) {
                return 0;
            } else {
                return -1;
            }
        }
        
        int beg = 0;
        int end = nums.size() - 1;

        while (beg < end) {
            int mid = (beg + end - 1) / 2; 

            if (target == nums[mid]) {
                return mid;
            }

            if (target > nums[mid]) {
                if (nums[mid] < nums[beg]) {
                    end = mid;
                } else {
                    beg = mid + 1;
                }
            } else {
                if (target < nums[beg]) {
                    beg = mid + 1;
                } else {
                    end = mid;
                }
            }
        }

        return -1;
    }
};
