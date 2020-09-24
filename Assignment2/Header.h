#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

namespace dataStructures
{
	using std::vector;
	using std::ifstream;
	using std::string;
	using std::cout;
	using std::cin;
	using std::map;
	using std::pair;
	using std::multimap;

	//pre: Takes a map<string, int> variable as an argument
	//post: Loads the map with keys being every word in Dictionary.txt with values as the length of each word
	void importDictionary(map<string, int>& dictionary);

	//pre: Takes a map<string, int> full of dictionary words
	//post: Prompts the user for a word, and if the word is a valid word in the dictionary returns an iterator to that word in the dictionary
	map<string, int>::iterator getStartWord(map<string, int>& dictionary);
	
	//pre: Takes a map<string, int> full of dictionary words
	//post: Prompts the user for a word, and if the word is a valid word in the dictionary returns a string of that word
	string getEndWord(map<string, int>& dictionary);

	//pre: Takes a map<string, int> dictionary full of words and a string word contained by that dictionary
	//post: Iterates through the dictionary and creates a secondary map<string, int> dictionary containing only words of the same length as string startWord and returns that dictionary
	map<string, int> getSubDict(map<string, int>& dictionary, string startWord);

	//pre: Takes two string words
	//post: If words are the same length, returns an integer number of the different characters between the two words, otherwise returns -1
	int getHammingDistance(string string1, string string2);

	//pre: Takes word and endWord strings that are valid dictionary words of the same length, and a map<string, int> dictionary of words of the same length of word and endWord
	//post: Creates a map<int, string> of words that have 1 character difference from the string word argument, and sorts them by least distance from the endWord string and returns that map
	multimap<int, string> getStepOptions(string word, string endWord, map<string, int>& subDict);

	//pre: Takes a string current word, endWord, vector<string> ladder, map<string, int> dictionary with words of same length as word and endWord, and a boolean ladderFound
	//post: Pushes the string current word onto the ladder vector, and if that word is the endWord, a word ladder solution has been found
	//		and can be returned. Otherwise, for recursively calls itself with every word valid word choice given by getStepOptions that has not been tried yet.
	vector<string> getWordLadder(string current, string endWord, vector<string> ladder, map<string, int>& subDict, bool& ladderFound);
}