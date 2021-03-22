
#include "letter_bank.hpp"

LetterBank::LetterBank()
{
    head.reset(new Letter);
    head->letter = START;
}

bool LetterBank::add_word(const std::string & word)
{
    if(word.length() == 0)
    {
        return false;
    }
    if(word_exists(word) == true)
    {
        return false;
    }

    std::shared_ptr<Letter> link = head;
    std::shared_ptr<Letter> prev = head;

    // Letter * link = head;
    // Letter * prev = head;

    for(int i = 0; i < word.length(); ++i)
    {
        prev = link;
        link = link->children[word[i]];
        if(!link)
        {
            link.reset(new Letter);
            // link = new Letter;
            // std::cout << "Making new letter object on heap!\n";
        }
        link->letter = word[i];
        link->parent = prev;

        prev->children[word[i]] = link;

        // std::cout << "Added letter " << link->letter << std::endl;
    }

    prev = link;
    link = link->children[ENDING];
    if(!link)
    {
        link.reset(new Letter);
        // link = new Letter;
    }
    link->letter = ENDING;
    link->parent = prev;

    return true;
}

bool LetterBank::word_exists(const std::string & word) const
{
    if(word.length() == 0)
    {
        // Empty word
        return true;
    }

    std::shared_ptr<Letter> link = head;
    // Letter* link = head;

    for(int i = 0; i < word.length(); ++i)
    {

        // std::cout << "Iteration " << i << std::endl;
        // std::cout << "\tLetter is " << link->letter << std::endl;
        if(link->children.find(word[i]) == link->children.end())
        {
            //
            // We did NOT find a letter matching the current word letter.
            // This means no word that matches.
            return false;
        }
        link = link->children[word[i]];
    }

    if(link->children.find(ENDING) == link->children.end())
    {
        // We got to the end of the word parameter but there is no ending
        // here in the letter bank
        return false;
    }

    return true;
}
