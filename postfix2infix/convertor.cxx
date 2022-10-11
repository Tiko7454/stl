#include "convertor.hxx"

const std::array<char, 4> Convertor::_OPERATORS{'+', '-', '*', '/'};

bool Convertor::is_operator(char ch) {
    for (char el : _OPERATORS) {
        if (ch == el) {
            return true;
        }
    }   
    return false;
}

bool Convertor::is_operator(std::string ch) {
    if (ch.size() != 1) {
        return false;
    }
    return is_operator(ch[0]);
}

