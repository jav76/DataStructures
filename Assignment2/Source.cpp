#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <utility>
#include "Header.h"

namespace dataStructures
{
    void importDictionary(map<string, int> &dictionary)
    {
        ifstream file;
        file.open("Dictionary.txt", std::ios::in);
        if (file.is_open())
        {
            pair<string, int> word;
            while (file >> word.first)
            {
                word.second = word.first.length();
                dictionary.insert(word);
            }
        }
        else
        {
            cout << "Error reading file" << std::endl;
        }
    }

    map<string, int>::iterator getStartWord(map<string, int> &dictionary)
    {
        string startWord;
        cout << "\nEnter the starting word:";
        cin >> startWord;
        map<string, int>::iterator found = dictionary.find(startWord);
        while (cin.fail() || found == dictionary.end())
        {
            cout << "\nInvalid word. Enter a new starting word:";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> startWord;
            found = dictionary.find(startWord);
        }
        return found;
    }

    string getEndWord(map<string, int> &dictionary)
    {
        string endWord;
        cout << "\nEnter the ending word:";
        cin >> endWord;
        map<string, int>::iterator found = dictionary.find(endWord);
        while (cin.fail() || found == dictionary.end())
        {
            cout << "\nInvalud word. Enter a new ending word:";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> endWord;
            found = dictionary.find(endWord);
        }
        return endWord;
    }

    map<string, int> getSubDict(map<string, int>& dictionary, string startWord)
    {
        map<string, int> subDict;
        for (map<string, int>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
        {
            if (it->second == startWord.length())
            {
                pair<string, int> word = { it->first, it->second };
                subDict.insert(word);
            }
        }
        return subDict;
    }
}
