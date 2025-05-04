#ifndef CAESAR_H
#define CAESAR_H

#include <string>

char caesar_shift(char ch, int shift);
std::string caesar_encrypt(const std::string& text, int shift);

#endif