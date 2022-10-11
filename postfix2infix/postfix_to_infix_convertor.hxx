#ifndef POSTFIX_TO_INFIX_CONVERTOR_HXX
#define POSTFIX_TO_INFIX_CONVERTOR_HXX
#include <stdexcept>
#include "convertor.hxx"
#include <stack>

class PostfixToInfixConvertor : public Convertor {
private:
    std::stack<std::string> _tokens;
public:
    PostfixToInfixConvertor(const std::string& expr)
        : Convertor{expr} {}

    std::string convert() final;
private:
    void _parse();

    std::string _build_infix();

    std::string _read_arg();

    void _clear_tokens() {
        _tokens = {};
    }

    std::string _gen_expr(
            const std::string& arg1,
            const std::string& arg2,
            const std::string& op
    ) const {
        return "(" + arg1 + " " + op +
               " " + arg2 + ")";
    }
};

#endif
