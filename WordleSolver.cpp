#include "WordleSolver.h"

#ifndef WORDLESOLVER_CPP
#define WORDLESOLVER_CPP

WordleSolver::WordleSolver() {
    exactMatch = "";
    partialMatch = "";
}

//A method reads the word list from the words list file
void WordleSolver::readWordList()
{
    string line;
    ifstream wordFile("words.txt");
    
    //Read each line and push that to a set of words
    while (getline(wordFile, line)) { 
        words.insert(line);
        possibleWords.push_back(line);
    }
    
    wordFile.close();
}

//A method picks the guess word randomly
void WordleSolver::pickRandomGuessWord() {
    
    int index = rand() % words.size();
    
    auto it = words.begin();
    for(int i = 0; i < index; i++) it++;
    
    guessWord = *it;
}

//Returns the guess word
string WordleSolver::getGuessWord() {
    return guessWord;
}

//Returns the word list
set<string> WordleSolver::getWordList() {
    return words;
}

//A method used to compare input word with guess word
bool WordleSolver::compareWord(string word1)
{
    //If both sizes are not matching, then simply return false
    if(word1.size() != guessWord.size()) return false;
    
    bool found = false;
    for (auto& word : words)
    {
        if(word.compare(word1) == 0)
        {
            found = true;
            break;
        }
    }
    
    if(!found) return false;
    
    string output = "     ";
    string guessWord(this->guessWord);
    
    //Loop each characters of input word
    for(int i = 0; i < word1.size(); i++)
    {
        if(word1[i] == guessWord[i])    //Exact match
        {
            guessWord[i] = '#';
            output[i] = '^';
        }
    }
    
    for(int i = 0; i < word1.size(); i++) {
        
        if(output[i] != '^')
        {
            if(guessWord.find(word1[i]) != string::npos)   //Partial match
                output[i] = '?';
            else    // No match
                output[i] = 'X';
        }
    }
    
    //Prints the output in color coded format
    for(int i = 0; i < output.size(); i++)
    {
        if (output[i] == '^')
            cout << "\033[1;32m" << output[i] << "\033[0m";
        else if (output[i] == '?')
            cout << "\033[1;31m" << output[i] << "\033[0m";
        else 
            cout << "\033[0;37m" << output[i] << "\033[0m";
    }
    
    //Updating the possible word list
    updatePossibleWords(word1, output);
    
    cout << endl;
    
    //Prints legends for the color coding
    cout << "\033[1;32m" << "\t\t\t\t( ^ ) Green  - Exact Match" << "\033[0m" << endl;
    cout << "\033[1;31m" << "\t\t\t\t( ? ) Red    - Partial Match" << "\033[0m" << endl;
    cout << "\033[0;37m" << "\t\t\t\t( X ) White  - No Match" << "\033[0m" << endl;
    
    cout << endl << endl;
    
    return true;
}

//Return the exact match characters
string WordleSolver::getExactMatch() {
    return exactMatch;
}

//Return the partial match characters
string WordleSolver::getPartialMatch() {
    return partialMatch;
}

//Return the used characters
string WordleSolver::getUsedWords() {
    return usedWords;
}

//Update the exact match characters list
void WordleSolver::updateExactMatch(char ch) {
    if(exactMatch.find(ch) == string::npos)
    {
        exactMatch = exactMatch + (char)(ch - 'a' + 'A');    
    }
}

//Update the partial match characters list
void WordleSolver::updatePartialMatch(char ch) {
    if(partialMatch.find(ch) == string::npos)
    {
        partialMatch = partialMatch + (char)(ch - 'a' + 'A');  
    }
}

//Update the used characters list
void WordleSolver::updateUsedWords(char ch) {
    if(usedWords.find(ch) == string::npos)
    {
        usedWords = usedWords + (char)(ch - 'a' + 'A');  
    }
}

//Update the possible word list based on the word and its output
void WordleSolver::updatePossibleWords(string word, string output) {
    
    //Loop through each output word and update the exact, partial and used word list
    for(int i = 0; i < output.size(); i++)
    {
        if(output[i] == '^') {
            updateExactMatch(word[i]);
        } else if(output[i] == '?') {
            updatePartialMatch(word[i]);
        } else if(output[i] == 'X') {
            updateUsedWords(word[i]);
        }
    }
    
    //Creating a temporary list to hold possible word list
    vector<string> possibleWordsClone;
    //Push all possible words into cloned list
    for(int i = 0; i < possibleWords.size(); i++)
        possibleWordsClone.push_back(possibleWords[i]);
    
    //Clear the possible word list
    possibleWords.clear();
    
    //Loop through the cloned list
    for (vector<string>::iterator it = possibleWordsClone.begin(); it != possibleWordsClone.end(); ++it)  
    {
        int totalExactMatch = 0, actualExactMatch = 0;
        int totalPartialMatch = 0, actualPartialMatch = 0;
        
        //Iterate through each output 
        for(int i = 0; i < output.size(); i++)
        {
            if(output[i] == '^') {
                totalExactMatch++;  
                //If it is exact match letter and the position of current word is also as expected, 
                //then increment both the counters
                if((*it).find(word[i]) == i) 
                    actualExactMatch++;
            }
            else if(output[i] == '?') {
                totalPartialMatch++;
                //If it is partial match letter and the letter is atleast found in the current word,
                //then increment both the counters
                if((*it).find(word[i]) != string::npos) 
                    actualPartialMatch++;
            }
        }
        
        //If both expected count of exact match and actual exact match count are equal, 
        //then push that word into possible word list
        if(totalExactMatch == actualExactMatch && totalExactMatch != 0)
            possibleWords.push_back(*it);
        
        //If both expected count of partial match and actual partial match count are equal, 
        //then push that word into possible word list
        if(totalPartialMatch == actualPartialMatch && totalPartialMatch != 0)
            possibleWords.push_back(*it);
    }
    
}

#endif