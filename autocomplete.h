#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Trie node class representing each character
class TrieNode {
public:
	TrieNode* children[26];  // Array for 'a' to 'z'
	bool isEndOfWord;        // True if the node represents the end of a word

	TrieNode();
};

// Trie data structure class
class Trie {
private:
	TrieNode* root;

	// Depth-first search to collect all words starting from the current node
	void dfs(TrieNode* node, const string& prefix, vector<string>& results);

public:
	Trie();

	// Insert a word into the trie
	void insert(const string& word);

	// Return all words in the trie that start with the given prefix
	vector<string> autocomplete(const string& prefix);
};
