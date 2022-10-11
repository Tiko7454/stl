#ifndef CONVERTORS_HXX
#define CONVERTORS_HXX
#include <string>
#include <array>
#include "postfix_to_infix_convertor.hxx"

std::string infix_to_postfix(const std::string& expr);
const std::array<char, 4> OPERATORS {'+', '-', '*', '/'};

bool is_in(char ch, const std::array<char, 4>& arr);

#endif
