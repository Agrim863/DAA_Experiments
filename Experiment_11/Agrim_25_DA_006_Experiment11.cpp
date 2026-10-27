// Huffman Coding for data compression
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(Node* l, Node* r) { return l->freq > r->freq; }
};
void getCodes(Node* root, string str, unordered_map<char, string> &codes) {
    if (!root) return;
    if (!root->left && !root->right) codes[root->ch] = str;
    getCodes(root->left, str + "0", codes);
    getCodes(root->right, str + "1", codes);
}
void huffman(string text) {
    unordered_map<char, int> freq;
    for (char c : text) freq[c]++;

    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : freq) pq.push(new Node(pair.first, pair.second));

    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    unordered_map<char, string> codes;
    getCodes(pq.top(), "", codes);

    for (auto pair : codes) {
        cout << pair.first << ": " << pair.second << "\n";
    }
}

int main() {
    huffman("hello huffman");
    return 0;
}
