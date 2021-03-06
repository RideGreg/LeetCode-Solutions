// Time:  O(26 * d * l) = O(d * l), d is the size of wordlist, l is the max length of words
// Space: O(d * l)

// two-end bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> lookup(cbegin(wordList), cend(wordList));
        if (!lookup.count(endWord)) {
            return 0;
        }
        int ladder = 2;
        for (unordered_set<string> left = {beginWord}, right = {endWord};
             !left.empty() && !right.empty();
             ++ladder) {
            if (left.size() > right.size()) {
                swap(left, right);
            }
            unordered_set<string> new_left;
            for (const auto& word : left) {
                auto new_word = word;
                for (int i = 0; i < new_word.length(); ++i) {
                    char prev = new_word[i];
                    for (int j = 0; j < 26; ++j) {
                        new_word[i] = 'a' + j;
                        if (right.count(new_word)) {
                            return ladder;
                        }
                        if (lookup.count(new_word)) {
                            lookup.erase(new_word);
                            new_left.emplace(new_word);
                        }
                    }
                    new_word[i] = prev;
                }
            }
            left = move(new_left);
        }
        return 0;
    }
};

// Time:  O(26 * d * l) = O(d * l), d is the size of wordlist, l is the max length of words
// Space: O(d * l)
class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> lookup(cbegin(wordList), cend(wordList));
        if (!lookup.count(endWord)) {
            return 0;
        }
        int ladder = 2;
        for (vector<string> q = {beginWord}; !q.empty(); ++ladder) {
            vector<string> new_q;
            for (const auto& word : q) {
                auto new_word = word;
                for (int i = 0; i < new_word.length(); ++i) {
                    char prev = new_word[i];
                    for (int j = 0; j < 26; ++j) {
                        new_word[i] = 'a' + j;
                        if (new_word == endWord) {
                            return ladder;
                        }
                        if (lookup.count(new_word)) {
                            lookup.erase(new_word);
                            new_q.emplace_back(new_word);
                        }
                    }
                    new_word[i] = prev;
                }
            }
            q = move(new_q);
        }
        return 0;
    }
};
