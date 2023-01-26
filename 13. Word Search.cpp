#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>>& board, vector<vector<bool>>& visited, string &word, int index, int x, int y, const int &R, const int &C){
    //x, y within the grid
    //not visited
    //char word[index]

    return ((x >= 0 && x < R && y >= 0 && y < C) && !visited[x][y] && board[x][y] == word[index]);
}

bool isPresent(vector<vector<char>>& board, vector<vector<bool>>& visited, string &word, int index, int x, int y, const int &R, const int &C){
    if(index >= word.size()){
        return true;
    }
    else{
        int xMoves[] = {0, 0, 1, -1};
        int yMoves[] = {1, -1, 0, 0};
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nextX = x + xMoves[i];
            int nextY = y + yMoves[i];
            if(isSafe(board, visited, word, index, nextX, nextY, R, C)){
                if(isPresent(board, visited, word, index + 1, nextX, nextY, R, C)){
                    return true;
                }
            }
        }
        //backtracking
        visited[x][y] = false;
        return false;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    if(word == ""){
        return true;
    }
    int R = board.size(); // rows
    if(R == 0){
        return false;
    }
    int C = board[0].size(); // columns

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(board[i][j] == word[0] && isPresent(board, visited, word, 1, i, j, R, C)){
                return true;
            }
        }
    }
    return false;
}

int main(){

}
