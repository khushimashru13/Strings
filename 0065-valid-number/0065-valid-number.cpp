class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExponent = false;

        for (int i = 0; i < s.length(); i++) {

            // If character is a digit
            if (isdigit(s[i])) {
                seenDigit = true;
            }

            // If character is + or -
            else if (s[i] == '+' || s[i] == '-') {
                // Sign is valid only at beginning
                // or immediately after e/E
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            }

            // If character is decimal point
            else if (s[i] == '.') {
                // Dot cannot appear after exponent
                // and cannot appear more than once
                if (seenDot || seenExponent) {
                    return false;
                }

                seenDot = true;
            }

            // If character is e or E
            else if (s[i] == 'e' || s[i] == 'E') {
                // Exponent must appear once and after a number
                if (seenExponent || !seenDigit) {
                    return false;
                }

                seenExponent = true;
                seenDigit = false; // Need digits after e/E
            }

            // Any other character is invalid
            else {
                return false;
            }
        }

        return seenDigit;
    }
};