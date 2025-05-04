#include <string>
#include <omp.h>

const std::string alphabet_upper = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
const std::string alphabet_lower = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
const int alphabet_len = alphabet_upper.length();

char caesar_shift(char ch, int shift) {
    auto upper_pos = alphabet_upper.find(ch);
    if (upper_pos != std::string::npos) {
        return alphabet_upper[(upper_pos + shift) % alphabet_len];
    }

    auto lower_pos = alphabet_lower.find(ch);
    if (lower_pos != std::string::npos) {
        return alphabet_lower[(lower_pos + shift) % alphabet_len];
    }
    
    return ch;
}

std::string caesar_encrypt(const std::string& text, int shift) {
    std::string result;
    result.reserve(text.length());
    
    #pragma omp parallel
    {
        std::string local_result;
        local_result.reserve(text.length() / omp_get_num_threads() + 1);
        
        #pragma omp for schedule(dynamic, 1000) nowait
        for (size_t i = 0; i < text.length(); i++) {
            local_result += caesar_shift(text[i], shift);
        }
        
        #pragma omp critical
        result += local_result;
    }
    
    return result;
}