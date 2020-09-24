
#include "Header.h"

namespace dataStructures
{
    void importDictionary(map<string, int>& dictionary)
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

    map<string, int>::iterator getStartWord(map<string, int>& dictionary)
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

    string getEndWord(map<string, int>& dictionary)
    {
        string endWord;
        cout << "\nEnter the ending word:";
        cin >> endWord;
        map<string, int>::iterator found = dictionary.find(endWord);
        while (cin.fail() || found == dictionary.end())
        {
            cout << "\nInvalid word. Enter a new ending word:";
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

    int getHammingDistance(string string1, string string2)
    {
        if (string1.length() != string2.length())
        {
            return -1;
        }
        int distance = 0;
        for (pair<string::iterator, string::iterator> it = { string1.begin(), string2.begin() }; it.first != string1.end(); ++it.first, ++it.second)
        {
            if (*it.first != *it.second)
            {
                ++distance; // Increase distance for each character that doesn't match between words
            }
        }
        return distance;
    }

    multimap<int, string> getStepOptions(string word, string endWord, map<string, int>& subDict)
    {
        multimap<int, string> options;
        int endDistance = 0;
        for (map<string, int>::iterator i = subDict.begin(); i != subDict.end(); ++i)
        {
            if (getHammingDistance(word, i->first) == 1) // Find words with 1 distance from given 'word'
            {
                endDistance = getHammingDistance(i->first, endWord);
                options.insert({ endDistance, i->first }); 
                // Insert into map such that words are sorted by shortest distance to endword to try and target finding the endword faster
            }
        }
        /*
        for (auto i = options.begin(); i != options.end(); ++i)
        {
            cout << "distance: " << i->first << " option: " << i->second << std::endl;
        }
        */
        return options;
    }
    
    vector<string> getWordLadder(string current, string endWord, vector<string> ladder, map<string, int>& subDict, bool &ladderFound)
    {
        ladder.push_back(current);
        if (current == endWord)
        {
            cout << "Found ladder" << std::endl;
            ladderFound = true;
            return ladder;
        }
        multimap<int, string> options = getStepOptions(current, endWord, subDict);
        if (options.size() > 1)
        {
            for (multimap<int, string>::iterator i = options.begin(); i != options.end(); ++i)
            {
                if (ladderFound == false)
                {
                    bool used = false;
                    for (vector<string>::iterator j = ladder.begin(); j != ladder.end(); ++j)
                    {
                        if (i->second == *j)
                        {
                            used = true;
                            break;
                        }
                    }
                    if (used == false)
                    {
                        //cout << std::endl << current << std::endl;
                        return getWordLadder(i->second, endWord, ladder, subDict, ladderFound);
                    }
                }
            }
        }
    }
}
