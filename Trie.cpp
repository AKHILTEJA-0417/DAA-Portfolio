#include <iostream>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    int wordCount;

    TrieNode() {
        wordCount = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

void insert(TrieNode* root, const string& key) {
    TrieNode* current = root;
    for (char c : key) {
        int index = c - 'a';
        if (current->children[index] == NULL)
            current->children[index] = new TrieNode();
        current = current->children[index];
    }
    current->wordCount++;
}

int search(TrieNode* root, const string& key) {
    TrieNode* current = root;
    for (char c : key) {
        int index = c - 'a';
        if (current->children[index] == NULL)
            return 0;
        current = current->children[index];
    }
    return current->wordCount > 0 ? 1 : 0;
}

int remove(TrieNode* root, const string& key) {
    TrieNode* current = root;
    TrieNode* lastBranch = NULL;
    char lastBranchChar;

    for (char c : key) {
        int index = c - 'a';
        if (current->children[index] == NULL)
            return 0;

        int childCount = 0;
        for (int i = 0; i < 26; i++) {
            if (current->children[i] != NULL)
                childCount++;
        }

        if (childCount > 1) {
            lastBranch = current;
            lastBranchChar = c;
        }
        current = current->children[index];
    }

    int childCount = 0;
    for (int i = 0; i < 26; i++) {
        if (current->children[i] != NULL)
            childCount++;
    }

    if (childCount > 0) {
        current->wordCount--;
    } else if (lastBranch) {
        lastBranch->children[lastBranchChar - 'a'] = NULL;
    } else {
        root->children[key[0] - 'a'] = NULL;
    }

    return 1;
}

void displayAllWords(TrieNode* root, string prefix) {
    if (root->wordCount > 0) {
        cout << prefix << "\n";
    }

    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            char nextChar = 'a' + i;
            displayAllWords(root->children[i], prefix + nextChar);
        }
    }
}

int main() {
    TrieNode* root = new TrieNode();
    int choice;

    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Search\n3. Delete\n4. Display All Words\n5. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string word;
            cout << "Enter word to insert: ";
            cin >> word;
            insert(root, word);
            cout << "Word inserted successfully.\n";
        } else if (choice == 2) {
            string word;
            cout << "Enter word to search: ";
            cin >> word;
            if (search(root, word)) {
                cout << "Word found in Trie.\n";
            } else {
                cout << "Word not found in Trie.\n";
            }
        } else if (choice == 3) {
            string word;
            cout << "Enter word to delete: ";
            cin >> word;
            if (remove(root, word)) {
                cout << "Word deleted successfully.\n";
            } else {
                cout << "Word not found in Trie.\n";
            }
        } else if (choice == 4) {
            cout << "Words in Trie:\n";
            displayAllWords(root, "");
        } else if (choice == 5) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
