#ifndef UNTITLED3_HUFFMAN_H
#define UNTITLED3_HUFFMAN_H


#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

// Функции работы с деревом Хаффмана
Node* getNode(char ch, int freq, Node* left, Node* right);
Node* buildHuffmanTree(const std::string& text);
void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode);
void decode(Node* root, int& index, const std::string& str, std::ofstream& out);

// Кодирование и декодирование файлов
void encodeFile(const std::string& inputFile, const std::string& outputFile);
void decodeFile(const std::string& inputFile, const std::string& outputFile);

#endif //UNTITLED3_HUFFMAN_H
