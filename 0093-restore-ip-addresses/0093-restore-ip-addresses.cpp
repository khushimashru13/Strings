class Solution {
public:
    vector<string> result;

    bool isValid(string s) {
        // Cannot have leading zeros unless the number is exactly "0"
        if (s.length() > 1 && s[0] == '0') {
            return false;
        }

        int num = stoi(s);

        return num >= 0 && num <= 255;
    }

    void backtrack(string& s, int index, int parts, string current) {

        // If 4 parts are created
        if (parts == 4) {
            // Check if entire string is used
            if (index == s.length()) {
                current.pop_back(); // Remove last dot
                result.push_back(current);
            }
            return;
        }

        // Each IP part can have 1 to 3 digits
        for (int len = 1; len <= 3; len++) {
            if (index + len > s.length()) {
                break;
            }

            string part = s.substr(index, len);

            if (isValid(part)) {
                backtrack(s, index + len, parts + 1,
                          current + part + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        // IP address must contain between 4 and 12 digits
        if (s.length() < 4 || s.length() > 12) {
            return {};
        }

        backtrack(s, 0, 0, "");

        return result;
    }
};