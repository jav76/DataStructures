/*
Data structures 3460:316
Assignment 2
Jaret Varn, jav76@zips.uakron.edu

This program takes two words given by the user and tries to recursively
find a word ladder between them such that each word 'step' of the ladder
has one character difference from the last step. 

*/



#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Header.h"


using namespace dataStructures;

int main()
{
    map<string, int> dictionary;
    cout << "Importing dictionary file...";
    importDictionary(dictionary);
    cout << "\nDone\n";
    bool ladderFound = false;

    map<string, int>::iterator startWord = getStartWord(dictionary);
    map<string, int> subDict = getSubDict(dictionary, startWord->first);
    string endWord = getEndWord(subDict);
    cout << "Searcing for word ladder...\n";
    vector<string> ladder;
    vector<string> result = getWordLadder(startWord->first, endWord, ladder, subDict, ladderFound);
    for (vector<string>::iterator i = result.begin(); i != result.end(); ++i)
    {
        cout << *i << std::endl;
    }
}