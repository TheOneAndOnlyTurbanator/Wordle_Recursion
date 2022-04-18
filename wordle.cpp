// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void wordle_helper(const std::set<std::string>& dict , std::string floating, size_t index, std::set<std::string>& set_correct, std::string temp_word);
 

// Definition of primary wordle function
std::set<std::string> wordle(const std::string& in, const std::string& floating, const std::set<std::string>& dict)
{
    // Add your code here
    std::set<std::string> wordle_answers; 

    wordle_helper(dict, floating, 0, wordle_answers, in);

    // wordle_helper(dict, floating, 0, wordle_awnsers, in);

    // return wordle_awnsers;
    return wordle_answers;

}

// Define any helper functions here
void wordle_helper(const std::set<std::string>& dict , std::string floating, size_t index, std::set<std::string>& set_correct, std::string temp_word){

    // base case - no dashes left // if real word you insert
    if(index == temp_word.size() && floating.empty()){ 
        if(dict.find(temp_word) != dict.end()){
            set_correct.insert(temp_word);
        }
        return; 
    }
    int numDashes = 0;
    // string adjusted_word; 
    // if word[index] != '-', recurse on next one
    if(temp_word[index] != '-'){
        wordle_helper(dict, floating, index+1, set_correct, temp_word);
        return;
    }
    for(size_t i = 0; i < temp_word.size(); i++){
        if(temp_word[i] == '-'){
            numDashes++;
        }
    }
    string temp2 = floating; 
    if(numDashes > (int)temp2.size()){
        for(char c = 'a'; c<= 'z'; c++){
            if(temp2.find(c)!=string::npos){
                temp_word[index] = c;
                string temp3 = temp2;
                temp3.erase(temp2.find(c), 1);
                wordle_helper(dict, temp3, index + 1, set_correct, temp_word);
            }
            else{
                temp_word[index] = c;
                wordle_helper(dict, temp2, index+1, set_correct, temp_word);
            }
        }
    }
    else if(numDashes == (int)temp2.size()){
        for(size_t i = 0; i < temp2.size(); i++){
            temp_word[index] = temp2[i];
            string temp3 = temp2;
            temp3.erase(i, 1);
            wordle_helper(dict, temp3, index + 1, set_correct, temp_word);
        }
    } 
}




        
    