#include "autocomplete.h"

int main() {
    Trie trie;

    // Initial dictionary
    vector<string> dictionary = {
        "apple", "app", "april", "banana", "bat", "batch", "batman", "cat", "catalog", "cater"
    };

    // Insert words into the trie
    for (const string& word : dictionary) {
        trie.insert(word);
    }

    string input;
    cout << "Autocomplete is enabled. Type a prefix to get suggestions.\n";
    cout << "Type 'exit' to quit the program.\n";

    while (true) {
        cout << "\nEnter prefix: ";
        cin >> input;

        // Check for exit command
        if (input == "exit") {
            cout << "Exiting program. Goodbye!\n";
            break;
        }

        vector<string> suggestions = trie.autocomplete(input);
        if (suggestions.empty()) {
            cout << "No matches found.\n";
        }
        else {
            cout << "Suggestions:\n";
            for (const string& word : suggestions) {
                cout << " - " << word << '\n';
            }
        }
    }

    return 0;
}
