#include "huffman.h"

// конструктор
HuffmanCompressor::HuffmanCompressor(const string& inputFile, const string& outputFile)
        : inputFile(inputFile), outputFile(outputFile) {}

// построение дерева
Node* HuffmanCompressor::buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (const auto& pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        pq.push(new Node('\0', left->freq + right->freq, left, right));
    }

    return pq.top();
}

// генерация кода
void HuffmanCompressor::generateCodes(Node* root, string code) {
    if (!root) return;

    if (root->ch != '\0') {
        huffmanCodes[root->ch] = code;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

// сжатие файла
void HuffmanCompressor::compress() {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile) {
        cerr << "Error: Could not open input file: " << inputFile << endl;
        return;
    }

    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    unordered_map<char, int> freqMap;
    for (char ch : content) {
        freqMap[ch]++;
    }

    Node* root = buildHuffmanTree(freqMap);

    generateCodes(root, "");

    string encodedData;
    for (char ch : content) {
        encodedData += huffmanCodes[ch];
    }

    ofstream outFile(outputFile, ios::binary);
    if (!outFile) {
        cerr << "Error: Could not create output file: " << outputFile << endl;
        return;
    }

    outFile << encodedData;
    outFile.close();
    cout << "File successfully compressed to " << outputFile << endl;

}


