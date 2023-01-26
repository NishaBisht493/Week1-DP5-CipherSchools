#include<bits/stdc++.h>
using namespace std;

void generateParenthesis(string &strSoFar, vector<string> &result, int open, int close){
    //Base Condition
    if(open > close || open < 0 || close < 0){
        //unbalanced
        return;
    }else if(open == 0 && close == 0){
        result.push_back(strSoFar);
        return;
    }else if(open <= close){
        //Next Recursion
        strSoFar.push_back('(');
        generateParenthesis(strSoFar, result, open - 1, close);
        strSoFar.pop_back();
        
        strSoFar.push_back(')');
        generateParenthesis(strSoFar, result, open, close - 1);
        strSoFar.pop_back();
    }
}
vector<string> generate(const int n){
    vector<string> result;
    int open = n, close = n;
    string strSoFar = "";
    generateParenthesis(strSoFar, result, open, close);
}
int main(){

}