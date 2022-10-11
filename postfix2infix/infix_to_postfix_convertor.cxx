#include "infix_to_postfix_convertor.hxx"
#include <stdexcept>


std::string InfixToPostfixConvertor::convert() {
    _parse();
    return _build();
}


void InfixToPostfixConvertor::_parse() {
    std::string operand{};
    std::string sub_expr{};
    std::size_t parentheses{};
    for (char ch : _expr) {
        if (ch == ' ') {
            continue;
        }
        if (parentheses != 0) {
            parentheses += _add_paren(ch);
            if (parentheses == 0) {
                _write_sub_expr(sub_expr);
                continue;
            }
            sub_expr += ch;
            continue;
        }

        if (not is_special_symbol(ch)) {
            operand += ch;
            continue;
        }

        // is_special_symbol(ch)
        // We must separate operand because ch is delimiter
        if (not operand.empty()) {
            _write_operand(operand);
        }

        if (ch == '(') {
            parentheses++;
        } else if (ch == ')') {
            throw std::invalid_argument{"expression is wrong"};
        } else {  // is_operator(ch)
            _operators.push({ch});
        }
    }
    if (not operand.empty()) {
        _write_operand(operand);
    }
}

void InfixToPostfixConvertor::_write_operand(std::string &token) {
    _operands.push(token);
    token.clear();
}

void InfixToPostfixConvertor::_write_sub_expr(std::string &sub_expr) {
    InfixToPostfixConvertor convertor{sub_expr};
    _operands.push(convertor.convert());
    sub_expr.clear();
}

int InfixToPostfixConvertor::_add_paren(char ch) {
    if (ch == '(') {
        return 1;
    }
    if (ch == ')') {
        return -1;
    }
    return 0;
}

std::string InfixToPostfixConvertor::_to_string(std::stack<std::string> &stack) {
    std::string result{};
    while (not stack.empty()) {
        result += stack.top() + " ";
        stack.pop();
    }
    if (not result.empty()) {
        result.pop_back();  // this is guaranteed to be a space
    }
    return result;
}

std::string InfixToPostfixConvertor::_build() {
    std::string result{};
    result += _to_string(_operands);
    if (not _operators.empty()) {
        result += ' ';
        result += _to_string(_operators);
    }
    return result;
}