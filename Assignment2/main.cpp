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

    while (true)
    {
        map<string, int>::iterator startWord = getStartWord(dictionary);
        string endWord = getEndWord(dictionary);
        map<string, int> subDict = getSubDict(dictionary, startWord->first);
        
        for (auto it = subDict.begin(); it != subDict.end(); ++it)
        {
            cout << it->first << std::endl;
        }
    }
}



