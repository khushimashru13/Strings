class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void backtrack(string& s, int start, vector<string>& path) {
        // If we reached the end of the string
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        // Try every possible substring
        for (int end = start; end < s.length(); end++) {

            // If substring is palindrome
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));

                backtrack(s, end + 1, path);

                // Backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;

        backtrack(s, 0, path);

        return result;
    }
};