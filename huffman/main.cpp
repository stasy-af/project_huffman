#include <iostream>
#include "huffman.h"

int main() {
    // файлы ввода и вывода
    string inputFile = "haffman.txt";
    string outputFile = "compressed.huff";

    // создаем объект сжатия
    HuffmanCompressor compressor(inputFile, outputFile);

    // сжатие файла
    compressor.compress();

    return 0;
}
