#include <iostream>
#include <cstdlib>
#include <array>
#include "exitcodes.hxx"
#include "convertors.hxx"


void help(const std::string program_name) {
    std::cout << "write an expretion as a command line argument:\n"
              << program_name << " 'expression'" << std::endl;
}


int main(int argc, char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return INVALID_ARGUMENT;
    }
    std::string expr = argv[1];
    std::string res{};
    if (is_in(expr[expr.size() - 1], operators)) {  // is postfix
        res = postfix_to_infix(expr);
    } else {  // is infix
        res = infix_to_postfix(expr);
    }
    std::cout << res << std::endl;
    return SUCCESS;
}
