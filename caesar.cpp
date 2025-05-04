#include "caesar.h"
#include <omp.h>

const std::wstring alphabet_upper = L"АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
const std::wstring alphabet_lower = L"абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
const int alphabet_len = alphabet_upper.length();

wchar_t caesar_shift(wchar_t ch, int shift) {
    auto upper_pos = alphabet_upper.find(ch);
    if (upper_pos != std::wstring::npos) {
        return alphabet_upper[(upper_pos + shift) % alphabet_len];
    }

    auto lower_pos = alphabet_lower.find(ch);
    if (lower_pos != std::wstring::npos) {
        return alphabet_lower[(lower_pos + shift) % alphabet_len];
    }
    
    return ch;
}

std::wstring caesar_encrypt(const std::wstring& text, int shift) {
    std::wstring result(text.length(), L' ');
    
    #pragma omp parallel for schedule(dynamic, 1000)
    for (size_t i = 0; i < text.length(); i++) {
        result[i] = caesar_shift(text[i], shift);
    }

    return result;
}