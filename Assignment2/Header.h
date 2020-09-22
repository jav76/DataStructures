#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <utility>



namespace dataStructures
{
	using std::vector;
	using std::ifstream;
	using std::string;
	using std::cout;
	using std::cin;
	using std::map;
	using std::pair;

	void importDictionary(map<string, int>& dictionary);
	map<string, int>::iterator getStartWord(map<string, int>& dictionary);
	string getEndWord(map<string, int>& dictionary);
	map<string, int> getSubDict(map<string, int>& dictionary, string startWord);
}