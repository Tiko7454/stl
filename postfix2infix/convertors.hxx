#ifndef CONVERTORS_HXX
#define CONVERTORS_HXX
#include <string>
#include <array>

std::string infix_to_postfix(const std::string& expr);
std::string postfix_to_infix(const std::string& expr);
const std::array<char, 4> operators {'+', '-', '*', '/'}; 

bool is_in(char ch, const std::array<char, 4>& arr);

#endif
