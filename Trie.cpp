#include <iostream>
#include <unordered_map>
using namespace std;

// Trie Node
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

// Trie Class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    // Check if any word starts with the given prefix
    bool startsWith(const string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }
};

// Main Function
int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apex");

    cout << boolalpha;
    cout << "Search 'apple': " << trie.search("apple") << endl; // true
    cout << "Search 'app': " << trie.search("app") << endl;     // true
    cout << "Search 'ap': " << trie.search("ap") << endl;       // false
    cout << "Starts with 'ap': " << trie.startsWith("ap") << endl; // true
    cout << "Starts with 'bat': " << trie.startsWith("bat") << endl; // false

    return 0;
}
