#include "postfix_to_infix_convertor.hxx"


std::string PostfixToInfixConvertor::convert() {
    _parse();
    return _build_infix();
}

void PostfixToInfixConvertor::_parse() {
    _clear_tokens();
    std::string token{};
    for (char ch : _expr) {
        if (ch == ' ') {
            _tokens.push(token);
            token = "";
        } else {
            token += ch;
        }
    }
    if (not token.empty()) {
        _tokens.push(token);
    }
}

std::string PostfixToInfixConvertor::_build_infix() {
    if (_tokens.size() < 3) {
        throw std::invalid_argument{"expression is wrong"};
    }
    std::string op = _tokens.top();
    _tokens.pop();

    std::string arg1 = _read_arg();
    std::string arg2 = _read_arg();

    return _gen_expr(arg1, arg2, op);
}

std::string PostfixToInfixConvertor::_read_arg() {
    std::string arg = _tokens.top();
    if (_is_operator(arg)) {
        arg = _build_infix();
    } else {
        _tokens.pop();
    }
    return arg;
}