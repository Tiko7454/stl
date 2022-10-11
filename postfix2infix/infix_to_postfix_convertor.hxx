#ifndef INFIX_TO_POSTFIX_CONVERTOR_HXX
#define INFIX_TO_POSTFIX_CONVERTOR_HXX
#include "convertor.hxx"
#include <stack>


class InfixToPostfixConvertor : public Convertor {
private:
    std::stack<std::string> _operands;
    std::stack<std::string> _operators;
public:
    InfixToPostfixConvertor(const std::string& expr)
        : Convertor(expr) {}

    std::string convert() override;
private:
    void _parse();

    void _write_operand(std::string& token);

    void _write_sub_expr(std::string& sub_expr);

    static int _add_paren(char ch);

    static std::string _to_string(std::stack<std::string>& stack);

    std::string _build();
};


#endif
