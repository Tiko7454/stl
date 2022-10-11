#ifndef SENTENCE_WORD_COUNTER_HXX
#define SENTENCE_WORD_COUNTER_HXX
#include <unordered_map>
#include <string>

using StringCountMap = std::unordered_map<std::string, std::size_t>;

class SentenceWordCounter {
private:
    StringCountMap _words;
public:
    SentenceWordCounter() = default;
    void process_sentence(const std::string& sentence);

    StringCountMap get_words() {
        return _words;
    }

private:
    void _push_word(const std::string& word) {
        _words[word]++;
    }
};


#endif
