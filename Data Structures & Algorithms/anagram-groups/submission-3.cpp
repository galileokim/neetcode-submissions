class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map{key: sorted string, val: array of strings}
        vector<vector<string>> out;
        unordered_map<string, vector<string>> anagrams;

        for (string str: strs) {
            string acc = str;
            sort(str.begin(), str.end());

            auto lookup = anagrams.find(str);

            if (lookup == anagrams.end()) {
                anagrams[str] = {};
            }
            
            anagrams[str].push_back(acc);
        }

        for (auto & key_val : anagrams) {
            out.push_back(key_val.second);
        }


        return out;
    }
};
