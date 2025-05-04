#ifndef CAESAR_H
#define CAESAR_H

#include <string>

char caesar_shift(char ch, int shift);
std::wstring caesar_encrypt(const std::wstring& text, int shift);

#endif