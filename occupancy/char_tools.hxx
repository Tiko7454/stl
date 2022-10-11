#ifndef CHAR_TOOLS_HXX
#define CHAR_TOOLS_HXX
#include <string>

inline char lower(char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

inline bool is_regular_symbol(char ch) {
    return std::isalpha(ch) or std::isdigit(ch);
}

#endif
