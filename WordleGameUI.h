#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

#ifndef WORDLEGAMEUI_H
#define WORDLEGAMEUI_H

//The class helps front end for printing QWERTY and also holds the stats of player
class WordleGameUI {
    
    int score, turn;
    
public:

    WordleGameUI();
    
    void increaseScore();
    
    void printScoreBoard();
    
    void printKeyBoard(string exactMatch, string partialMatch, string usedWords);
};

#endif