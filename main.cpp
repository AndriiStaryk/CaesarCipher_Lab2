#include <iostream>
#include <fstream>
#include <vector>
#include <codecvt>
#include <locale>
#include <omp.h>
#include "caesar.h"

int main(int argc, char* argv[]) {

    int num_threads = 4;
    int shift = 11;

    if (argc > 1) {
        num_threads = std::stoi(argv[1]);
    }

    if (argc > 2) {
        shift = std::stoi(argv[2]);
    }

    omp_set_num_threads(num_threads);

    std::cout << "Using " << num_threads << " threads" << std::endl;
    std::cout << "Using Caesar shift of " << shift << std::endl;

    // Open file with UTF-8 encoding
    std::wifstream input_file("harry_potter.txt");
    if (!input_file) {
        std::cerr << "Cannot open input file!" << std::endl;
        return 1;
    }
    
    // Set UTF-8 locale for input
    input_file.imbue(std::locale(input_file.getloc(), 
                    new std::codecvt_utf8<wchar_t>));

    // Read the file into a wide string
    std::wstring text((std::istreambuf_iterator<wchar_t>(input_file)),
                       std::istreambuf_iterator<wchar_t>());
    input_file.close();
    
    double start_time = omp_get_wtime();
    
    std::wstring encrypted = caesar_encrypt(text, shift);
    
    double end_time = omp_get_wtime();
    double duration = end_time - start_time;
    
    // Write to output with UTF-8 encoding
    std::wofstream output_file("output.txt");
    if (!output_file) {
        std::cerr << "Cannot open output file!" << std::endl;
        return 1;
    }
    
    // Set UTF-8 locale for output
    output_file.imbue(std::locale(output_file.getloc(),
                     new std::codecvt_utf8<wchar_t>));
    
    output_file << encrypted;
    output_file.close();

    std::cout << "Encryption complete in " << duration << " seconds" << std::endl;
    std::cout << "Output saved to output.txt" << std::endl;
    return 0;
}