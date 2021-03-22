#ifndef DICTIONARY_H
#define DICTIONARY_H

// #include <exception>
#include "letter_bank.hpp"
#include <map>
#include <optional>
#include <utility>
#include <vector>
#include <fstream>

class Dictionary
{
  private:
    LetterBank word_data;
    std::map<std::string, bool> successes;

  public:
    Dictionary() {}
    Dictionary(const std::string &filename);
    ~Dictionary() {}

    bool read_file(const std::string &filename);

    constexpr bool read_good(const std::string &filename);
    std::optional<std::pair<std::string, bool>> read_good() const;

    bool check_word(const std::string &word) const;

    //  Used to clear the dictionary if a new one must be built.
    constexpr inline void clear()
    {
        // word_data.clear();
        successes.clear();
    }

    std::optional<std::vector<std::string>>
        get_suggestions(const std::string &misspelled_word);

    std::optional<std::string> random_word(const std::string &hint);
};

#endif
