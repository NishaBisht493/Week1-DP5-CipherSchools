#include<bits/stdc++.h>
using namespace std;

vector<string> dialPad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void letterCombinations(string &input, string &strSoFar, vector<string> &result, int start, int end){
    //Base Condition
    if(start > end){
        result.push_back(strSoFar);
        return;
    }else{
        //Next Recursion
        char digitPressed = input[start];
        string possibleMoves = dialPad[digitPressed - '0'];

        for(int i = 0; i < possibleMoves.size(); i++){
            strSoFar.push_back(possibleMoves[i]);
            letterCombinations(input, strSoFar, result,start + 1, end);
            //Backtracking
            strSoFar.pop_back();
        }
    }
}

vector<string> combinations(string digits) {
    vector<string> result;
    if(digits.size() == 0){
        return result;
    }
    int start = 0, end = digits.size() - 1;
    string strSoFar = "";
    letterCombinations(digits, strSoFar, result, start, end);
        
    return result;
}

int main(){

}