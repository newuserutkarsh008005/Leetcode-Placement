#include<iostream>
using namespace std;

class Node {

public:

    Node* child[26];
    bool isEnd;

    Node() {

        for(int i=0;i<26;i++) {
            child[i] = nullptr;
        }

        isEnd = false;
    }
};

class Trie {

public:

    Node* root;

    Trie() {
        root = new Node();
    }
};

int main() {

    Trie t;

}