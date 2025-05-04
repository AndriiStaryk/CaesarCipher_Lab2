#include <iostream>
#include <fstream>
#include "caesar.h"

int main() {
    std::ifstream input_file("input.txt");
    if (!input_file) {
        std::cerr << "Cannot open input file!" << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(input_file)),
                      std::istreambuf_iterator<char>());
    input_file.close();

    int shift = 11;
    std::string encrypted = caesar_encrypt(text, shift);

    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Cannot open output file!" << std::endl;
        return 1;
    }

    outputFile << encrypted;
    outputFile.close();

    std::cout << "Encryption complete. Output saved to output.txt" << std::endl;
    return 0;
}