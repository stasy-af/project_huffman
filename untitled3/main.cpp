#include "huffman.h"

int main() {
    std::string inputFile = "haffman.txt";
    std::string encodedFile = "compressed.huff";
    std::string decodedFile = "decompressed.txt";

    encodeFile(inputFile, encodedFile);
    decodeFile(encodedFile, decodedFile);

    return 0;
}
