#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

#ifndef WORDLESOLVER_H
#define WORDLESOLVER_H

//Class helps loading list of words, picking random word, and compare guess word with actual word.
class WordleSolver {
    set<string> words;
    vector<string> possibleWords;
    string guessWord;
    
    string exactMatch, partialMatch, usedWords;
    
public:
    
    WordleSolver();
    
    void readWordList();
    
    void pickRandomGuessWord();
    
    string getGuessWord();
    
    set<string> getWordList();
    
    bool compareWord(string word1);
    
    string getExactMatch();
    
    string getPartialMatch();
    
    string getUsedWords();
    
    void updateExactMatch(char ch);
    
    void updatePartialMatch(char ch);
    
    void updateUsedWords(char ch);
    
    void updatePossibleWords(string word, string output);
};

#endif