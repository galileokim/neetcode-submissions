class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == 0) {
            return {};
        }
        map<int, int> counts;
        for (int i : nums) {
            counts[i]++;
        }

        // get a vector of int vectors
        // the frequency is the index
        // if the vector is not empty, append the nums of the vector

        vector<vector<int>> vec(nums.size() + 1);

        // load vector with ordered frequencies and corresponding values in a vector
        for (auto kv : counts) {
            vec[kv.second].push_back(kv.first);
        }

        vector<int> out;

        for (int i = vec.size()-1; i > 0; i--) {
            if (vec[i].size() > 0) {
                for (int i : vec[i]) {
                    out.push_back(i);
                    
                    if (out.size() == k) {
                        return out;
                    }
                }
            }
        }
    }
};
