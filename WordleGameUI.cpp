#include "WordleGameUI.h"

#ifndef WORDLEGAMEUI_CPP
#define WORDLEGAMEUI_CPP

//Constructor initializes the score from persistent file if exists
WordleGameUI::WordleGameUI() {
    score = 0;
    
    ifstream persistentFile("stat.txt");
    
    if (persistentFile) {
        persistentFile >> score;
        persistentFile.close();
    }
}

//The method increases the score and updates the persistent file
void WordleGameUI::increaseScore() {
    score++;
    
    ofstream persistentFile("stat.txt");
    persistentFile << score;
    persistentFile.close();
}

//Prints the score board
void WordleGameUI::printScoreBoard() {
    cout << endl << endl << "\033[1;32m" << "===========================================" << "\033[0m" << endl;
    cout << "\033[1;32m" << "                 Score : " << score << "\033[0m" << endl;
    cout << "\033[1;32m" << "===========================================" << "\033[0m" << endl << endl << endl;
}

//Prints a layout of keyboard with respect to exact, partial and used word
void WordleGameUI::printKeyBoard(string exactMatch, string partialMatch, string usedWords) {
    
    string line1 = "QWERTYUIOP";
    string line2 = "ASDFGHJKL";
    string line3 = "ZXCVBNM";
    
    cout << endl << "Letters : " << endl;
    
    //Prints first line "QWERTYUIOP"
    cout << "     ";
    for(int i = 0; i < line1.size(); i++)
    {
        if (exactMatch.find(line1[i]) != std::string::npos)
            cout << "\033[1;32m" << line1[i] << "  " << "\033[0m";
        else if (partialMatch.find(line1[i]) != std::string::npos)
            cout << "\033[1;31m" << line1[i] << "  " << "\033[0m";
        else if (usedWords.find(line1[i]) != std::string::npos)
            cout << "\033[1;34m" << line1[i] << "  " << "\033[0m";
        else 
            cout << "\033[0;37m" << line1[i] << "\033[0m" << "  " ;
    }
    cout << endl;
    
    //Prints first line "ASDFGHJKL"
    cout << "       ";
    for(int i = 0; i < line2.size(); i++)
    {
        if (exactMatch.find(line2[i]) != std::string::npos)
            cout << "\033[1;32m" << line2[i] << "  " << "\033[0m";
        else if (partialMatch.find(line2[i]) != std::string::npos)
            cout << "\033[1;31m" << line2[i] << "  " << "\033[0m";
        else if (usedWords.find(line2[i]) != std::string::npos)
            cout << "\033[1;34m" << line2[i] << "  " << "\033[0m";
        else 
            cout << "\033[0;37m" << line2[i] << "\033[0m" << "  " ;
    }
    cout << endl;
    
    //Prints first line "ZXCVBNM"
    cout << "         ";
    for(int i = 0; i < line3.size(); i++)
    {
        if (exactMatch.find(line3[i]) != std::string::npos)
            cout << "\033[1;32m" << line3[i] << "  " << "\033[0m";
        else if (partialMatch.find(line3[i]) != std::string::npos)
            cout << "\033[1;31m" << line3[i] << "  " << "\033[0m";
        else if (usedWords.find(line3[i]) != std::string::npos)
            cout << "\033[1;34m" << line3[i] << "  " << "\033[0m";
        else 
            cout << "\033[0;37m" << line3[i] << "\033[0m" << "  " ;
    }
    cout << endl;
    
    //Print legends
    cout << "\033[1;32m" << "\t\t\t\tGreen - Exact Match" << "\033[0m" << endl;
    cout << "\033[1;31m" << "\t\t\t\tRed   - Partial Match" << "\033[0m" << endl;
    cout << "\033[0;34m" << "\t\t\t\tBlue  - No Match" << "\033[0m" << endl;
    cout << "\033[0;37m" << "\t\t\t\tWhite - Unused" << "\033[0m" << endl;
    
    cout << endl << endl << endl;
}

#endif