#include <bits/stdc++.h>
#include <string>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }
    // For user
    void insertWord(string word)
    {
        insertWord(root, word);
    }

    bool searchWord(TrieNode *root, string word)
    {
        if (root->children[word[0] - 'a'] == NULL)
        {
            return false;
        }

        if (word.size() == 1)
        {
            return root->children[word[0] - 'a']->isTerminal;
        }

        return searchWord(root->children[word[0] - 'a'], word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchWord(root, word);
    }

    void removeWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }
        removeWord(child, word.substr(1));

        // Remove child Node if it is useless
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    void removeWord(string word)
    {
        removeWord(root, word);
    }
};

int main()
{
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout << t.searchWord("and") << endl;

    t.removeWord("and");
    cout << t.searchWord("and") << endl;
}
