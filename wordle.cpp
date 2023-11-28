// Feature List:
// * Integrated Wordle-solver
// Front end
// Color code output
// Keyboard with Colors
// 
// Back end
// *** Use <set> rather than <vector> to store the wordlist
// *** Use find for valid word check in a vector
// Implement with at least 2 classes
// Implement multiple games with stats
// Implement persistent stats
// Use <string> find and npos rather than iterating over a string

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include "WordleSolver.h"
#include "WordleGameUI.h"

using namespace std;

int main()
{
    //Initializing required variables
    int MAX_TURNS = 6;
    string input, choice;
    bool found;
    
    while(1) {
        
        found = false;
        
        WordleGameUI *ui = new WordleGameUI();
        WordleSolver * wordleSolver = new WordleSolver();
        //Reading the word list from file
        wordleSolver->readWordList();
        
        wordleSolver->pickRandomGuessWord();
        
        //Test code
        //cout << "guessWord : " << wordleSolver->getGuessWord() << endl;
        
        //Loop through each turn
        for(int turn = 1; turn <= MAX_TURNS; turn++)
        {
            cout << endl << "Turn " << turn << endl;
            
            ui->printKeyBoard(wordleSolver->getExactMatch(), wordleSolver->getPartialMatch(), wordleSolver->getUsedWords());
            
            while(1) {
                cout << "Input a word: " << endl;
                cin >> input;   //Get an input word from user
                
                if(!wordleSolver->compareWord(input))  //Compare the words
                    cout << "Not a word in the list. Try again" << endl;
                else 
                    break;
            }
            
            //If the guess word is same as input word, then break the loop
            if(input.compare(wordleSolver->getGuessWord()) == 0)
            {
                found = true;
                break;
            }
        }
        
        //Print the status according to win state
        if(found)
        {
            cout << "winner" << endl;
            ui->increaseScore();
        }
        else {
            cout << "loser" << endl;
            cout << "The word was " << wordleSolver->getGuessWord() << endl;
        }
        
        ui->printScoreBoard();
        
        //Prompt user if he wants to continue again
        cout << "Do you want to continue playing ? (yes/no) :";
        cin >> choice;
        
        //If he chooses "no", then exit
        if(choice.compare("no") == 0) break;
    }
    
    return 0;
}