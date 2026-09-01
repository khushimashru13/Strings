class Solution {
public:
    unordered_map<string, bool> memo;

    bool isScramble(string s1, string s2) {
        string key = s1 + "#" + s2;

        // Check memoized result
        if (memo.count(key)) {
            return memo[key];
        }

        // If both strings are equal
        if (s1 == s2) {
            return memo[key] = true;
        }

        // If characters are different, cannot be scrambled
        string a = s1;
        string b = s2;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a != b) {
            return memo[key] = false;
        }

        int n = s1.length();

        // Try every possible split
        for (int i = 1; i < n; i++) {

            // Case 1: No swap
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Case 2: Swap
            if (isScramble(s1.substr(0, i),
                           s2.substr(n - i)) &&
                isScramble(s1.substr(i),
                           s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};