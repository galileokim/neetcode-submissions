class Solution {
public:
    int search(vector<int>& nums, int target) {

        // if beg > end
        // if mid < beg there is a swap in that region
        // if mid > end there is a swap in that region
        // if target > mid, we want to search in a swapped region
        // if target < mid, we'll get there

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
