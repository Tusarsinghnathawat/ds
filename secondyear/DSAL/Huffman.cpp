#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

class HuffmanNode {
public:
    char data;
    int freq;
    HuffmanNode *left, *right;

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

class Compare {
public:
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

class HuffmanTree {
public:
    HuffmanNode* buildTree(map<char, int> freqMap) {
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

        for (auto& pair : freqMap) {
            HuffmanNode* newNode = new HuffmanNode(pair.first, pair.second);
            pq.push(newNode);
        }

        while (pq.size() != 1) {
            HuffmanNode* left = pq.top();
            pq.pop();
            HuffmanNode* right = pq.top();
            pq.pop();

            HuffmanNode* internalNode = new HuffmanNode('$', left->freq + right->freq);
            internalNode->left = left;
            internalNode->right = right;

            pq.push(internalNode);
        }

        return pq.top();
    }

    void generateCodes(HuffmanNode* root, string code, map<char, string>& codes) {
        if (root == nullptr) return;

        if (root->data != '$') {
            codes[root->data] = code;
        }

        generateCodes(root->left, code + "0", codes);
        generateCodes(root->right, code + "1", codes);
    }
};

int main() {
    string text = "hello world";
    map<char, int> freqMap;

    // Count the frequency of each character
    for (char c : text) {
        freqMap[c]++;
    }

    HuffmanTree huffman;
    HuffmanNode* root = huffman.buildTree(freqMap);

    map<char, string> codes;
    huffman.generateCodes(root, "", codes);

    // Print the Huffman codes
    for (auto& pair : codes) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}
