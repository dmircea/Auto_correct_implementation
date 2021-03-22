#ifndef LETTER_BANK_H
#define LETTER_BANK_H

#include <vector>
#include <memory>
#include <unordered_map>
#include <iostream> // DEBUG ONLY

const char START = '$';
const char ENDING = '%';

struct Letter
{
    char letter;
    std::shared_ptr<Letter> parent;
    std::unordered_map<char, std::shared_ptr<Letter>> children;
};

class LetterBank
{
private:
    // std::shared_ptr<Letter> head;
    std::shared_ptr<Letter> head;

public:
    LetterBank();

    bool add_word(const std::string & word);

    bool word_exists(const std::string & word) const;
};

#endif
