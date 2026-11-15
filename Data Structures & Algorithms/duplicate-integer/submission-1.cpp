class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> found;

        for (int i : nums) {
            if (found.contains(i)) {
                return true;
            }

            found.insert(i);
        }

        return false;
    }
};