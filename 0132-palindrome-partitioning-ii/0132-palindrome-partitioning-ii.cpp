class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        vector<vector<bool>> palindrome(
            n, vector<bool>(n, false)
        );

        vector<int> dp(n);

        // dp[i] = minimum cuts needed for substring s[0...i]
        for (int i = 0; i < n; i++) {
            dp[i] = i; // Maximum possible cuts

            for (int j = 0; j <= i; j++) {

                // Check if s[j...i] is a palindrome
                if (s[i] == s[j] &&
                    (i - j <= 2 || palindrome[j + 1][i - 1])) {

                    palindrome[j][i] = true;

                    // Entire substring is palindrome
                    if (j == 0) {
                        dp[i] = 0;
                    }
                    else {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};