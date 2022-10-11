#include <iostream>
#include "exit_codes.hxx"
#include "convertor.hxx"
#include "postfix_to_infix_convertor.hxx"
#include "infix_to_postfix_convertor.hxx"


void help(const std::string& program_name) {
    std::cout << "write an expression as a command line argument:\n"
              << program_name << " 'expression'" << std::endl;
}


int main(int argc, char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return INVALID_ARGUMENT;
    }
    std::string expr = argv[1];
    std::string res{};
    Convertor* convertor;
    if (Convertor::is_operator(expr[expr.size() - 1])) {  // is postfix
        convertor = new PostfixToInfixConvertor{expr};
    } else {  // is infix
        convertor = new InfixToPostfixConvertor{expr};
    }
    try {
        res = convertor->convert();
    } catch (const std::invalid_argument& e) {
        delete convertor;
        std::cout << e.what() << std::endl;
        return INVALID_ARGUMENT;
    }
    delete convertor;
    std::cout << res << std::endl;
    return SUCCESS;
}