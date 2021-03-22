#include "dictionary.hpp"

//  Utilizes the read_file function to create the dictionary. More concise but
//  does not have a method of telling you if the loading was successful
//  without using the successes map.
Dictionary::Dictionary(const std::string &filename) { read_file(filename); }

//  Reads a file containing words for each line. Split each word into
//  separate letters and crate a Markov Chain around all letters found
//  through the entire dictionary. THe final map should containt all words
//  where each letter may go to any other letter to define a word. If a
//  letter can not go to another specific letter then no word exists
//  containing those letters adjacently.
//  The success of this operation will be tracked by the boolean return type,
//  but also by the successes map inside the class.
bool Dictionary::read_file(const std::string &filename)
{
    //  Open a file stream to read from file.
    std::ifstream file(filename);

    //  Return false if file does not exist.
    if(!file.is_open())
    {
        return false;
    }

    //  If file good, start reading word by word.
    std::string current_word;

    while(file >> current_word)
    {
        word_data.add_word(current_word);
    }

    return true;
}

//  Check the successes map for the filename given, if it exists return the
//  Approprate boolean value it contains, if not return nullopt.
constexpr bool Dictionary::read_good(const std::string &filename)
{
    //  TODO
    //
    //
    return false;
}

//  Check all successes in the map, if all are true than return nullopt,
//  Other wise return the first found issue.
std::optional<std::pair<std::string, bool>> Dictionary::read_good() const
{
    //  TODO
    //
    //
    return std::nullopt;
}

//  Check if a word exists in the dictionary. Follow the Markov Chain. If
//  the chain ends, but there are more letters, the word does not exists. If
//  the word ends and the Chain has no ending symbol ("^") in the given
//  vector for that letter, the word does not exist.
bool Dictionary::check_word(const std::string &word) const
{
    // TODO
    //
    //
    return true;
}

//  Used to suggest words based on a misspelled word.
//  Check to see if the word is misspelled, if so
//  continue with finding suggestions, otherwise return
//  nullopt
std::optional<std::vector<std::string>>
    Dictionary::get_suggestions(const std::string &misspelled_word)
{
    //  TODO
    //
    //
    return std::nullopt;
}

//  Get a random word given some starting letter(s) from the user.
//  If there are not starting letters then all words are fair game.
//  If there are, follow the Markov Chain for those letters that
//  begin randomization. If letters make up the only word that exists
//  with those letters than that word is returned. If letters don't match
//  any word in the dictionary than nullopt is returned.
std::optional<std::string> Dictionary::random_word(const std::string &hint = "")
{
    //  TODO
    //
    //
    return std::nullopt;
}
