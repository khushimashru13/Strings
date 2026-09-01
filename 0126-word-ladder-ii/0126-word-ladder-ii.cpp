class Solution {
public:
    vector<vector<string>> result;
    unordered_map<string, vector<string>> parent;

    void backtrack(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> sequence = path;
            reverse(sequence.begin(), sequence.end());
            result.push_back(sequence);
            return;
        }

        for (string prev : parent[word]) {
            path.push_back(prev);
            backtrack(prev, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        // If endWord is not in wordList
        if (words.find(endWord) == words.end()) {
            return {};
        }

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;
        int wordLength = beginWord.length();

        while (!q.empty() && !found) {
            int size = q.size();

            // Words visited in the current BFS level
            unordered_set<string> levelVisited;

            for (int k = 0; k < size; k++) {
                string current = q.front();
                q.pop();

                string word = current;

                // Try changing every character
                for (int i = 0; i < wordLength; i++) {
                    char original = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;

                        word[i] = c;

                        if (words.find(word) != words.end()) {

                            // Store parent for backtracking
                            if (visited.find(word) == visited.end()) {
                                parent[word].push_back(current);

                                if (levelVisited.find(word) == levelVisited.end()) {
                                    q.push(word);
                                    levelVisited.insert(word);
                                }

                                if (word == endWord) {
                                    found = true;
                                }
                            }
                            // Another shortest path to same word
                            else if (levelVisited.find(word) != levelVisited.end()) {
                                parent[word].push_back(current);
                            }
                        }
                    }

                    word[i] = original;
                }
            }

            // Mark current level as visited
            for (string word : levelVisited) {
                visited.insert(word);
            }
        }

        // No transformation found
        if (!found) {
            return {};
        }

        // Start backtracking from endWord
        vector<string> path;
        path.push_back(endWord);

        backtrack(endWord, beginWord, path);

        return result;
    }
};