#include "dictionary.hpp"
#include "letter_bank.hpp"
#include <exception>
#include <fstream>
#include <gtest/gtest.h>
/*
    The words.txt data for this program was taken from:
    https://github.com/dwyl/english-words.git

    Thank you for the data you have provided and to the people who made
    this data originally!
*/

//  TODO Finish the three hundred word file by typing out all the words

const std::string ALL_FILE_NAMES[] = {
    "empty_file.txt",
    "one_word_file.txt",
    "five_words_file.txt",
    "similar_words_file",
    "identical_words_file.txt",
    "heterogenous_words_file.txt",
    "three_hundred_words_file.txt",
    "words_test.txt", //  This one should exist in the same folder
    "words.txt"       //  This one should exist in the same folder
};

//  Test set for the letter bank
class LetterBankTest : public ::testing::Test
{
protected:

public:
    LetterBankTest()
    {
        // std::cout << "Creating LetterBankTest object.\n";
    }
};

TEST_F(LetterBankTest, CanCreateLetterBank)
{
    // std::cout << "Creating letter bank.\n";
    LetterBank word_bank;
}

TEST_F(LetterBankTest, CanAddWordToLetterBank)
{
    LetterBank word_bank;
    word_bank.add_word("hello");
}

TEST_F(LetterBankTest, CanAddManyDifferentWords)
{
    LetterBank word_bank;
    word_bank.add_word("hello");
    word_bank.add_word("apple");
    word_bank.add_word("banana");
    word_bank.add_word("orange");
}

TEST_F(LetterBankTest, CanAddManySimimlarWords)
{
    LetterBank word_bank;
    word_bank.add_word("apple");
    word_bank.add_word("app");

    LetterBank other_bank;
    other_bank.add_word("app");
    other_bank.add_word("apple");
}

TEST_F(LetterBankTest, CanFindWordsInBank)
{
    LetterBank word_bank;
    word_bank.add_word("hello");
    word_bank.word_exists("hello");
}
//  Test set for the dictionary class
class DictionaryTest : public ::testing::Test
{
    //  Setting up testing equipment
  protected:
    const std::string PATH = "test_files/";

  public:
    DictionaryTest()
    {
        // std::cout << "Creating DictionaryTest object.";
        std::ofstream empty_file(PATH + ALL_FILE_NAMES[0]);
        std::ofstream one_word_file(PATH + ALL_FILE_NAMES[1]);
        std::ofstream five_words_file(PATH + ALL_FILE_NAMES[2]);
        std::ofstream similar_words_file(PATH + ALL_FILE_NAMES[3]);
        std::ofstream identical_words_file(PATH + ALL_FILE_NAMES[4]);
        std::ofstream heterogenous_words_file(PATH + ALL_FILE_NAMES[5]);
        //  TODO use each file in order to fill in something in accordance to
        //  what it is meant to do.
        empty_file << "";
        one_word_file << "hello";
        five_words_file << "hello\nhi\napple\nbanana\nfive";
        similar_words_file << "app\napple\napples\napplication\napricot";
        identical_words_file << "app\napp\napp\napple";
        heterogenous_words_file << "apple\nbanana\ncoffee\nphilosophy\nmath";

        empty_file.close();
        one_word_file.close();
        five_words_file.close();
        similar_words_file.close();
        identical_words_file.close();
        heterogenous_words_file.close();
    }
};

TEST_F(DictionaryTest, CanCreateObjectWithFile)
{
    Dictionary dict("one_word_file.txt");
}

TEST_F(DictionaryTest, CanReadInFileSuccessfully)
{
    Dictionary dict;
    bool success = dict.read_file("one_word_file.txt");
    ASSERT_TRUE(success);
}

TEST_F(DictionaryTest, CanCheckIfWordExists)
{
    Dictionary dict("one_word_file.txt");
    bool exists = dict.check_word("hello");
    ASSERT_TRUE(exists);
    exists = dict.check_word("hi");
    ASSERT_FALSE(exists);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
