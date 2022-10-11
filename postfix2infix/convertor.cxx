#include <algorithm>
#include "convertor.hxx"

const std::array<char, 4> Convertor::_OPERATORS{'*', '+', '-', '/'};

bool Convertor::is_operator(char ch) {
    return std::binary_search(_OPERATORS.begin(), _OPERATORS.end(), ch);
}

bool Convertor::is_operator(const std::string& ch) {
    if (ch.size() != 1) {
        return false;
    }
    return is_operator(ch[0]);
}

