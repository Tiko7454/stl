#include <iostream>
#include <unordered_map>
#include <cctype>


enum exit_codes {
    SUCCESS,
    INVALID_ARGUMENT
};


void help(const std::string program_name) {
    std::cout << "write the sentence as a command line argument:\n"
              << program_name << " 'sentence'" << std::endl;
}


void push_to_map(
    const std::string& key,
    std::unordered_map<std::string, unsigned long long>& map
) {
    if (key == "") {
        return;
    }
    if (map.count(key) == 0) {
        map[key] = 1;
    } else {
        map[key]++;
    }
}

inline char lower(char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

int main(int argc, char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return INVALID_ARGUMENT;
    }
    std::string sentence = argv[1];
    std::unordered_map<std::string, unsigned long long> words{};
    std::string key{};
    
    for (char ch : sentence) {
        if (not (std::isalpha(ch) or std::isdigit(ch))) {
            push_to_map(key, words);
            key = "";
        } else {
            key += lower(ch);
        }
    }
    push_to_map(key, words);

    for (auto& el : words) {
        std::cout << el.first << " " << el.second << std::endl;
    }
    return SUCCESS;
}

