#include <iostream>
#include "sentence_word_counter.hxx"


enum exit_codes {
    SUCCESS,
    INVALID_ARGUMENT
};



void help(const std::string program_name) {
    std::cout << "write the sentence as a command line argument:\n"
              << program_name << " 'sentence'" << std::endl;
}



int main(int argc, char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return INVALID_ARGUMENT;
    }

    std::string sentence = argv[1];

    SentenceWordCounter sentence_word_counter{};
    sentence_word_counter.process_sentence(sentence);

    StringCountMap words = sentence_word_counter.get_words();

    for (auto& el : words) {
        std::cout << el.first << " " << el.second << std::endl;
    }
    return SUCCESS;
}

