#include "sentence_word_counter.hxx"
#include "char_tools.hxx"

void SentenceWordCounter::process_sentence(const std::string& sentence) {
    _words.clear();
    std::string word{};
    for (char ch : sentence) {
        if (not is_regular_symbol(ch)) {
            _push_word(word);
            word = "";
        } else {
            word += lower(ch);
        }
    }
    if (not word.empty()) {
        _push_word(word);
    }
}
