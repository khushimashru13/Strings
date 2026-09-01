class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;          // Pointer for string
        int j = 0;          // Pointer for pattern
        int star = -1;      // Position of last '*'
        int match = 0;      // Position in string when '*' was found

        while (i < s.length()) {

            // Characters match or '?' matches any character
            if (j < p.length() &&
                (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }

            // Found '*'
            else if (j < p.length() && p[j] == '*') {
                star = j;
                match = i;
                j++;
            }

            // Previous '*' can match more characters
            else if (star != -1) {
                j = star + 1;
                match++;
                i = match;
            }

            // No match
            else {
                return false;
            }
        }

        // Remaining characters in pattern must be '*'
        while (j < p.length() && p[j] == '*') {
            j++;
        }

        return j == p.length();
    }
};