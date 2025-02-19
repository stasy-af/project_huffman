#include "huffman.h"

void decode(Node* root, int& index, const std::string& str, std::ofstream& out) {
    if (!root) return;

    if (!root->left && !root->right) {
        out.put(root->ch);
        return;
    }

    index++;
    if (index < str.size()) {
        if (str[index] == '0')
            decode(root->left, index, str, out);
        else
            decode(root->right, index, str, out);
    }
}

void decodeFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream in(inputFile, std::ios::binary);
    if (!in) {
        std::cerr << "Error opening input file \n";
        return;
    }

    // Восстановление таблицы кодов
    std::unordered_map<std::string, char> reverseHuffmanCode;
    int tableSize;
    in >> tableSize;
    in.ignore();

    for (int i = 0; i < tableSize; ++i) {
        char ch;
        std::string code;
        in.get(ch);
        in.ignore();
        std::getline(in, code);
        reverseHuffmanCode[code] = ch;
    }

    // Чтение закодированного текста
    std::string encodedText;
    std::getline(in, encodedText);
    in.close();

    std::ofstream out(outputFile, std::ios::binary);
    if (!out) {
        std::cerr << "Error opening output file\n";
        return;
    }

    // Декодирование по таблице
    std::string buffer;
    for (char bit : encodedText) {
        buffer += bit;
        if (reverseHuffmanCode.find(buffer) != reverseHuffmanCode.end()) {
            out.put(reverseHuffmanCode[buffer]);
            buffer.clear();
        }
    }

    out.close();
    std::cout << "File decoded successfully: " << outputFile << std::endl;
}
