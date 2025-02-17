#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// узел дерева
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f, Node* l = nullptr, Node* r = nullptr)
            : ch(c), freq(f), left(l), right(r) {}
};

// приоретет очереди
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// класс сжатия
class HuffmanCompressor {
public:
    HuffmanCompressor(const string& inputFile, const string& outputFile);
    void compress();

private:
    string inputFile;
    string outputFile;

    unordered_map<char, string> huffmanCodes;

    Node* buildHuffmanTree(const unordered_map<char, int>& freqMap);
    void generateCodes(Node* root, string code);
};
#endif //HUFFMAN_HUFFMAN_H
