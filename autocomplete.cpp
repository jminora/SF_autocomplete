#include "autocomplete.h"
#include <iostream>

TrieNode::TrieNode() {
    isEndOfWord = false;
    for (int i = 0; i < 26; ++i)
        children[i] = nullptr;
}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (index < 0 || index >= 26) continue; // Skip non-lowercase letters
        if (!current->children[index])
            current->children[index] = new TrieNode();
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

void Trie::dfs(TrieNode* node, const string& prefix, vector<string>& results) {
    if (node->isEndOfWord)
        results.push_back(prefix);

    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            dfs(node->children[i], prefix + char('a' + i), results);
        }
    }
}

vector<string> Trie::autocomplete(const string& prefix) {
    TrieNode* current = root;
    for (char ch : prefix) {
        int index = ch - 'a';
        if (index < 0 || index >= 26)
            return {}; // Invalid character
        if (!current->children[index])
            return {}; // Prefix not found
        current = current->children[index];
    }

    vector<string> results;
    dfs(current, prefix, results);
    return results;
}
