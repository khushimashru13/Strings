class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        if (s.empty() || words.empty()) {
            return result;
        }

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.length() < totalLen) {
            return result;
        }

        // Store required frequency of each word
        unordered_map<string, int> required;

        for (string word : words) {
            required[word]++;
        }

        // Try each possible starting offset
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int count = 0;

            unordered_map<string, int> window;

            for (int right = offset; right + wordLen <= s.length();
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                // Word exists in required words
                if (required.count(word)) {
                    window[word]++;
                    count++;

                    // If frequency is too high, shrink window
                    while (window[word] > required[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // Found valid concatenation
                    if (count == wordCount) {
                        result.push_back(left);

                        // Move window forward
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                }
                else {
                    // Invalid word, reset window
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};