class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> result;

        vector<string> letters = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        string current = "";

        backtrack(digits, 0, current, result, letters);

        return result;
    }

    void backtrack(string &digits, int index, string current,
                   vector<string> &result, vector<string> &letters) {

        // Base case
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';

        for (char ch : letters[digit]) {
            backtrack(digits, index + 1, current + ch, result, letters);
        }
    }
};