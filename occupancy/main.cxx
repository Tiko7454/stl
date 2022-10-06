#include <iostream>
#include <unordered_map>
#include <cctype>


enum exit_codes {
    SUCCESS,
    INVALID_ARGUMENT
};

using StringCountMap = std::unordered_map<std::string, std::size_t>;


void help(const std::string program_name) {
    std::cout << "write the sentence as a command line argument:\n"
              << program_name << " 'sentence'" << std::endl;
}


inline char lower(char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

inline bool is_regular_symbol(char ch) {
    return std::isalpha(ch) or std::isdigit(ch);
}

class SentenceWordCounter {
private:
    StringCountMap _words;
public:
    SentenceWordCounter() = default;
    void process_sentence(const std::string& sentence) {
        _words.clear();
        std::string word{};
        for (char ch : sentence) {
            if (not is_regular_symbol(ch)) {
                push_word(word);
                word = "";
            } else {
                word += lower(ch);
            }
        }
        if (word != "") {
            push_word(word);
        }
    }

    void push_word(const std::string& word) {
        if (word == "") {
            return;
        }
        _words[word]++;
    }

    auto get_words() -> decltype(_words) {
        return _words;
    }
};

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

