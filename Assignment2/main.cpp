/*
Data structures 3460:316
Assignment 2
Jaret Varn, jav76@zips.uakron.edu

This program takes two words given by the user and tries to recursively
find a word ladder between them such that each word 'step' of the ladder
has one character difference from the last step. 

*/
#include "Header.h"
using namespace dataStructures;

int main()
{
    map<string, int> dictionary;
    cout << "Importing dictionary file...";
    importDictionary(dictionary);
    cout << "\nDone\n";
    bool ladderFound = false;
    map<string, int>::iterator startWord;
    map<string, int> subDict;
    string endWord;

    while (true)
    {
        startWord = getStartWord(dictionary);
        if (startWord->first == "exit" || startWord->first == "quit") // Allow the option to exit program
        {
            return 0;
        }
        subDict = getSubDict(dictionary, startWord->first);
        endWord = getEndWord(subDict);
        cout << "Searcing for word ladder...\n";
        vector<string> ladder;

        bool result = getWordLadderb(endWord, startWord->first, ladder, subDict);
        if (result)
        {
            cout << "Ladder found" << std::endl;
        }
        else
        {
            cout << "No ladder found" << std::endl;
        }
    }
    return 0;
}