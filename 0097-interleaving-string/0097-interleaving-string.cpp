class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();

        // Length must match
        if (m + n != s3.length()) {
            return false;
        }

        vector<bool> dp(n + 1, false);

        // Empty s1 and empty s2 form empty s3
        dp[0] = true;

        // Initialize using only s2
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i <= m; i++) {

            // Using characters only from s1
            dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);

            for (int j = 1; j <= n; j++) {

                bool fromS1 = dp[j] &&
                              (s1[i - 1] == s3[i + j - 1]);

                bool fromS2 = dp[j - 1] &&
                              (s2[j - 1] == s3[i + j - 1]);

                dp[j] = fromS1 || fromS2;
            }
        }

        return dp[n];
    }
};