/*  Jacob Kurbis (Z1945650)
	CSCI 340: Data Structures Section: 0003
	Assignment 7	Due: 03/20/2023
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>


//Global constants
const int NO_ITEMS = 4;//The number of items to print per line
const int ITEM_WORD_WIDTH = 14;//The width of the word item
const int ITEM_COUNT_WIDTH = 3;//The width of the count item


/**
 * @brief: Cleans the word by removing all non-alphanumeric characters
 *
 * @param orig_word: A reference to the original word
 * @param clean_word: A reference to the cleaned word
 * 
 */
void clean_entry(const std::string &orig_word, std::string &clean_word)
{
    //Find the first alphanumeric character
    auto alpha = find_if(orig_word.begin(), orig_word.end(), [](char c) { return isalnum(c); });

    //Find the first non-alphanumeric character
    auto non_alpha = find_if(alpha, orig_word.end(), [](char c) { return !isalnum(c); });

    //If the word is empty return
    if(alpha == orig_word.end())
    {
        clean_word = "";
        return;
    }

    //Store the cleaned up word into the clean_word variable
    clean_word = std::string(alpha, non_alpha);

    //Convert the word to lowercase
    for_each(clean_word.begin(), clean_word.end(), [](char &c) { c = tolower(c); });
}


/**
 * @brief: Gets the words from the input stream and stores them in the map
 *
 * @param M: The map to store the words in
 * 
 */
void get_words(std::map<std::string, int> &M)
{
    //Strings to store the words in
    std::string word, clean_word;

    //Get the words from the input stream
    while(std::cin >> word)
    {
        //Clean the word
        clean_entry(word, clean_word);

        //If the word is not empty add it to the map
        if(clean_word.length() > 0)
        {
            M[clean_word]++;//Increment the count of the word
        }
    }
}


/**
 * @brief: Prints the words in the map
 *
 * @param M: The map to print
 *
 */
void print_words(const std::map<std::string, int> &M)
{
    int non_empty_words = 0; //The number of nonempty words
    int cnt = 0;//Count for the number of words printed

    //Get the number of nonempty words
    for(const auto &pair : M)
    {
        non_empty_words += pair.second;
    }

    //Print the words in the map
    for (const auto &pair : M)
    {
        std::cout << std::setw(ITEM_WORD_WIDTH) << std::left << pair.first << ":" << std::setw(ITEM_COUNT_WIDTH) << pair.second;

        cnt++;

        //Print a new line if the line is full
        if(cnt % NO_ITEMS == 0)
        {
            std::cout << std::endl;
        }
    }

    //Print a new line if the last line is not full
    if(cnt % NO_ITEMS != 0)
    {
        std::cout << std::endl;
    }

    //Print the number of words in the input and output streams
    std::cout << "number of words in input stream   :" << non_empty_words << std::endl;
    std::cout << "number of words in output stream  :" << M.size() << std::endl;

}


int main()
{
    std::map<std::string, int> M;//The map to store the words in
    get_words(M);//Get the words from the input stream
    print_words(M);//Print the words in the map
    return 0;
}