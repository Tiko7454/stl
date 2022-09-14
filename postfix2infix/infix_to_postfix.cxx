#include <cstddef>
#include <stack>
#include <iostream>
#include "convertors.hxx"


std::string infix_to_postfix(const std::string& expr) {
    std::stack<std::string> operands{};
    std::stack<std::string> operations{};
    std::string token{};
    std::string subexpr{};
    std::size_t parantheses{};
    for (char ch : expr) {
	if (parantheses == 0) {
	    if (ch == ' ') {
		if (token != "") {
	            operands.push(token);
	            token = "";
		}
	    } else if (is_in(ch, operators)) {
	        operations.push({ch});
	    } else if (ch == '(') {
                parantheses++;
	    } else {
                token += ch;
            }
	} else { 
	    if (ch == '(') {
	        parantheses++;
	    } else if (ch == ')') {
		parantheses--;
	    }
	    if (parantheses == 0) {
                operands.push(infix_to_postfix(subexpr));
		continue;
	    }
	    subexpr += ch;
	}
    }
    if (token != "") {
        operands.push(token);
        token = "";
    }
    std::string result{};
    while (not operands.empty()) {
        result += operands.top() + " ";
	operands.pop();
    }
    while (not operations.empty()) {
        result += operations.top() + " ";
	operations.pop();
    }
    result.pop_back();  // this is garanteed to be a space
    return result;
}
