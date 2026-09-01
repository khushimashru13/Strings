class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;

            // Sort the string to create the key
            sort(key.begin(), key.end());

            // Put the original string into its group
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto& pair : mp) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};