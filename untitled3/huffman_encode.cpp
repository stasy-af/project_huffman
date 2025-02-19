#include "huffman.h"

void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void encodeFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream in(inputFile, std::ios::binary);
    if (!in) {
        std::cerr << "Error opening input file \n";
        return;
    }

    std::string text((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    Node* root = buildHuffmanTree(text);
    std::unordered_map<char, std::string> huffmanCode;
    encode(root, "", huffmanCode);

    std::ofstream out(outputFile, std::ios::binary);
    if (!out) {
        std::cerr << "Error opening output file\n";
        return;
    }

    // Запись таблицы кодов
    out << huffmanCode.size() << '\n';
    for (auto pair : huffmanCode) {
        out << pair.first << " " << pair.second << '\n';
    }

    // Запись закодированных данных
    std::string encodedText;
    for (char ch : text) {
        encodedText += huffmanCode[ch];
    }
    out << encodedText;

    out.close();
    std::cout << "File encoded successfully: " << outputFile << std::endl;
}
