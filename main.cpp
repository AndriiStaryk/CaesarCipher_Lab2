#include <iostream>
#include <fstream>
#include <omp.h>
#include "caesar.h"

int main(int argc, char* argv[]) {

    int num_threads = 4;
    if (argc > 1) {
        num_threads = std::stoi(argv[1]);
    }
    omp_set_num_threads(num_threads);
    
    std::cout << "Using " << num_threads << " threads" << std::endl;

    std::ifstream input_file("harry_potter.txt");
    if (!input_file) {
        std::cerr << "Cannot open input file!" << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(input_file)),
                      std::istreambuf_iterator<char>());
    input_file.close();

    int shift = 33;
    
    double start_time = omp_get_wtime();
    
    std::string encrypted = caesar_encrypt(text, shift);
    
    double end_time = omp_get_wtime();
    double duration = end_time - start_time;
    
    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Cannot open output file!" << std::endl;
        return 1;
    }

    outputFile << encrypted;
    outputFile.close();

    std::cout << "Encryption complete in " << duration << " seconds" << std::endl;
    std::cout << "Output saved to output.txt" << std::endl;
    return 0;
}