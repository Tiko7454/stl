#include <stack> 
#include <iostream> 
#include <cctype>
#include <stdexcept>
#include "convertors.hxx"

static std::stack<std::string> parse(const std::string& expr) {
    std::stack<std::string> tokens{};
    std::string token{}; 
    for (char ch : expr) {
        if (ch == ' ') {
            tokens.push(token);
            token = "";
        } else {
            token += ch;
        }
    } 
    if (token != "") {
        tokens.push(token);
    }
    return tokens;
}

static bool is_operator(std::string ch) {
    return ch.size() == 1 and is_in(ch[0], operators);
}

static std::string build_infix(std::stack<std::string>& tokens) {
    if (tokens.size() < 3) {
        throw std::invalid_argument{"expression is wrong"};
    }
    std::string op = tokens.top();
    tokens.pop();
    std::string arg1 = tokens.top();
    if (is_operator(arg1)) {
        arg1 = build_infix(tokens);
    } else {
        tokens.pop();
    }
    std::string arg2 = tokens.top();
    if (is_operator(arg2)) {
        arg2 = build_infix(tokens);
    } else {
        tokens.pop();
    }
    return "(" + arg1 + " " + op + " " + arg2 + ")";
    
}

std::string postfix_to_infix(const std::string& expr) {
    std::stack<std::string> tokens = parse(expr);
    return build_infix(tokens);
} 

