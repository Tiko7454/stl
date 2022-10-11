#include "convertor.hxx"


bool is_in(char ch, const std::array<char, 4>& arr) {
    for (char el : arr) { 
        if (ch == el) {
            return true;
        }
    }   
    return false;
}

