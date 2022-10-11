#ifndef CONVERTOR_HXX
#define CONVERTOR_HXX
#include <string>
#include <array>

class Convertor {
public:
    virtual std::string convert() = 0;
protected:
    const std::string _expr;
    static const std::array<char, 4> _OPERATORS;
    Convertor(const std::string& expr)
        : _expr{expr} {}
public:
    static bool is_operator(char ch);
    static bool is_operator(std::string ch);
    static bool is_special_symbol(char ch) {
        return ch == '(' or ch == ')' or is_operator(ch);
    }
    virtual ~Convertor() = default;
};

#endif
